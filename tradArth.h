#pragma once
#include "vals.h"
using namespace std;
class tradArth : public vals
{
	public:
	tradArth(double, double, double);
	void doOperation(char);
protected:
	char op;
};

