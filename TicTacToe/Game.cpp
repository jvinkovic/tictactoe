#include "Game.h"
#include <iostream>
#include <string>

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
	initGame();

	std::cout << "Welcome!" << std::endl;

	board.paint();
	while (currentGameState == PLAYING)
	{
		Location loc = playerMove();
		updateGameState(loc);
		board.paint();
	}

	std::string result;
	switch (currentGameState)
	{
	case Game::DRAW:
		result = "It's a draw!";
		break;
	case Game::X_WON:
		result = "Player X WON!";
		break;
	case Game::O_WON:
		result = "Player O WON!";
		break;
	}

	std::cout << result << std::endl;
}

void Game::initGame()
{
	board = Board();
	board.init();

	currentPlayer = PLAYER_X;
	currentGameState = PLAYING;
}

Location Game::playerMove()
{
	std::string player;
	switch (currentPlayer)
	{
	case PLAYER_X:
		player = "Player X";
		break;
	case PLAYER_O:
		player = "Player O";
		break;
	}

	int r;
	int c;
	Location loc;
	bool valid = false;
	do {
		std::cout << player + ", make a move. Row? ";
		std::cin >> r;
		while (std::cin.fail()) {
			std::cout << "Input a number! Row? ";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> r;
		}

		std::cout << "Column? ";
		std::cin >> c;
		while (std::cin.fail()) {
			std::cout << "Input a number! Column?";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> c;
		}

		loc.row = r - 1;
		loc.col = c - 1;

		valid = board.isCellValid(loc);

		if (!valid)
		{
			std::cout << "Invalid move!" << std::endl;
		}
	} while (!valid);

	return loc;
}

void Game::updateGameState(Location loc)
{
	if (board.hasWon(currentPlayer, loc))
	{
		switch (currentPlayer)
		{
		case PLAYER_X:
			currentGameState = X_WON;
			break;
		case PLAYER_O:
			currentGameState = O_WON;
			break;
		}

		return;
	}

	if (board.isFull())
	{
		currentGameState = DRAW;
	}

	if (currentPlayer == PLAYER_X)
	{
		currentPlayer = PLAYER_O;
	}
	else
	{
		currentPlayer = PLAYER_X;
	}
}