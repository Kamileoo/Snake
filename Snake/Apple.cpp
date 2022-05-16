#include "Apple.h"

Apple::Apple() {

	std::vector< float > verticess;
	std::vector< float > uvss;
	std::vector< float > normalss;
	bool res = loadOBJ("Objects/Apple.obj", verticess, uvss, normalss, &vertexCount);

	vertices = new float[verticess.size()];
	std::copy(verticess.begin(), verticess.end(), vertices);

	texCoords = new float[uvss.size()];
	std::copy(uvss.begin(), uvss.end(), texCoords);

	normals = new float[normalss.size()];
	std::copy(normalss.begin(), normalss.end(), normals);

}

void Apple::loadTex() {
	texApple = readTexture("Objects/Apple_BaseColor.png");
}

void Apple::drawApple(ShaderProgram* sp, array<array<int, 16>, 16>& tab, float b) {
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			if (tab[x][y] == -1) {
				glm::mat4 M = glm::mat4(1.0f);
				M = glm::translate(M, glm::vec3(float(x * 2), 2.0f + b, float(y * 2)));
				M = glm::scale(M, glm::vec3(2.0f, 2.0f, 2.0f));
				glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
				glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
				glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska¿ tablicê z danymi dla atrybutu vertex
				glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
				glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska¿ tablicê z danymi dla atrybutu normal
				glEnableVertexAttribArray(sp->a("texCoord0"));  //W³¹cz przesy³anie danych do atrybutu texCoord0
				glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord0

				glUniform1i(sp->u("textureMap0"), 0);
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, texApple);

				glDrawArrays(GL_TRIANGLES, 0, vertexCount); //Narysuj obiekt

				glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
				glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
				glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy³¹cz przesy³anie danych do atrybutu texCoord0
			}
		}
	}
}

