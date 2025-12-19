#pragma once
#ifndef VALS_H
#define VALS_H
using namespace std;


class vals
{
protected:
	double val1;
	double val2;
	double val3;
	double sum;
public:
	vals(double, double, double);
	void setVal1(double);
	void setVal2(double);
	void setVal3(double);
	double getVal1();
	double getVal2();
	double getVal3();
	void cont();
	void clear();
	void print();
};


#endif // !1