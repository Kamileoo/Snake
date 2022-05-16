#ifndef GAME
#define GAME

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <array>
#include <tuple>
#include "Apple.h"
#include "Snake.h"
#include "Text.h"
#include "Board2.h"

using namespace std;

class Game {
public:
	Game();
	void newGame();
	void createApple();
	bool isOver();
	bool isWin();
	void move(int x, int y);
	pair<int,int> getHead();
	pair<int,int> getForward(int hx, int hy);
	void printTable();
	array<array<int, 16>, 16>& getTab();
	float getBounce();
	void bounce();
	void drawApple(ShaderProgram *sp);
	void drawSnake(ShaderProgram* sp);
	void drawBoard(ShaderProgram* sp);
	void drawOver(ShaderProgram* sp);
	void drawWin(ShaderProgram* sp);

	void loadTex();

	array<array<int, 16>, 16> tab;
private:
	bool isOv = false;
	int snakeL = 0;
	float bounceLevel = 0.0f;
	float bounceUD = 0.01f;
	Apple a;
	Snake s;
	Board b;
	Text over = { "Objects/GO.obj", "Objects/TX.png" };
	Text win = { "Objects/YW.obj", "Objects/TX.png" };
};



#endif /* !GAME */