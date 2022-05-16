#ifndef SNAKE
#define SNAKE

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shaderprogram.h"
#include "OBJReader.h"
#include "constants.h"
#include "cube.h"

using namespace std;

class Snake {
public:
	Snake();

	void drawSnake(ShaderProgram* sp, array<array<int, 16>, 16>& tab, int snakeL);

	void loadTex();

private:
	GLuint texSnakeHead;
	GLuint texSnakeBody;
	GLuint texSnakeBodyRound;
	GLuint texSnakeTail;

	float* Hvertices;
	float* Hnormals;
	float* HtexCoords;
	int HvertexCount;

	float* Bvertices;
	float* Bnormals;
	float* BtexCoords;
	int BvertexCount;

	float* BRvertices;
	float* BRnormals;
	float* BRtexCoords;
	int BRvertexCount;

	float* Tvertices;
	float* Tnormals;
	float* TtexCoords;
	int TvertexCount;
};

#endif /* !SNAKE */