#pragma once
#include<vector>
#include "Employ.h"
#include "Dailyemployees.h"
#include "Hourlyemployees.h"
#include "Manager.h"
#include "Productemployees.h"

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
	int suportedTypesCunt() {
		return _prototypes.size();
	}

	static EmployFactory* instance() {
		if (_instance == NULL) {
			_instance = new EmployFactory();
		}
		return  _instance;
	}
};