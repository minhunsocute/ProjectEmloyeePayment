#include<iostream>
#include "listEmploy.h"
#include<map>
using namespace std;
int main() {
	listEmploy le;
	le.readFile("November2021.txt");
	le.outPut();
	return 0;
}
