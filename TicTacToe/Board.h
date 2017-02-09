#pragma once

#include "Cell.h"

struct Location
{
	int row;
	int col;
};

enum Player { PLAYER_X, PLAYER_O };

class Board
{
	static const int ROWS = 3;
	static const int COLS = 3;
public:
	Board();
	~Board();

	void init();
	bool isCellValid(Location loc);
	bool isFull();
	bool hasWon(Player thePlayer, Location loc);
	void paint();

private:
	Cell cells[ROWS][COLS];

	bool updateCell(Mark aMark, Location loc);
	bool fullRow(Mark aMark, int row);
	bool fullCol(Mark aMark, int col);
	bool fullDiagonal(Mark aMark, Location loc);
};
