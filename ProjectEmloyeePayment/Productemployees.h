#pragma once
#include "Employ.h"
class Productemployees :public Employ {
private:
	double _paymentPerProduct;
	int _totalProducts;
public:
	Productemployees();
	Productemployees(string, double, int);

	double paymentPerProduct();
	int totalProducts();
	void setPaymentPerProduct(double);
	void setTotalProducts(int);
	double calcuPayment();

	string toString();
	string className() { return "Productemployees"; }
};