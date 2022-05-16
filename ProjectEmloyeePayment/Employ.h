#pragma once
#include<iostream>
#include<sstream>
#include<string.h>
#include <iomanip>

using namespace std;

class Employ {
public:
	virtual string toString() = 0;
	virtual string className() = 0;
public:
	string _name;	
public:
	Employ() {
		this->_name = "";
	}
	Employ(string name) {
		this->_name = name;
	}
	void setName(string value) { this->_name = value; }
	
	string getName() { return _name; }

};