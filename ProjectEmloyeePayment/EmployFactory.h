#pragma once
#include<vector>
#include "Employ.h"
#include "Dailyemployees.h"
#include "Hourlyemployees.h"
#include "Manager.h"
#include "Productemployees.h"

class EmployType {
public:
	static const int dailyemployees = 0;
	static const int hourlyemployees = 1;
	static const int productemployees = 2;	
	static const int manager = 3;
};


class EmployFactory {
private:
	static inline EmployFactory* _instance = NULL;
	vector<Employ*> _prototypes;
	
	EmployFactory() {
		_prototypes.push_back(new Dailyemployees());
		_prototypes.push_back(new Hourlyemployees());
		_prototypes.push_back(new Productemployees());
		_prototypes.push_back(new Manager());
	}
public: 
	int suportedTypesCunt();

	Employ* creat(int type);
	static EmployFactory* instance();
	vector<Employ*> getProtoTypes();
};