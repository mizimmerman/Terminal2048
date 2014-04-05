#include "terminal_view.h"
#include <iomanip>
#include <iostream>
using std::cout;
using std::endl;
using std::setw;

void print_border();

void Terminal_view::draw(int score)
{
	cout << "Score = " << score << endl;
	print_border();
	
	// Print cells
	for (int i = 0; i < 4; ++i) {
		cout << '|';
		for (int j = 0; j < 4; ++j) {
			if(board[i][j] != 0)
				cout << setw(4) << board[i][j] << '|';
			else
				cout << "    |";
		}
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

void Terminal_view::game_over(int score)
{
	cout << "Game over" << endl;
	cout << "Final score: " << score << endl;

}

void Terminal_view::game_won(int score)
{
	cout << "You win!!" << endl;
	cout << "Final score: " << score << endl;
}
