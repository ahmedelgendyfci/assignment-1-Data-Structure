#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt()
{
	Number = "";
	size = 0;
}

BigDecimalInt::BigDecimalInt(string decStr )
{
	Number = decStr;
	int x = Number.find('-');
	if (x == -1)
	{
		Number1.push_back(0);
		x = Number.length();
		for (--x; x >= 0; x--)
		{
			stringstream ss;
			int y;
			ss << Number[x];
			ss >> y;
			Number1.push_back(y);
		}
	}
	else
	{
		Number1.push_back(1);
		x = Number.length();
		for (--x; x > 0; x--)
		{
			stringstream ss;
			int y;
			ss << Number[x];
			ss >> y;
			Number1.push_back(y);
		}
	}
	
}

BigDecimalInt::~BigDecimalInt()
{
	Number1.clear();
}

void BigDecimalInt:: setNumber(string Num)
{
	Number = Num;
	int x = Number.find('-');
	if (Number1.size() != 0)
		Number1.clear();
	if (x == -1)
	{
		Number1.push_back(0);
		x = Number.length();
		for (--x; x >= 0; x--)
		{
			stringstream ss;
			int y;
			ss << Number[x];
			ss >> y;
			Number1.push_back(y);
		}
	}
	else
	{
		Number1.push_back(1);
		x = Number.length();
		for (--x; x > 0; x--)
		{
			stringstream ss;
			int y;
			ss << Number[x];
			ss >> y;
			Number1.push_back(y);
		}
	}
}

string BigDecimalInt:: getNumber()
{
	return Number;
}

BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt anotherDec)
{
	BigDecimalInt res;
	res.Number1.clear();
	if (getsize() > anotherDec.getsize())
	{
		int aa = getsize() - anotherDec.getsize();
		for (int i = 0; i < aa; i++)
		{
			anotherDec.Number1.push_back(0);
		}
	}
	else if (getsize() < anotherDec.getsize())
	{
		int aa = anotherDec.getsize() - getsize();
		for (int i = 0; i < aa; i++)
		{
			Number1.push_back(0);
		}
	}
	if (Number1[0] == anotherDec.Number1[0])
	{
		res.Number1.push_back(Number1[0]);
		int c = 0;
		for (int i = 1; i<getsize(); i++)
		{
			int sum = Number1[i] + anotherDec.Number1[i] + c;
			if (sum > 9)
			{
				if (i != (getsize() - 1))
				{
					res.Number1.push_back(sum % 10);
					c = sum / 10;
				}
				else
				{
					res.Number1.push_back(sum );
				}
			}
			else
			{
				res.Number1.push_back(sum);
				c = 0;
				
			}

		}
	}
	else
	{
		bool a = 1;
		int i = getsize();
		cout << i << endl;
		for (--i; i > 0; i--)
		{
			if (Number1[i] > anotherDec.Number1[i])
			{
				a = 1;
				break;
			}
			else if (Number1[i] < anotherDec.Number1[i])
			{
				a = 0;
				break;
			}
		}
		if (a)
		{
			res.Number1.push_back(Number1[0]);
			int c = 10;
			for (int i = 1; i < getsize(); i++)
			{
				if (Number1[i] < anotherDec.Number1[i])
				{
					Number1[i] += c;
					Number1[i + 1] -= 1;
				}
				int sub = Number1[i] - anotherDec.Number1[i];
				res.Number1.push_back(sub);
			}
		}
		else
		{
			res.Number1.push_back(anotherDec.Number1[0]);
			int c = 10;
			for (int i = 1; i < getsize(); i++)
			{
				if (Number1[i] > anotherDec.Number1[i])
				{
					anotherDec.Number1[i] += c;
					anotherDec.Number1[i + 1] -= 1;
				}
				int sub = anotherDec.Number1[i] - Number1[i];
				res.Number1.push_back(sub);
			}
		}

	}

	return res;
}

BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
	if (anotherDec.Number1[0] == 0)
		anotherDec.Number1[0] = 1;
	else
		anotherDec.Number1[0] = 0;
	
	BigDecimalInt res;
	res.Number1.clear();
	if (getsize() > anotherDec.getsize())
	{
		int aa = getsize() - anotherDec.getsize();
		for (int i = 0; i < aa; i++)
		{
			anotherDec.Number1.push_back(0);
		}
	}
	else if (getsize() < anotherDec.getsize())
	{
		int aa = anotherDec.getsize() - getsize();
		for (int i = 0; i < aa; i++)
		{
			Number1.push_back(0);
		}
	}
	if (Number1[0] == anotherDec.Number1[0])
	{
		res.Number1.push_back(Number1[0]);
		int c = 0;
		for (int i = 1; i<getsize(); i++)
		{
			int sum = Number1[i] + anotherDec.Number1[i] + c;
			if (sum > 9)
			{
				if (i != (getsize() - 1))
				{
					res.Number1.push_back(sum % 10);
					c = sum / 10;
				}
				else
				{
					res.Number1.push_back(sum);
				}
			}
			else
			{
				res.Number1.push_back(sum);
				c = 0;

			}

		}
	}
	else
	{
		bool a = 1;
		int i = getsize();
		cout << i << endl;
		for (--i; i > 0; i--)
		{
			if (Number1[i] > anotherDec.Number1[i])
			{
				a = 1;
				break;
			}
			else if (Number1[i] < anotherDec.Number1[i])
			{
				a = 0;
				break;
			}
		}
		if (a)
		{
			res.Number1.push_back(Number1[0]);
			int c = 10;
			for (int i = 1; i < getsize(); i++)
			{
				if (Number1[i] < anotherDec.Number1[i])
				{
					Number1[i] += c;
					Number1[i + 1] -= 1;
				}
				int sub = Number1[i] - anotherDec.Number1[i];
				res.Number1.push_back(sub);
			}
		}
		else
		{
			res.Number1.push_back(anotherDec.Number1[0]);
			int c = 10;
			for (int i = 1; i < getsize(); i++)
			{
				if (Number1[i] > anotherDec.Number1[i])
				{
					anotherDec.Number1[i] += c;
					anotherDec.Number1[i + 1] -= 1;
				}
				int sub = anotherDec.Number1[i] - Number1[i];
				res.Number1.push_back(sub);
			}
		}

	}
	
	return res;
}

BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec)
{
	BigDecimalInt res;
	res.Number = anotherDec.Number;
	res.Number1 = anotherDec.Number1;
	return res;
}

int BigDecimalInt::getsize()
{
	size = Number1.size();
	return size;
}

ostream & operator << (ostream& out, BigDecimalInt b)
{
	int a = b.getsize();
	if (b.Number1[0] == 1)
		cout << "-";
	for (--a; a > 0; a--)
		cout << b.Number1[a];
	cout << endl;
	return out;
}

