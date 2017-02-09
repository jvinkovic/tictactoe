// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "stdlib.h"

int main()
{
	Game game = Game();

	game.start();

	system("pause");
	return 0;
}