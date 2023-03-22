#pragma once

#include <string>

// possible to extend std::string, but I prefered to just overload cast
class RomeNumberAdapter {
public:
	RomeNumberAdapter(int arabNumber);

	// implementation of all string operations
	operator std::string() const { return this->_romeValue; };

private:
	std::string _romeValue;
};

