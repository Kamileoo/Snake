#ifndef OBJREADER
#define OBJREADER

#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <array>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "lodepng.h"

using namespace std;


bool loadOBJ(
	const char* path,
	std::vector < float >& out_vertices,
	std::vector < float >& out_uvs,
	std::vector < float >& out_normals,
	int *vCount
);

GLuint readTexture(const char* filename);


#endif /* !OBJREADER */