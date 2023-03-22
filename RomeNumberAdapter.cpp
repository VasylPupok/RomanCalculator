#include "RomeNumberAdapter.h"

RomeNumberAdapter::RomeNumberAdapter(int arabNumber) {

	if (arabNumber == 0) {
		this->_romeValue = "NULL";
		return;
	}

	for (int i = 0; i < arabNumber / 1000; ++i) {
		this->_romeValue += 'M';
	}
	arabNumber %= 1000;

	if (arabNumber >= 900) {
		this->_romeValue += "CM";
		arabNumber -= 900;
	}

	if (arabNumber >= 500) {
		this->_romeValue += 'D';
		arabNumber -= 500;
	}

	if (arabNumber >= 400) {
		this->_romeValue += "CD";
		arabNumber -= 400;
	}

	for (int i = 0; i < arabNumber / 100; ++i) {
		this->_romeValue += 'C';
	}
	arabNumber %= 100;

	if (arabNumber >= 90) {
		this->_romeValue += "XC";
		arabNumber -= 90;
	}

	if (arabNumber >= 50) {
		this->_romeValue += "L";
		arabNumber -= 50;
	}

	if (arabNumber >= 40) {
		this->_romeValue += "XL";
		arabNumber -= 40;
	}

	for (int i = 0; i < arabNumber / 10; ++i) {
		this->_romeValue += 'X';
	}
	arabNumber %= 10;

	if (arabNumber == 9) {
		this->_romeValue += "IX";
		return;
	} else if (arabNumber == 4) {
		this->_romeValue += "IV";
		return;
	}
	
	if (arabNumber >= 5) {
		this->_romeValue += "V";
		arabNumber -= 5;
	}

	for (int i = 0; i < arabNumber; ++i) {
		this->_romeValue += "I";
	}

}
