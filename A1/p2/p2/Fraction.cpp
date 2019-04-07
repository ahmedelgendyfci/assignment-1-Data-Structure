#include "Fraction.h"


Fraction::Fraction()
{
	num = 0;
	dnum = 0;
}

istream& operator>>(istream &input, Fraction& fraction)
{
	cout << "Enter Num: ";
	input >> fraction.num;
	cout << "Enter DNum: ";
	input >> fraction.dnum;

	return input;
}

ostream& operator<<(ostream &out, Fraction& fraction)
{
	out << fraction.num << '/' << fraction.dnum << endl;
	return out;
}


void Fraction::operator+(const Fraction& fraction)
{
	int bst;
	int mkam;

	bst = (num*fraction.dnum) + (fraction.num*dnum);
	mkam = dnum*fraction.dnum;
	//reduce(bst, mkam);
}

void Fraction::operator-(const Fraction& fraction)
{
	int bst;
	int mkam;

	bst = (num*fraction.dnum) - (fraction.num*dnum);
	mkam = dnum*fraction.dnum;

	reduce(bst, mkam);
}

void Fraction::operator*(const Fraction& fraction)
{
	int bst;
	int mkam;

	bst = num*fraction.num;
	mkam = dnum*fraction.dnum;

	reduce(bst, mkam);
}

void Fraction::operator/(const Fraction& fraction)
{
	int bst;
	int mkam;

	bst = num*fraction.dnum;
	mkam = dnum*fraction.num;

	reduce(bst, mkam);
}


bool Fraction::operator <(const Fraction& fraction)
{
	if ((float)num / (float)dnum < (float)fraction.num / (float)fraction.dnum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator >(const Fraction& fraction)
{
	if ((float)num / (float)dnum > (float)fraction.num / (float)fraction.dnum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator ==(const Fraction& fraction)
{
	if ((float)num / (float)dnum == (float)fraction.num / (float)fraction.dnum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator >=(const Fraction& fraction)
{
	if (
		((float)num / (float)dnum == (float)fraction.num / (float)fraction.dnum)
		||
		((float)num / (float)dnum > (float)fraction.num / (float)fraction.dnum)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Fraction::operator <=(const Fraction& fraction)
{
	if (
		((float)num / (float)dnum == (float)fraction.num / (float)fraction.dnum)
		||
		((float)num / (float)dnum < (float)fraction.num / (float)fraction.dnum)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fraction::reduce(int num, int dnum)
{
	for (int i = num * dnum; i > 1; i--) {
		if ((dnum % i == 0) && (num % i == 0)) {
			dnum /= i;
			num /= i;
		}
	}
	if (num == dnum)
	{
		cout << num << endl;
	}
	else if (num==0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << num << '/' << dnum << endl;
	}
}

Fraction::~Fraction()
{
}
