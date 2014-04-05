#ifndef MODEL_H
#define MODEL_H

class View;

class Model {
public:
	static Model *get_instance();

	void notify_cell(int row, int col, int value);
	void attach(View *v);

	friend class Model_destroyer;

private:
	Model();
	~Model();

	static Model *ptr;
	View *view;

public:
	// disallow copy/move, construction or assignment
	Model(const Model&) = delete;
	Model(Model&&) = delete;
	Model& operator= (const Model&) = delete;
	Model& operator= (Model&&) = delete;
};

#endif
