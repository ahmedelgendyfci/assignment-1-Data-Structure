#include <iostream>
#include "BigDecimalInt.h"

using namespace std;

int main()
{
	BigDecimalInt num1("123456789012345678901234567890");
	BigDecimalInt num2("113456789011345678901134567890");
	BigDecimalInt num3 = num2 + num1;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	//236913578023691357802369135780 
	cout << "num2 + num1 = " << num3 << endl;
    return 0;
}
