#include "Game.h"

Game::Game() {
	newGame();
}

void Game::createApple() {
	int x, y;
	do {
		x = rand() % 15 + 0;
		y = rand() % 15 + 0;
	} while (tab[x][y] != 0);
	tab[x][y] = -1;
}

void Game::newGame() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			tab[i][j] = 0;
		}
	}
	tab[7][7] = 1;
	tab[6][7] = 2;
	tab[5][7] = 3;

	snakeL = 3;

	createApple();

	isOv = 0;
}

bool Game::isOver() {
	return isOv;
}

bool Game::isWin() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (tab[i][j] == 0 || tab[i][j] == -1) {
				return false;
			}
		}
	}
	return true;
}

pair<int, int> Game::getHead() {

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (tab[i][j] == 1) {
				return { i, j };
			}
		}
	}
}

pair<int, int> Game::getForward(int hx, int hy) {
	int nx, ny;

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			nx = (hx + i) % 16;
			ny = (hy + j) % 16;
			if (nx == -1) { nx = 15; }
			if (ny == -1) { ny = 15; }

			if (tab[nx][ny] == 2) {
				return { i, j };
			}
		}
	}
}

void Game::move(int x, int y) {
	if (isOver() || isWin()) {
		return;
	}

	if (x == 0 && y == 0) {
		return;
	}

	

	int isApple = 0;

	auto [hx, hy] = getHead();

	if (x == -1 && y == -1) {
		auto [tx, ty] = getForward(hx, hy);
		x = tx;
		y = ty;
	}

	int nx = (hx + x) % 16;
	int ny = (hy + y) % 16;
	if (nx == -1) { nx = 15; }
	if (ny == -1) { ny = 15; }

	if (tab[nx][ny] == 2) {
		x *= -1;
		y *= -1;
		nx = (hx + x) % 16;
		ny = (hy + y) % 16;
		if (nx == -1) { nx = 15; }
		if (ny == -1) { ny = 15; }
	}


	int nv = tab[nx][ny];

	if (nv > 1 && nv < snakeL) {
		isOv = true;
		return;
	}

	if (nv == -1) {
		isApple = 1;
		snakeL++;
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (tab[i][j] > 0) {
				tab[i][j]++;
				if (tab[i][j] > snakeL) {
					tab[i][j] = 0;
				}
			}
		}
	}

	tab[nx][ny] = 1;

	if (isApple) {
		createApple();
	}
}

void Game::bounce() {
	if (bounceLevel + bounceUD > 0.6f || bounceLevel + bounceUD < 0) {
		bounceUD *= -1;
	}

	bounceLevel += bounceUD;
}

array<array<int, 16>, 16>& Game::getTab() {
	return tab;
}

void Game::printTable() {
	for (int y = 15; y >= 0; y--) {
		for (int x = 0; x < 16; x++) {
			printf("%i", tab[x][y]);
;		}
		printf("\n");
	}
	printf("\n");
}

float Game::getBounce() {
	return bounceLevel;
}

void Game::drawApple(ShaderProgram* sp) {
	a.drawApple(sp, getTab(), getBounce());
}

void Game::drawSnake(ShaderProgram* sp) {
	s.drawSnake(sp, getTab(), snakeL);
}

void Game::drawBoard(ShaderProgram* sp) {
	b.drawBoard(sp, getBounce());
}

void Game::drawOver(ShaderProgram* sp) {
	over.drawText(sp, getBounce());
}

void Game::drawWin(ShaderProgram* sp) {
	win.drawText(sp, getBounce());
}

void Game::loadTex() {
	a.loadTex();
	s.loadTex();
	over.loadTex();
	win.loadTex();
	b.loadTex();
}
