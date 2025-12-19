#include "vals.h"
#include <iostream>
#include <string>
using namespace std;
vals::vals(double v1, double v2, double v3) {
	this->val1 = v1;
	this->val2 = v2;
	this->val3 = v3;
}
void vals::setVal1(double v1) {
	val1 = v1;
}
void vals::setVal2(double v2) {
	val2 = v2;
}
void vals::setVal3(double v3) {
	val3 = v3;
}
double vals::getVal1() {
	return val1;
}
double vals::getVal2() {
	return val2;
}
double vals::getVal3() {
	return val3;
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
	val3 = 0;
}