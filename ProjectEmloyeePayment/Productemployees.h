#pragma once
#include "Employ.h"
class Productemployees :public Employ {
private:
	double _paymentPerProduct;
	int _totalProducts;
public:
	Productemployees();
	string toString();
	double paymentPerProduct();
	int totalProducts();
	void setPaymentPerProduct(double);
	void setTotalProducts(int);
	double calcuPayment();
};