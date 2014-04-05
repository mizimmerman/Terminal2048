#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"
#include "command.h"
#include <map>

class Controller {
public:
	Controller();
	~Controller() {}
	void run();

private:
	std::map<Command, int (Board::*)()> commands;
};

#endif
