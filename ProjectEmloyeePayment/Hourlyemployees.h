#pragma once
#include "Employ.h"

class Hourlyemployees : public Employ {
private:
	float _hourlyPayment;
	int  _totalHours;
public:
	Hourlyemployees(){};
};