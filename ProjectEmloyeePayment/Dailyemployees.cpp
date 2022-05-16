#include "Dailyemployees.h"


Dailyemployees::Dailyemployees()  {
	this->_dailyPayment = 0;
	this->_totalDays = 0;
}
void Dailyemployees::setDailyPayment(double value) {
	this->_dailyPayment = value;
}

void Dailyemployees::setTotalDays(int value) {
	this->_totalDays = value;
}

double Dailyemployees::getDailyPayment() {
	return _dailyPayment;
}

int Dailyemployees::getTotalDays() {
	return _totalDays;
}

double Dailyemployees::calcuPayment() {
	return  this->_dailyPayment * this->_totalDays;
}
string Dailyemployees::toString() {
	stringstream builder;
	builder << this->_name << "\t\t" << "Dailyemployees" << "\t\t" << calcuPayment() << "$\n";
	return builder.str();
}
