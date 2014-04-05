#ifndef VIEW_H
#define VIEW_H

class View {
public:
	View();
	virtual ~View();

	virtual void draw(int score) = 0;
	virtual void game_over(int score) = 0;
	virtual void game_won(int score) = 0;
	virtual void clear();

	virtual void update_board(int row, int col, int val);

protected:
	int board[4][4];
};


#endif
