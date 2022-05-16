#include "Dailyemployees.h"


Dailyemployees::Dailyemployees()  {
	this->_dailyPayment = 0;
	this->_totalDays = 0;
}

Dailyemployees::Dailyemployees(string name, double d, int i): Employ(name), _dailyPayment(d), _totalDays(i){}
void Dailyemployees::setDailyPayment(double value) {this->_dailyPayment = value;}

void Dailyemployees::setTotalDays(int value) {this->_totalDays = value;}

double Dailyemployees::getDailyPayment() {return _dailyPayment;}

int Dailyemployees::getTotalDays() {return _totalDays;}

double Dailyemployees::calcuPayment() {
	return  this->_dailyPayment * this->_totalDays;
}
string Dailyemployees::toString() {
	stringstream builder;
	builder << left << setw(10) << this->_name << "\t\t" << left << setw(15) << "Dailyemployees" << "\t\t" << calcuPayment() << "$\n";

	return builder.str();
}
