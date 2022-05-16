#pragma once
#include<iostream>
#include"Employ.h"
class Dailyemployees:public Employ{
private:
	float _dailyPayment;
	int _totalDays;
public:
	Dailyemployees();
	Dailyemployees(float a, int b) ;
	void setDailyPayment(float );
	void setTotalDays(int );
	float getDailyPayment();
	int getTotalDays();
	string toString();
public:
	~Dailyemployees();
};