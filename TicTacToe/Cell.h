#pragma once

enum Mark { EMPTY, X, O };

class Cell
{
private:
	Mark content;

public:
	Cell();
	~Cell();
	Mark getContent();
	void setContent(Mark c);
	void clear();
	void paint();
};