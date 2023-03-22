#include "Calculator.h"

Calculator::Calculator() {
	// do nothing yet
}

Calculator::~Calculator() {
	// also do nothing yet
}

int Calculator::add(int a, int b) const {
	return a + b;
}

int Calculator::subtract(int a, int b) const {
	return a > b ? a - b : 0;
}

int Calculator::divide(int a, int b) const {
	return a / b;
}

int Calculator::multiply(int a, int b) const {
	return a * b;
}
