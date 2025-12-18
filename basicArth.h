#pragma once
#include "vals.h"
#ifndef BASICARTH_H
#define BASICARTH_H
using namespace std;


class basicArth :public vals
{
public:
	basicArth(int, int);
	void add();
	void sub();
	void mul();
	void div();
};


#endif // !1