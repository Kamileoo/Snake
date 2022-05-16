#include "Board2.h"

Board::Board() {
	bool res = false;
	std::vector< float > verticess;
	std::vector< float > uvss;
	std::vector< float > normalss;
	res = loadOBJ("Objects/Brick.obj", verticess, uvss, normalss, &vertexCount);

	vertices = new float[verticess.size()];
	std::copy(verticess.begin(), verticess.end(), vertices);

	texCoords = new float[uvss.size()];
	std::copy(uvss.begin(), uvss.end(), texCoords);

	normals = new float[normalss.size()];
	std::copy(normalss.begin(), normalss.end(), normals);

	// Grass

	res = false;
	std::vector< float > HGverticess;
	std::vector< float > HGuvss;
	std::vector< float > HGnormalss;
	res = loadOBJ("Objects/Grass.obj", HGverticess, HGuvss, HGnormalss, &HGvertexCount);

	HGvertices = new float[HGverticess.size()];
	std::copy(HGverticess.begin(), HGverticess.end(), HGvertices);

	HGtexCoords = new float[HGuvss.size()];
	std::copy(HGuvss.begin(), HGuvss.end(), HGtexCoords);

	HGnormals = new float[HGnormalss.size()];
	std::copy(HGnormalss.begin(), HGnormalss.end(), HGnormals);


}

void Board::loadTex() {
	texBoard1 = readTexture("Objects/B1.png");
	texBoard2 = readTexture("Objects/B2.png");
	texGrass = readTexture("Objects/Grass.png");
	texHGrass = readTexture("Objects/HGrass.png");
}

void Board::drawBoard(ShaderProgram* sp, float b) {
	GLuint* texC;
	glm::mat4 MT[16][16];

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			if ((x + y) % 2 == 0) {
				texC = &texBoard1;
			}
			else {
				texC = &texBoard2;
			}

			MT[x][y] = glm::mat4(1.0f);;
			MT[x][y] = glm::translate(MT[x][y], glm::vec3(float(x * 2), 0.5f, float(y * 2)));
			glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(MT[x][y]));
			glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
			glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska¿ tablicê z danymi dla atrybutu vertex
			glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
			glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska¿ tablicê z danymi dla atrybutu normal
			glEnableVertexAttribArray(sp->a("texCoord0"));  //W³¹cz przesy³anie danych do atrybutu texCoord0
			glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord0

			glUniform1i(sp->u("textureMap0"), 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, *texC);

			glDrawArrays(GL_TRIANGLES, 0, vertexCount); //Narysuj obiekt

			glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
			glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
			glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy³¹cz przesy³anie danych do atrybutu texCoord0
		}
	}

	for (int x = -2; x < 18; x++) {
		for (int y = -2; y < 18; y++) {

			glm::mat4 M = glm::mat4(1.0f);;
			M = glm::translate(M, glm::vec3(float(x * 2), 0.0f, float(y * 2)));
			glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
			glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
			glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska¿ tablicê z danymi dla atrybutu vertex
			glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
			glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska¿ tablicê z danymi dla atrybutu normal
			glEnableVertexAttribArray(sp->a("texCoord0"));  //W³¹cz przesy³anie danych do atrybutu texCoord0
			glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord0

			glUniform1i(sp->u("textureMap0"), 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texGrass);

			glDrawArrays(GL_TRIANGLES, 0, vertexCount); //Narysuj obiekt

			glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
			glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
			glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy³¹cz przesy³anie danych do atrybutu texCoord0
		}
	}

	glm::mat4 M = glm::mat4(1.0f);;
	M = glm::translate(M, glm::vec3(33, -0.2f, 33));
	M = glm::rotate(M, -0.5f + b / 4, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::scale(M, glm::vec3(1.5f, 1.5f, 1.5f));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
	glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, HGvertices); //Wska¿ tablicê z danymi dla atrybutu vertex
	glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, HGnormals); //Wska¿ tablicê z danymi dla atrybutu normal
	glEnableVertexAttribArray(sp->a("texCoord0"));  //W³¹cz przesy³anie danych do atrybutu texCoord0
	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, HGtexCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord0

	glUniform1i(sp->u("textureMap0"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texHGrass);

	glDrawArrays(GL_TRIANGLES, 0, HGvertexCount); //Narysuj obiekt

	glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
	glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy³¹cz przesy³anie danych do atrybutu texCoord0

}
