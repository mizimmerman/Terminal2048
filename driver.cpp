#include "controller.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "\nWelcome to 2048 - Command Line Edition\n" << endl;
	Controller c;
	c.run();

	return 0;
}
