#pragma once

class Calculator {

public:

	Calculator();
	~Calculator();

	int add(int a, int b) const;

	int subtract(int a, int b) const;

	int divide(int a, int b) const;

	int multiply(int a, int b) const;

};