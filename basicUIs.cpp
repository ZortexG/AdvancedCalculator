#include "basicUIs.h"
#include <iostream>
#include<string>
#include<cctype>
using namespace std;
basicUIs::basicUIs(int v1, int v2) :basicArth(v1, v2) {
	this->val1 = v1;
	this->val2 = v2;
}
void basicUIs::summer() {
	this->add();
}
void basicUIs::subtracter() {
	this->sub();
}
void basicUIs::multiplier() {
	this->mul();
}
void basicUIs::divider() {
	this->div();
}
void basicUIs::menu() {
	string choice;
	int opt;

	while(choice!="q"){
	cout << "write Q to exit, everything else continues" << endl;
	cin >> choice;
	choice = tolower(choice[0]);
	if(choice=="q"){
		break;
	}
	cout << "What do you want to do?" << endl;
	cout << "1. Do math" << endl;
	cout << "2. Print Values" << endl;
	cout << "3. Clear Values" << endl;
	cin >> opt;
	if(opt==1){
		int ch;
		cout << "Enter first value: " << endl;
		cin >> val1;
		cout << "Enter second value: " << endl;
		cin >> val2;
		cout << "Choose operation: " << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Division" << endl;
		cin >> ch;
		if(ch==1){
		summer();
		}
		else if (ch == 2) {
		subtracter();
		}
		else if (ch == 3) {
			multiplier();
		}
		else if (ch == 4) {
			divider();
		}
		else {
			
		}
	}
	else if (opt==2) {
		print();
	}
	else if (opt==3)
	{
		clear();
	}
	else {

	}
	}
}