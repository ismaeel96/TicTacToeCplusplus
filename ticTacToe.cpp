#include"ticTacToe.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <sstream>  
#include <string> 
#include "getData.h"

using namespace std;

ticTacToe::ticTacToe()
{
	reset();
}

void ticTacToe::play()
{
	displayBoard();
	cout << endl << "Player " << player << " moves first." << endl << endl;
	getXOMove();
}

void ticTacToe::getXOMove()
{
	string input = "first time is an error";
	string temp;

	while (!isMoveValid(input))
	{
		cout << "Player " << player << " make your move by entering a" << endl;
		cout << "row followed by a column (eg. 2b) ==> ";

		getline(cin, temp);
		cout << endl;

		if (isMoveValid(temp))
			input = temp;

		if (isMoveValid(input))
		{
			board[toupper(input[1]) - 'A'][stoi(input, 0) - 1] = player;
			turns++;
			displayBoard();
			gameStatus();

			if (player == 'X')
				player = 'O';
			else
				player = 'X';
		}

	}


}

bool ticTacToe::isMoveValid(string input)
{
	try
	{
		stoi(input, 0);
	}
	catch (...)
	{
		return false;
	}

	int row = stoi(input, 0);
	char col = toupper(input[1]);

	if (row < 1 || row > 3)
		return false;
	if (col < 'A' || row > 'C')
		return false;
	if (board[col - 'A'][row - 1] != ' ')
		return false;
	if (board[col - 'A'][row - 1] == 'X')
		return false;
	if (board[col - 'A'][row - 1] == 'O')
		return false;

	return true;
}

void ticTacToe::gameStatus()
{
	//column row /|-\\*/
	bool winrWinrChknDnr = false;
	char exitOrNot = 'n';

	for (int x = 0; x < 3; x++)
	{
		if (board[x][0] == board[x][1] && board[x][0] == board[x][2] && board[x][0] != ' '/*|| board[x][1]!= ' '|| board[x][2]!=' ')*/)
			winrWinrChknDnr = true;
	}
	for (int y = 0; y < 3; y++)
	{
		if (board[0][y] == board[1][y] && board[0][y] == board[2][y] && board[0][y] != ' ')
			winrWinrChknDnr = true;
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		winrWinrChknDnr = true;
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
		winrWinrChknDnr = true;

	if (winrWinrChknDnr)
	{
		cout << "Player " << player << " wins!" << endl;
		cout << "Enter Y or y to continue; any other character to quit ==> ";
		getData::getChar(exitOrNot);

		if (toupper(exitOrNot) == 'Y')
		{
			reset();
			play();
		}
		if (toupper(exitOrNot) != 'Y')
		{
			exit(0);
		}
	}
	if (winrWinrChknDnr && turns == 9)
	{
		cout << "This game is a draw!" << endl;
		cout << "Enter Y or y to continue; any other character to quit ==> ";
		getData::getChar(exitOrNot);

		if (toupper(exitOrNot) == 'Y')
		{
			reset();
			play();
		}
		if (toupper(exitOrNot) != 'Y')
		{
			exit(0);
		}
	}
}

void ticTacToe::reset()
{
	srand(time(0));

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = ' ';
		}
	}


	if ((rand() % 2) == 1)
		player = 'X';
	else
		player = 'O';
}

void ticTacToe::displayBoard()
{
	cout << "   A     B     C" << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << "      |     |" << endl;
		for (int x = 0; x < 3; x++)
		{
			if (x == 0)
				cout << y + 1;

			cout << "  " << board[x][y];

			if (x < 2)
				cout << "  |";
		}
		cout << endl;

		if (y<2)
			cout << " _____|_____|_____" << endl;
		if (y == 2)
			cout << "      |     |";
	}
	cout << endl;
}

