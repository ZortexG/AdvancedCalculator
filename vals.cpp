#include "vals.h"
#include <iostream>
#include <string>
using namespace std;
vals::vals(int v1, int v2) {
	this->val1 = v1;
	this->val2 = v2;
}
void vals::setVal1(int v1) {
	val1 = v1;
}
void vals::setVal2(int v2) {
	val2 = v2;
}
int vals::getVal1() {
	return val1;
}
int vals::getVal2() {
	return val2;
}
void vals::print() {
	cout << "First Value is: " << val1 << endl;
	cout << "Second Value is: " << val2 << endl;
	cout << "The last result is: " << sum << endl;
}

void vals::cont() {
	val1 = sum;
}

void vals::clear() {
	val1 = 0;
	val2 = 0;
	sum = 0;
	temp = 0;
}