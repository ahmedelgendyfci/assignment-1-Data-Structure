#include<iostream>
using namespace std;


int Power(int a, int n)
{
	if (n != 0)
	{
		return a*Power(a, n - 1);
	}
	else
	{
		return 1;
	}

}

double  Power_(double a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n % 2 != 0)
	{
		return Power_(a, n / 2)*Power_(a, n / 2);
	}
	else
	{
		return a*Power_(a, n - 1);
	}
}
int main()
{
	cout << Power(3, 5) << endl;
	cout << Power_(5, 5) << endl;

	system("pause");
	return 0;
}