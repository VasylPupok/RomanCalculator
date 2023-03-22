#pragma once

#include <string>


class ArabNumberAdapter /* extends Integer */ {
public:
	ArabNumberAdapter(const std::string& romanNumber);

	// implementation of all int operations
	operator int() const { return this->_arabValue; }

private:
	int _arabValue;
};
