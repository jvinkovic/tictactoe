#pragma once

#include "Board.h"

class Game
{
	enum GameState { PLAYING, DRAW, X_WON, O_WON };
public:
	Game();
	~Game();

	void start();

private:
	Board board;
	GameState currentGameState;
	Player currentPlayer;

	void initGame();
	Location playerMove();
	void updateGameState(Location loc);
};
