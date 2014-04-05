#include "view.h"

View::View()
{
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			board[i][j] = 0;
}

View::~View() {}

void View::update_board(int row, int col, int val)
{
	board[row][col] = val;
}

void View::clear()
{
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			board[i][j] = 0;	
}
