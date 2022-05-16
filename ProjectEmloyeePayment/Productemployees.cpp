#include "Productemployees.h"

Productemployees::Productemployees(){
	this->_paymentPerProduct = 0;
	this->_totalProducts = 0;
}
double Productemployees::paymentPerProduct() { return _paymentPerProduct; }
int Productemployees::totalProducts() { return _totalProducts; }
void Productemployees::setPaymentPerProduct(double value){
	this->_paymentPerProduct = value;
}
void Productemployees::setTotalProducts(int value) {
	this->_totalProducts = value;
};

double Productemployees::calcuPayment(){
	return this->_paymentPerProduct * this->_totalProducts;
}
string Productemployees::toString() {
	stringstream builder;
	builder << this->_name << "\t\t" << "Productemployees" << "\t\t" << calcuPayment() << "$\n";
	return builder.str();
}
