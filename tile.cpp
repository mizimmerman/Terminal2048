#include "tile.h"
#include <iomanip>
using std::setw;
using std::ostream;

ostream& operator<<(ostream &out, Tile& t)
{
	if (t.value)
		out << setw(4) << t.value;
	else
		out << "    ";
	return out;
}

int Tile::merge(Tile& rhs)
{
	if (value != 0 && rhs.value == value &&
		!has_merged && !rhs.has_merged) {
		value += rhs.value;
		rhs.value = 0;
		has_merged = true;
		return value / 2;
	}
	return 0;
}

bool Tile::operator==(const Tile& rhs)
{
	return value == rhs.value;
}

bool Tile::shift(Tile& rhs)
{
	if (value == 0 && rhs.value != 0) {
		value = rhs.value;
		rhs.value = 0;
		has_merged = rhs.has_merged;
		rhs.has_merged = false;
		return true;
	}

	return false;
}
