#include "Text.h"

Text::Text(const char* nob, const char* ntx) {

	ob = nob;
	tx = ntx;

	std::vector< float > verticess;
	std::vector< float > uvss;
	std::vector< float > normalss;
	bool res = loadOBJ(ob.c_str() , verticess, uvss, normalss, &vertexCount);

	vertices = new float[verticess.size()];
	std::copy(verticess.begin(), verticess.end(), vertices);

	texCoords = new float[uvss.size()];
	std::copy(uvss.begin(), uvss.end(), texCoords);

	normals = new float[normalss.size()];
	std::copy(normalss.begin(), normalss.end(), normals);

}

void Text::loadTex() {
	texText = readTexture(tx.c_str());
	
}

void Text::drawText(ShaderProgram* sp, float b) {
	glm::mat4 M = glm::mat4(1.0f);
	M = glm::translate(M, glm::vec3(float(16), 4.0f + b, float(16)));
	M = glm::rotate(M, PI, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
	glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska¿ tablicê z danymi dla atrybutu vertex
	glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska¿ tablicê z danymi dla atrybutu normal
	glEnableVertexAttribArray(sp->a("texCoord0"));  //W³¹cz przesy³anie danych do atrybutu texCoord0
	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord0

	glUniform1i(sp->u("textureMap0"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texText);

	glDrawArrays(GL_TRIANGLES, 0, vertexCount); //Narysuj obiekt

	glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
	glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy³¹cz przesy³anie danych do atrybutu texCoord0
}

