#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

class Board {
public:
	Board();

	// Initializes the board, returns false if the game is over or won
	bool init_round();

	// Draws the board
	void draw();

	// Returns true if the player cannot make any moves
	bool game_over();

	// Returns true if the board contains a tile with the value 2048
	bool game_won();

	// Performs the named operation on the board
	int up();
	int down();
	int left();
	int right();

private:
	Tile board[4][4];
	bool no_free_space;

	void insert_random_tile();

};

#endif
