#include "Hourlyemployees.h"

Hourlyemployees::Hourlyemployees() {
	this->_hourlyPayment = 0;
	this->_totalHours = 0;
}

double Hourlyemployees::hourlyPayment() { return _hourlyPayment; }
int Hourlyemployees::totalHours() { return _totalHours; }
void Hourlyemployees::setHourlyPayment(double value){
	this->_hourlyPayment = value;
}
void Hourlyemployees::setTotalHours(int value){
	this->_totalHours = value;
}
double Hourlyemployees::calcuPayment(){
	return this->_hourlyPayment * this->_totalHours;
}
string Hourlyemployees::toString(){
	stringstream builder;
	builder << this->_name << "\t\t" << "Hourlyemployees" << "\t\t" << calcuPayment() << "$\n";
	return builder.str();
}