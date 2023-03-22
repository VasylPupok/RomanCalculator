#include "ArabNumberAdapter.h"
#include <unordered_map>

ArabNumberAdapter::ArabNumberAdapter(const std::string& romanNumber) :
	_arabValue(0)
{

	if (romanNumber == "NULL") {
		return;
	}

	static std::unordered_map<char, int> romanSignMap =
	{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	int prevVal = 1001;
	int currVal;

	for (char c : romanNumber) {
		if (romanSignMap.find(c) == romanSignMap.end()) {
			throw "Parsing error";
			// TODO throw actual exception
		}

		currVal = romanSignMap[c];
		if (currVal > prevVal) {
			if (prevVal == 1 || prevVal == 10 || prevVal == 100) {
				if (currVal == prevVal * 5) {
					this->_arabValue += prevVal * 3;
				}
				else if (currVal == prevVal * 10) {
					this->_arabValue += prevVal * 8;
				}
				else {
					throw "Parsing error";
					// TODO throw actual exception
				}
			}
			else {
				throw "Parsing error";
				// TODO throw actual exception
			}
		}
		else {
			this->_arabValue += currVal;
		}
		prevVal = currVal;
	}
}
