#ifndef BOARD2
#define BOARD2

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

using namespace std;

class Board {
public:
	Board();

	void drawBoard(ShaderProgram* sp, float b);

	void loadTex();

private:
	GLuint texBoard1;
	GLuint texBoard2;
	GLuint texGrass;
	GLuint texHGrass;

	float* vertices;
	float* normals;
	float* texCoords;
	int vertexCount;

	float* HGvertices;
	float* HGnormals;
	float* HGtexCoords;
	int HGvertexCount;
};

#endif /* !BOARD2 */