#pragma once
#include<iostream>
#include"Employ.h"
class Dailyemployees:public Employ{
private:
	double _dailyPayment;
	int _totalDays;
public:
	Dailyemployees();
	Dailyemployees(string, double, int);
	void setDailyPayment(double );
	void setTotalDays(int );
	double getDailyPayment();
	int getTotalDays();
	string toString();
	string className() { return "Dailyemployees"; }
	double calcuPayment();
};