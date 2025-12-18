#include "basicArth.h"
#include <iostream>
using namespace std;
basicArth::basicArth(int v1, int v2) :vals(v1, v2) {
	this->val1 = v1;
	this->val2 = v2;
}
void basicArth::add() {
	sum = val1 + val2;
}

void basicArth::sub() {
	sum = val1 - val2;
}
void basicArth::mul() {
	sum = val1 * val2;
}
void basicArth::div() {
	sum = val1 / val2;
}