#pragma once
#include<iostream>
#include<sstream>
#include<string.h>

using namespace std;

class Employ {
public:
	virtual string toString() = 0;
public:
	string _name;	
	float total_payment;
//public:
//	Employ() {
//		this->_name = "";
//		this->total_payment = 0;
//	}
//	Employ(string name, float total) {
//		this->_name = name;
//		this->total_payment = total;
//	}
//	void setName(string value) { this->_name = value; }
//	void setTotalPayment(float value) { this->total_payment = value; }
//	
//	string getName() { return _name; }
//	float getTotal() { return total_payment; }


};