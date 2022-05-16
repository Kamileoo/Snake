#include <Board.h>


void drawBoard(ShaderProgram* sp) {

	float* Bvertices = Models::CubeInternal::vertices;
	float* Bnormals = Models::CubeInternal::normals;
	float* BtexCoords = Models::CubeInternal::texCoords;
	float* Bcolors1 = Models::CubeInternal::colors1;
	float* Bcolors2 = Models::CubeInternal::colors2;
	int BvertexCount = Models::CubeInternal::vertexCount;

	glm::mat4 MT[16][16];

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			MT[x][y] = glm::mat4(1.0f);;
			MT[x][y] = glm::translate(MT[x][y], glm::vec3(float(x * 2), 0.0f, float(y * 2)));
			glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(MT[x][y]));
			glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
			glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, Bvertices); //Wska¿ tablicê z danymi dla atrybutu vertex
			glEnableVertexAttribArray(sp->a("color"));  //W³¹cz przesy³anie danych do atrybutu color
			if ((x + y) % 2 == 0) {
				glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, Bcolors1); //Wska¿ tablicê z danymi dla atrybutu color
			}
			else {
				glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, Bcolors2); //Wska¿ tablicê z danymi dla atrybutu color
			}
			glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
			glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, Bnormals); //Wska¿ tablicê z danymi dla atrybutu normal
			glDrawArrays(GL_TRIANGLES, 0, BvertexCount); //Narysuj obiekt
			glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
			glDisableVertexAttribArray(sp->a("color"));  //Wy³¹cz przesy³anie danych do atrybutu color
			glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
		}
	}

}