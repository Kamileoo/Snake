/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#define GLM_FORCE_RADIANS
#define GLM_FORCE_SWIZZLE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "constants.h"
#include "lodepng.h"
#include "shaderprogram.h"
#include "Game.h"
#include "Board.h"
#include "Snake.h"
#include "Apple.h"

float speed_x=0;
float speed_y=0;
float walk_speed = 0;
float aspectRatio=1;

glm::vec3 pos = glm::vec3(16, 30, -8);

int move_x = 0;
int move_y = 0;
bool newG = false;

ShaderProgram *sp;
ShaderProgram *sp2;


//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}


void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods) {
    if (action==GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) { move_x = 1; move_y = 0; }
        if (key==GLFW_KEY_RIGHT) { move_x = -1; move_y = 0; }
        if (key==GLFW_KEY_UP) { move_x = 0; move_y = 1; }
        if (key==GLFW_KEY_DOWN) { move_x = 0; move_y = -1; }
		if (key == GLFW_KEY_SPACE) { newG = true; }
		if (key == GLFW_KEY_A) speed_y = 1;
		if (key == GLFW_KEY_D) speed_y = -1;
		if (key == GLFW_KEY_Z) speed_x = 1;
		if (key == GLFW_KEY_X) speed_x = -1;
		if (key == GLFW_KEY_W) walk_speed = 6;
		if (key == GLFW_KEY_S) walk_speed = -6;
    }
    if (action==GLFW_RELEASE) {
		if (key == GLFW_KEY_A) speed_y = 0;
		if (key == GLFW_KEY_D) speed_y = 0;
		if (key == GLFW_KEY_Z) speed_x = 0;
		if (key == GLFW_KEY_X) speed_x = 0;
		if (key == GLFW_KEY_W) walk_speed = 0;
		if (key == GLFW_KEY_S) walk_speed = 0;
    }
}

glm::vec3 calcDir(float kat_x, float kat_y) {
	glm::vec4 dir = glm::vec4(0, 0, 1, 0);
	glm::mat4 M = glm::rotate(glm::mat4(1.0f), kat_y, glm::vec3(0, 1, 0));
	M = glm::rotate(M, kat_x, glm::vec3(1, 0, 0));
	dir = M * dir;
	return glm::vec3(dir);
}

void windowResizeCallback(GLFWwindow* window,int width,int height) {
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	//************Tutaj umieszczaj kod, który należy wykonać raz, na początku programu************
	glClearColor(0.3f,0.75f,1.f,1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);

	sp = new ShaderProgram("v_simplest.glsl",NULL,"f_simplest.glsl");
	sp2 = new ShaderProgram("v_new.glsl", NULL, "f_new.glsl");

}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************

    delete sp;
	delete sp2;
}




//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window, float kat_x, float kat_y, Game *g) {
	//************Tutaj umieszczaj kod rysujący obraz******************l
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 V = glm::lookAt(pos, pos + calcDir(kat_x, kat_y), glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz widoku


    glm::mat4 P=glm::perspective(50.0f*PI/180.0f, aspectRatio, 0.01f, 50.0f); //Wylicz macierz rzutowania

    
    sp->use();//Aktywacja programu cieniującego
    //Przeslij parametry programu cieniującego do karty graficznej
    glUniformMatrix4fv(sp->u("P"),1,false,glm::value_ptr(P));
    glUniformMatrix4fv(sp->u("V"),1,false,glm::value_ptr(V));


	sp2->use();//Aktywacja programu cieniującego
	glUniformMatrix4fv(sp2->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp2->u("V"), 1, false, glm::value_ptr(V));

	// Plansza
	g->drawBoard(sp2);


	g->bounce();
	if (g->isOver()) {
		g->drawOver(sp2);
	}
	else if (g->isWin()) {
		g->drawWin(sp2);
	}
	else {
		// Apple
		g->drawApple(sp2);
	}

	// Snake
	g->drawSnake(sp2);
	

    glfwSwapBuffers(window); //Przerzuć tylny bufor na przedni
}


int main(void)
{
	srand(time(NULL));
	Game* g = new Game();
	//g->printTable();

	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące
	g->loadTex();

	//Główna pętla
	float kat_x = 0.95;
	float kat_y = 0;
	float timer = 0;
	glfwSetTime(0); //Zeruj timer
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
		timer += glfwGetTime();
		if (timer > 0.8f) {
			timer = 0;
			g->move(move_x, move_y);
			//g->printTable();
			if (move_x != 0 && move_y != 0) {
				move_x = -1;
				move_y = -1;
			}
		}

		if (g->isOver() || g->isWin()) {
			if (newG) {
				newG = false;
				g->newGame();
			}
		}
		kat_x += speed_x * glfwGetTime();
		kat_y += speed_y * glfwGetTime();
		pos += (float)(walk_speed * glfwGetTime()) * calcDir(kat_x, kat_y);
		glfwSetTime(0); //Zeruj timer
		drawScene(window, kat_x, kat_y, g); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	delete g;

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
