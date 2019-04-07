#pragma once
#include<iostream>
using namespace std;

class Fraction
{
public:
	Fraction();
	~Fraction();

	friend istream& operator>>(istream &, Fraction&);
	friend ostream& operator<<(ostream &, Fraction&);
	void operator+(const Fraction&);
	void operator-(const Fraction&);
	void operator*(const Fraction&);
	void operator/(const Fraction&);
	bool operator <(const Fraction&);
	bool operator >(const Fraction&);
	bool operator ==(const Fraction&);
	bool operator <=(const Fraction&);
	bool operator >=(const Fraction&);

	void reduce(int, int);

private:
	int num;
	int dnum;
};

