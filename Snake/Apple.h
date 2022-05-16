#ifndef APPLE
#define APPLE

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shaderprogram.h"
#include "OBJReader.h"

using namespace std;

class Apple {
public:
	Apple();

	void drawApple(ShaderProgram *sp, array<array<int, 16>, 16>& tab, float b);

	void loadTex();

private:
	GLuint texApple;

	float* vertices;
	float* normals;
	float* texCoords;
	int vertexCount;
};

#endif /* !APPLE */