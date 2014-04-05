#include "model.h"
#include "view.h"

Model *Model::ptr = nullptr;

Model::Model()
{
}

Model *Model::get_instance()
{
	if(!ptr)
		ptr = new Model();

	return ptr;
}

void Model::notify_cell(int row, int col, int value)
{
	view->update_board(row, col, value);
}

void Model::attach(View *v)
{
	view = v;
}

class Model_destroyer {
public:
	~Model_destroyer() { delete Model::ptr; }
};

static Model_destroyer destructor;

Model::~Model()
{
	if(view)
		delete view;
}
