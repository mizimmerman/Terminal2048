#include "controller.h"
#include "view.h"
#include "model.h"
#include "terminal_view.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::map;

/* Command modes:
 command | WASD | ULRD
   UP    |  w   | u/up
   DOWN  |  s   | d/down
   RIGHT |  d   | r/right
   LEFT  |  a   | l/left
 */
enum Mode {WASD, ULRD};

// Asks the user which mode to play the game in:
Mode get_mode();

// Gets the next command from the user
Command get_command(Mode m);

void clear_line();

Controller::Controller()
{
	commands.insert({
		{LEFT, &Board::left}, {UP, &Board::up      },
		{DOWN, &Board::down}, {RIGHT, &Board::right}
	});
}

void Controller::run()
{
	View *view = new Terminal_view();
	Model::get_instance()->attach(view);
	Board board;
	int score = 0;
	Mode m = get_mode();
	while (board.init_round()) {
		view->draw(score);
		score += (board.*commands[get_command(m)])();
	}

	if (board.game_over())
		view->game_over(score);
	else
		view->game_won(score);
}

// Asks the user which mode to play the game in:
Mode get_mode()
{
	char c;
	for (;;) {
		cout << "Which mode to play in?\n(W)ASD\n(U)LRD\n(H)elp" << endl;
		cin >> c;
		clear_line();
		c = toupper(c);
		switch(c) {
		case 'W':
			return WASD;
		case 'U':
			return ULRD;
		case 'H':
			cout << "Command modes:\ncommand | WASD | ULRD\n";
			cout << "  UP    |  w   | u/up\n  DOWN  |  s   | d/down\n";
			cout << "  RIGHT |  d   | r/right\n  LEFT  |  a   | l/left\n" << endl;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}

}

// Gets the next command from the user
Command get_command(Mode m)
{
	char c;
	for (;;) {
		cin >> c;
		c = toupper(c);
		if (m == ULRD) {
			clear_line();
			switch (c) {
			case 'U':
				return UP;
			case 'L':
				return LEFT;
			case 'R':
				return RIGHT;
			case 'D':
				return DOWN;
			default:
				cout << "Invalid input" << endl;
			}
		}
		else {
			switch (c) {
			case 'W':
				return UP;
			case 'A':
				return LEFT;
			case 'D':
				return RIGHT;
			case 'S':
				return DOWN;
			default:
				clear_line();
				cout << "Invalid input" << endl;
			}
		}
	}
}

void clear_line()
{
	while (cin.get() != '\n');
}