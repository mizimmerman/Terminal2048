#include "board.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using std::rand;
using std::vector;
using std::cout;
using std::endl;

void print_border();

Board::Board()
{
	no_free_space = false;
	srand(time(0));
	insert_random_tile();
}

bool Board::init_round()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			board[i][j].set_ready();
		}
	}
	return !game_over() && !game_won();
}

// Draws the board
void Board::draw()
{
	print_border();
	
	// Print cells
	for (int i = 0; i < 4; ++i) {
		cout << '|';
		for (int j = 0; j < 4; ++j)
			cout << board[i][j] << '|';
		print_border();
	}

	cout << endl;
}

void print_border()
{
	cout << endl << '+';
	for (int i = 0; i < 4; ++i)
		cout << "----" << '+';
	cout << endl;
}

// Returns true if the player cannot make any moves
bool Board::game_over()
{
	if (!no_free_space)
		return false;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i != 3) {
				if (board[i][j] == board[i+1][j])
					return false;
			}
			if (j != 3) {
				if (board[i][j] == board[i][j+1])
					return false;
			}
		}
	}

	return true;
}

// Returns true if the board contains a tile with the value 2048
bool Board::game_won()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (board[i][j].get_value() == 2048)
				return true;
		}
	}

	return false;
}

// Performs the named operation on the board
int Board::up()
{
	bool did_something = false;
	int score = 0;
	for (int k = 0; k < 3; ++k) {
		// Merge pass
		for (int i = 1; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int add = board[i-1][j].merge(board[i][j]);
				if (add) {
					score += add;
					no_free_space = false;
					did_something = true;
				}
			}
		}

		// Shift pass
		for (int i = 1; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if(board[i-1][j].shift(board[i][j]))
					did_something = true;
			}
		}
	}
	if (did_something)
		insert_random_tile();

	return score;
}

int Board::down()
{
	bool did_something = false;
	int score = 0;
	for (int k = 0; k < 3; ++k) {
		// Merge pass
		for (int i = 3; i > 0; --i) {
			for (int j = 0; j < 4; ++j) {
				int add = board[i][j].merge(board[i-1][j]);
				if (add) {
					score += add;
					no_free_space = false;
					did_something = true;
				}
			}
		}

		// Shift pass
		for (int i = 3; i > 0; --i) {
			for (int j = 0; j < 4; ++j) {
				if(board[i][j].shift(board[i-1][j]))
					did_something = true;
			}
		}
	}

	if (did_something)
		insert_random_tile();

	return score;
}

int Board::left()
{
	bool did_something = false;
	int score = 0;
	for (int k = 0; k < 3; ++k) {
		// Merge pass
		for (int j = 1; j < 4; ++j) {
			for (int i = 0; i < 4; ++i) {
				int add = board[i][j-1].merge(board[i][j]);
				if (add) {
					score += add;
					no_free_space = false;
					did_something = true;
				}
			}
		}

		// Shift pass
		for (int j = 1; j < 4; ++j) {
			for (int i = 0; i < 4; ++i) {
				if(board[i][j-1].shift(board[i][j]))
					did_something = true;
			}
		}
	}

	if (did_something)
		insert_random_tile();

	return score;
}

int Board::right()
{
	bool did_something = false;
	int score = 0;
	for (int k = 0; k < 3; ++k) {
		// Merge pass
		for (int j = 3; j > 0; --j) {
			for (int i = 0; i < 4; ++i) {
				int add = board[i][j].merge(board[i][j-1]);
				if (add) {
					score += add;
					no_free_space = false;
					did_something = true;
				}
			}
		}

		// Shift pass
		for (int j = 3; j > 0; --j) {
			for (int i = 0; i < 4; ++i) {
				if(board[i][j].shift(board[i][j-1]))
					did_something = true;
			}
		}
	}

	if (did_something)
		insert_random_tile();

	return score;
}

void Board::insert_random_tile()
{
	struct cell {
		cell(int x, int y) : row(x), col(y) {}
		int row;
		int col;
	};

	if (!no_free_space) {
		vector<cell> free_spaces;

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (board[i][j].get_value() == 0) {
					free_spaces.push_back(cell(i, j));
				}
			}
		}

		int idx = rand() % free_spaces.size();
		int val = ((rand() % 20) == 0) ? 4 : 2;
		board[free_spaces[idx].row][free_spaces[idx].col].set_value(val);

		if (free_spaces.size() == 1)
			no_free_space = true;
		else
			no_free_space = false;
	}
}
