#pragma once
#include "Employ.h"

class Manager : public Employ {
private:
	double _fixedPayment;
	int _totalEmployees;	
	double _paymentPerEmployee;
public:
	Manager();
	Manager(string, double, int, double);
	double fixedPayment();	
	int totalEmployees();
	double paymentPerEmployee();
	void setFixedPayment(double);
	void setTotalEmployees(int);
	void setPaymentPerEmployee(double);
	double calcuPayment();
	string toString();
	string className() { return "Manager"; }
};