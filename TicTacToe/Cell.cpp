#include "Cell.h"
#include <iostream>
#include <string>

Cell::Cell()
{
	content = EMPTY;
}

Cell::~Cell()
{
}

Mark Cell::getContent()
{
	return Cell::content;
}

void Cell::setContent(Mark c)
{
	Cell::content = c;
}

void Cell::clear()
{
	Cell::content = EMPTY;
}

void Cell::paint()
{
	std::string str;
	switch (Cell::content)
	{
	case X:
		str = " X ";
		break;
	case O:
		str = " O ";
		break;
	default:
		str = "   ";
		break;
	}

	std::cout << str;
}