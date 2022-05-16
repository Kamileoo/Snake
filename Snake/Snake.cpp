#include "Snake.h"

Snake::Snake() {
	bool res = false;
	// Head
	std::vector< float > Hverticess;
	std::vector< float > Huvss;
	std::vector< float > Hnormalss;
	res = loadOBJ("Objects/SnakeHead.obj", Hverticess, Huvss, Hnormalss, &HvertexCount);

	Hvertices = new float[Hverticess.size()];
	std::copy(Hverticess.begin(), Hverticess.end(), Hvertices);

	HtexCoords = new float[Huvss.size()];
	std::copy(Huvss.begin(), Huvss.end(), HtexCoords);

	Hnormals = new float[Hnormalss.size()];
	std::copy(Hnormalss.begin(), Hnormalss.end(), Hnormals);

	//// Body
	std::vector< float > Bverticess;
	std::vector< float > Buvss;
	std::vector< float > Bnormalss;
	res = loadOBJ("Objects/SnakeBody.obj", Bverticess, Buvss, Bnormalss, &BvertexCount);

	Bvertices = new float[Bverticess.size()];
	std::copy(Bverticess.begin(), Bverticess.end(), Bvertices);

	BtexCoords = new float[Buvss.size()];
	std::copy(Buvss.begin(), Buvss.end(), BtexCoords);

	Bnormals = new float[Bnormalss.size()];
	std::copy(Bnormalss.begin(), Bnormalss.end(), Bnormals);

	// Body Rounded
	std::vector< float > BRverticess;
	std::vector< float > BRuvss;
	std::vector< float > BRnormalss;
	res = loadOBJ("Objects/SnakeBodyRounded.obj", BRverticess, BRuvss, BRnormalss, &BRvertexCount);

	BRvertices = new float[BRverticess.size()];
	std::copy(BRverticess.begin(), BRverticess.end(), BRvertices);

	BRtexCoords = new float[BRuvss.size()];
	std::copy(BRuvss.begin(), BRuvss.end(), BRtexCoords);

	BRnormals = new float[BRnormalss.size()];
	std::copy(BRnormalss.begin(), BRnormalss.end(), BRnormals);

	// Tail
	std::vector< float > Tverticess;
	std::vector< float > Tuvss;
	std::vector< float > Tnormalss;
	res = loadOBJ("Objects/SnakeTail.obj", Tverticess, Tuvss, Tnormalss, &TvertexCount);

	Tvertices = new float[Tverticess.size()];
	std::copy(Tverticess.begin(), Tverticess.end(), Tvertices);

	TtexCoords = new float[Tuvss.size()];
	std::copy(Tuvss.begin(), Tuvss.end(), TtexCoords);

	Tnormals = new float[Tnormalss.size()];
	std::copy(Tnormalss.begin(), Tnormalss.end(), Tnormals);

}

void Snake::loadTex() {
	texSnakeHead = readTexture("Objects/Snake.png");
	texSnakeBody = readTexture("Objects/Snake.png");
	texSnakeBodyRound = readTexture("Objects/Snake.png");
	texSnakeTail = readTexture("Objects/Snake.png");
}

void Snake::drawSnake(ShaderProgram* sp, array<array<int, 16>, 16>& tab, int snakeL) {
	float ang = 0.0f;
	float* v;
	float* n;
	float* tx;
	int vc = 0;
	int nx = 0;
	int ny = 0;
	GLuint* texC;
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			ang = 0.0f;
			if (tab[x][y] != 0 && tab[x][y] != -1) {
				v = Tvertices;
				n = Tnormals;
				tx = TtexCoords;
				texC = &texSnakeTail;
				vc = TvertexCount;

				if (tab[x][y] == 1) {
					v = Hvertices;
					n = Hnormals;
					tx = HtexCoords;
					texC = &texSnakeHead;
					vc = HvertexCount;

					if (x - 1 < 0) { nx = 15; }
					else { nx = x - 1; }
					if (tab[nx][y] == 2) {
						ang = 3 * PI / 2;
					}

					nx = (x + 1) % 16;
					if (tab[nx][y] == 2) {
						ang = PI / 2;
					}

					if (y - 1 < 0) { ny = 15; }
					else { ny = y - 1; }
					if (tab[x][ny] == 2) {
						ang = PI;
					}

					nx = (y + 1) % 16;
					if (tab[x][ny] == 2) {
						//ang = 0.0f;
					}
				}
				else if (tab[x][y] > 1 && tab[x][y] < snakeL) {
					if (x - 1 < 0) { nx = 15; }
					else { nx = x - 1; }
					if (tab[nx][y] == tab[x][y] - 1 || tab[nx][y] == tab[x][y] + 1) {
						if (tab[x][(y + 1) % 16] == tab[x][y] - 1 || tab[x][(y + 1) % 16] == tab[x][y] + 1)	{
							v = BRvertices;
							n = BRnormals;
							tx = BRtexCoords;
							texC = &texSnakeBodyRound;
							vc = BRvertexCount;
							ang = 0.0f;
						}
						else if (tab[(x + 1) % 16][y] == tab[x][y] - 1 || tab[(x + 1) % 16][y] == tab[x][y] + 1) {
							v = Bvertices;
							n = Bnormals;
							tx = BtexCoords;
							texC = &texSnakeBody;
							vc = BvertexCount;
							ang = PI/2;
						}
						else  {
							v = BRvertices;
							n = BRnormals;
							tx = BRtexCoords;
							texC = &texSnakeBodyRound;
							vc = BRvertexCount;
							ang = 3*PI/2;
						}

					}
					else if (tab[(x + 1) % 16][y] == tab[x][y] - 1 || tab[(x + 1) % 16][y] == tab[x][y] + 1) {
						if (tab[x][(y + 1) % 16] == tab[x][y] - 1 || tab[x][(y + 1) % 16] == tab[x][y] + 1) {
							v = BRvertices;
							n = BRnormals;
							tx = BRtexCoords;
							texC = &texSnakeBodyRound;
							vc = BRvertexCount;
							ang = PI/2;
						}
						else {
							v = BRvertices;
							n = BRnormals;
							tx = BRtexCoords;
							texC = &texSnakeBodyRound;
							vc = BRvertexCount;
							ang = PI;
						}
					}
					else {
						v = Bvertices;
						n = Bnormals;
						tx = BtexCoords;
						texC = &texSnakeBody;
						vc = BvertexCount;
						ang = 0.0f;
					}
				}
				else  {
					v = Tvertices;
					n = Tnormals;
					tx = TtexCoords;
					texC = &texSnakeTail;
					vc = TvertexCount;

					if (x - 1 < 0) { nx = 15; }
					else { nx = x-1; }
					if (tab[nx][y] == snakeL - 1) {
						ang = 3 * PI / 2;
					}

					nx = (x + 1) % 16;
					if (tab[nx][y] == snakeL - 1) {
						ang = PI / 2;
					}

					if (y - 1 < 0) { ny = 15; }
					else { ny = y-1; }
					if (tab[x][ny] == snakeL - 1) {
						ang = PI;
					}

					nx = (y + 1) % 16;
					if (tab[x][ny] == snakeL - 1) {
						//ang = 0.0f;
					}

				}
				glm::mat4 M = glm::mat4(1.0f);
				M = glm::translate(M, glm::vec3(float(x * 2), 1.35f, float(y * 2)));
				M = glm::rotate(M, ang, glm::vec3(0.0f, 1.0f, 0.0f));
				glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
				glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
				glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, v); //Wska¿ tablicê z danymi dla atrybutu vertex
				glEnableVertexAttribArray(sp->a("normal"));  //W³¹cz przesy³anie danych do atrybutu normal
				glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, n); //Wska¿ tablicê z danymi dla atrybutu normal
				glEnableVertexAttribArray(sp->a("texCoord0"));  //W³¹cz przesy³anie danych do atrybutu texCoord0
				glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, tx); //Wska¿ tablicê z danymi dla atrybutu texCoord0

				glUniform1i(sp->u("textureMap0"), 0);
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, *texC);

				glDrawArrays(GL_TRIANGLES, 0, vc); //Narysuj obiekt

				glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
				glDisableVertexAttribArray(sp->a("normal"));  //Wy³¹cz przesy³anie danych do atrybutu normal
				glDisableVertexAttribArray(sp->a("texCoord0"));  //Wy³¹cz przesy³anie danych do atrybutu texCoord0
			}
		}
	}
}