#include "Board.h"
#include <iostream>
#include <algorithm>

Board::Board()
{
}

Board::~Board()
{
}

void Board::init()
{
}

bool Board::isCellValid(Location loc)
{
	if (loc.col >= 0 && loc.row >= 0 && loc.col <= 2 && loc.row <= 2)
	{
		if (cells[loc.row][loc.col].getContent() == EMPTY)
		{
			return true;
		}
	}

	return false;
}

bool Board::isFull()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (cells[i][j].getContent() == EMPTY)
			{
				return false;
			}
		}
	}

	return true;
}

bool Board::updateCell(Mark aMark, Location loc)
{
	if (isCellValid(loc))
	{
		cells[loc.row][loc.col].setContent(aMark);
		return true;
	}

	return false;
}

bool Board::hasWon(Player thePlayer, Location loc)
{
	if (!isCellValid(loc))
	{
		return false;
	}

	Mark mark;
	switch (thePlayer)
	{
	case PLAYER_X:
		mark = X;

		break;
	case PLAYER_O:
		mark = O;
		break;
	}

	bool updated = updateCell(mark, loc);

	if (updated)
	{
		if (fullRow(mark, loc.row))
		{
			return true;
		}

		if (fullCol(mark, loc.col))
		{
			return true;
		}

		if (fullDiagonal(mark, loc))
		{
			return true;
		}
	}

	return false;
}

void Board::paint()
{
	std::cout << "-------------" << std::endl;

	for (int i = 0; i < ROWS; i++)
	{
		std::cout << "|";
		for (int j = 0; j < COLS; j++)
		{
			cells[i][j].paint();
			std::cout << "|";
		}
		std::cout << std::endl;
	}

	std::cout << "-------------" << std::endl;
}

bool Board::fullRow(Mark aMark, int row)
{
	for (int j = 0; j < COLS; j++)
	{
		if (cells[row][j].getContent() != aMark)
		{
			return false;
		}
	}

	return true;
}

bool Board::fullCol(Mark aMark, int col)
{
	for (int i = 0; i < ROWS; i++)
	{
		if (cells[i][col].getContent() != aMark)
		{
			return false;
		}
	}

	return true;
}

bool Board::fullDiagonal(Mark aMark, Location loc)
{
	bool firstDiagonal = true;

	for (int i = 0; i < std::min(ROWS, COLS); i++)
	{
		if (cells[i][i].getContent() != aMark)
		{
			firstDiagonal = false;
			break;
		}
	}

	if (firstDiagonal)
	{
		return true;
	}

	// check second diagonal
	int j;
	for (int i = 0, j = std::min(ROWS, COLS) - 1; i < std::min(ROWS, COLS) && j >= 0; i++, j--)
	{
		if (cells[i][j].getContent() != aMark)
		{
			return false;
		}
	}

	return true;
}