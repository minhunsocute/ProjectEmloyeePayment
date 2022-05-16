#include "Dailyemployees.h"

Dailyemployees::Dailyemployees(float a, int b) {
	this->_dailyPayment = a;
	this->_totalDays = b;
}

Dailyemployees::Dailyemployees()  {
	this->_dailyPayment = 0;
	this->_totalDays = 0;
}
void Dailyemployees::setDailyPayment(float value) {
	this->_dailyPayment = value;
}

void Dailyemployees::setTotalDays(int value) {
	this->_totalDays = value;
}

float Dailyemployees::getDailyPayment() {
	return _dailyPayment;
}

int Dailyemployees::getTotalDays() {
	return _totalDays;
}
