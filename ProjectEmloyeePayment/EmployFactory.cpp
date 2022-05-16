#include "EmployFactory.h"

int EmployFactory::suportedTypesCunt() {
	return _prototypes.size();
}

Employ* EmployFactory::creat(int type) {
	return _prototypes.at(type);
}

EmployFactory* EmployFactory::instance() {
	if (_instance == NULL) {
		_instance = new EmployFactory();
	}
	return  _instance;
}
vector<Employ*> EmployFactory::getProtoTypes() { return _prototypes; }