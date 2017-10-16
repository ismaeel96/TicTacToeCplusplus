#pragma once
#include "string"

using namespace std;

class ticTacToe
{
public:
	ticTacToe();
	void play();

private:
	void displayBoard();
	void getXOMove();
	bool isMoveValid(string input);
	void gameStatus();
	void reset();

	char board[3][3];
	char player;
	int turns = 0;
};
