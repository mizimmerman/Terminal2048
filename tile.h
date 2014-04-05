#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile {
public:
	Tile() : value(0), has_merged(false) {}

	int get_value() { return value; }
	void set_value(int value_) { value = value_; }
	void set_ready() { has_merged = false;}

	// Combines rhs into this
	// Returns the value of the tiles before combining
	int merge(Tile& rhs);

	// Moves rhs into this tile's spot
	// Returns true if a meaningful shift occurred
	bool shift(Tile& rhs);

	bool operator==(const Tile& rhs);
	friend std::ostream& operator<<(std::ostream &out, Tile& t);
	
private:
	int value;
	bool has_merged;
};

#endif
