#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class BigDecimalInt
{
public:
	BigDecimalInt(string decStr);
	BigDecimalInt();
	~BigDecimalInt();
	void setNumber(string Num);
	string getNumber();
	BigDecimalInt operator+ (BigDecimalInt anotherDec);
	BigDecimalInt operator- (BigDecimalInt anotherDec);
	BigDecimalInt operator= (BigDecimalInt anotherDec);
	int getsize();
	friend ostream & operator << (ostream& out, BigDecimalInt b);

private:
	string Number;
	vector<int>Number1;
	int size;
};

#endif
