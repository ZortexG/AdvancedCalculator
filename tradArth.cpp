#include "tradArth.h"
#include <iostream>
#include<string>
using namespace std;

tradArth::tradArth(double v1, double v2, double v3) :vals(v1, v2, v3)
{
	this->val1 = v1;
	this->val2 = v2;
	this->val3 = v3;
	this->op = 0;
}
void tradArth::doOperation(char op)
{
	if (val2 == 0) {
		val2 = val1;
		this->op = op;
		return;
	}

	if (op == '+') {
		val2 += val1;
	}
	else if (op == '-') {
		val2 -= val1;
	}
	else if (op == '*') {
		val2 *= val1;
	}
	else if (op == '/') {
		if (val1 != 0) {
			val2 /= val1;
		}
		else {
		
		}
	}
	else {
		
	}
	this->op = op;
}