#pragma once
#include<fstream>
#include "EmployFactory.h"
#include <regex>
#include <map>
class Conver {
public:
	virtual string convert(void* Emp) = 0;
};

class DailyConvert:public Conver {
public:
	string convert(void* Emp) {
		Dailyemployees* daily = (Dailyemployees*)Emp;
		stringstream builder;
		builder << left << setw(10) << daily->_name << "\t\t" << left << setw(15) << "Dailyemployees" << "\t\t" << daily->calcuPayment() << "$\n";

		return builder.str();
	}
};

class HourlyConvert:public Conver {
public: 
	string convert(void* Emp) {
		Hourlyemployees* hour = (Hourlyemployees*)Emp;
		stringstream builder;
		builder << left << setw(10) << hour->_name << "\t\t" << left << setw(15) << "Hourlyemployees" << "\t\t" << hour->calcuPayment() << "$\n";
		return builder.str();

	}
};

class ProductConvert :public Conver {
public:
	string convert(void* Emp) {
		Productemployees* pro = (Productemployees*)Emp;
		stringstream builder;
		builder << left << setw(10) << pro->_name << "\t\t" << left << setw(15) << "Productemployees" << "\t" << pro->calcuPayment() << "$\n";
		return builder.str();

	}
};

class ManagerConvert :public Conver {
public:
	string convert(void* Emp) {
		Manager* mana = (Manager*)Emp;
		stringstream builder;
		builder << left << setw(10) << mana->_name << "\t\t" << left << setw(15) << "Manager" << "\t\t" << mana->calcuPayment() << "$\n";
		return builder.str();
	}
};

class listEmploy {
private:
	vector<Employ*> listEmploy;
public:

	int checkTypeEmploy(string type) {
		if (type == "Manager")
			return 1;
		return 0;
	}
	vector<string> split(string line) {
		vector<string> result;
		string item = "";
		int checkAdd = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ';') {
				checkAdd = 0;
				result.push_back(item);
			}
			if (checkAdd == 1 and line[i] != '$') {
				item += line[i];
			}
			if (line[i] == '=') {
				checkAdd = 1;
				item = "";
			}
		}
		result.push_back(item);
		return result;
	}
	tuple<bool, int,int, string, Employ*> getTypeOfEmploy(string line1, string  line2) {
		bool successful = false;
		int errcode = 0;
		int index1 = 0;
		string message = "";
		Employ* f = NULL;

		if (line1.size() == 0 || line2.size() == 0) {
			errcode = 1;
			message = "Line is null";
		}
		else {
			bool check = true;
			int index = 0; string type = "", name = "";
			try {
				index = line1.find(':');
				type = line1.substr(0, index);
				name = line1.substr(index + 2, line1.length() - 1);
			}
			catch (const char* message) {
				check = false;
			}
			if (!check) {
				errcode = 2;
				message = "Invalid format line 1";
			}
			else {

				if (checkTypeEmploy(type) == 1) {// Manager
					string patterLine2 = "   FixedPayment=\\d+\\$; TotalEmployees=\\d+\\; PaymentPerEmployee=\\d+\\$";
					bool isMatched = regex_match(line2, regex(patterLine2));
					if (!isMatched) {
						errcode = 3;
						message = "Invalid format line 2";
					}
					else {
						auto tokens = split(line2);
						double fixed = stod(tokens[0]);
						int total = stoi(tokens[1]);
						double payment = stod(tokens[2]);
						successful = true;
						f = new Manager(name, fixed, total, payment);
						index1 = 3;
					}
				}
				else {
					string typeName = type.substr(0, type.find('E'));
					string patterLine2 = (type == "ProductEmployee") ? "   PaymentPerProduct=\\d+\\$; TotalProducts=\\d+"
																	 : (type == "DailyEmployee") ?  "   DailyPayment=\\d+\\$; TotalDays=\\d+"
																								 : "   HourlyPayment=\\d+\\$; TotalHours=\\d+";
					bool isMatched = regex_match(line2, regex(patterLine2));
					if (!isMatched) {
						errcode = 3;
						message = "Invalid format line 2";
					}
					else {
						auto tokens = split(line2);
						double d = stod(tokens[0]);
						int i = stoi(tokens[1]);
						successful = true;
						if (type == "DailyEmployee") { f = new Dailyemployees(name, d, i); index1 = 0; }
						else if (type == "HourlyEmployee") { f = new Hourlyemployees(name, d, i); index1 = 1; }
						else if (type == "ProductEmployee") { f = new Productemployees(name, d, i); index1 = 2; }
					}
				}
			}
		}
		auto result = make_tuple(successful,index1, errcode, message, f);
		return result;
	}

	void readFile(string filename) {//November2021.txt
		ifstream fin;
		fin.open(filename);
		string str = "";
		string line1 = "";
		string line2 = "";
		int count_line = 0;
		bool successful = false;
		int errorCode = 0;
		string message = "";
		int index = 0;
		Employ* f;
		while (std::getline(fin, str)) {
			if (count_line == 0) { line1 = str; }
			else if (count_line == 1) { line2 = str; }
			count_line++;
			if (count_line == 2) {
				count_line = 0;
				tie(successful,index, errorCode, message, f) = getTypeOfEmploy(line1, line2);

				if (successful) {
					Employ* em = EmployFactory::instance()->creat(index);
					em = f;
					this->listEmploy.push_back(em);
				}
			}
		}
		fin.close();
		return;
	}

	void outPut() {
		map<string, Conver*> ui = {
			{(new Dailyemployees())->className(), new DailyConvert()},
			{(new Hourlyemployees())->className(), new HourlyConvert()},
			{(new Productemployees())->className(), new ProductConvert()},
			{(new Manager())->className(), new ManagerConvert()}
		};
		cout<< left << setw(10) <<"Name" << "\t\t" << left << setw(15) << "Employee" << "\t\t" << "final Payement"<<"\n\n";
		for (int i = 0; i < listEmploy.size(); i++) {
			auto converter = ui[listEmploy[i]->className()];
			string data = converter->convert((void*)listEmploy[i]);
			cout << data;
		}
	}
};