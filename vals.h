#pragma once
#ifndef VALS_H
#define VALS_H
using namespace std;


class vals
{
protected:
	int val1;
	int val2;
	int temp;
	int sum;
public:
	vals(int, int);
	void setVal1(int);
	void setVal2(int);
	int getVal1();
	int getVal2();
	void cont();
	void clear();
	void print();
};


#endif // !1