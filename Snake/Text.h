#ifndef TEXT
#define TEXT

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

class Text {
public:
	Text(const char* nob, const char* ntx);

	void drawText(ShaderProgram* sp, float b);

	void loadTex();

private:
	string ob;
	string tx;
	GLuint texText;

	float* vertices;
	float* normals;
	float* texCoords;
	int vertexCount;
};

#endif /* !TEXT */