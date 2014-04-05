#ifndef TERMINAL_VIEW_H
#define TERMINAL_VIEW_H

#include "view.h"

class Terminal_view : public View {
public:
	Terminal_view() : View() {}
	void draw(int score) override;
	void game_over(int score) override;
	void game_won(int score) override;
};

#endif
