#include "Matrix.h"
using namespace std;

int main()
{

	cout << "Welcome To Zamalek Calculator !!" << endl;
	cout << "--------------------------------" << endl;
	int num = 0;

	cout << "1- Perform Matrix Addition !!" << endl;
	cout << "2- Perform Matrix Subtraction !!" << endl;
	cout << "3- Perform Matrix Multiplication !!" << endl;
	cout << "4- Matrix Transpose !!" << endl;
	cout << ">> ";
	cin >> num;
	int row;
	int col;
	if (num == 1)
	{
		cout << "Welcome To Addition Calculator !!" << endl;
		cout << "\t---------------" << endl;

		cout << "Enter The Number Of Rows: ";
		cin >> row;
		cout << "Enter The Number Of Cols: ";
		cin >> col;
		
		cout << "Enter First Matrix !! \n";
		Matrix m1(row, col);
		cin >> m1;
		cout << m1;

		cout << "Enter Second Matrix !! \n";
		Matrix m2(row, col);
		cin >> m2;
		cout << m2;

		cout << "The Addition Of The Matrices !! \n";
		m1 + m2;

	}
	else if (num == 2)
	{
		cout << "Welcome To subtraction Calculator !!" << endl;
		cout << "\t---------------" << endl;

		cout << "Enter The Number Of Rows: ";
		cin >> row;
		cout << "Enter The Number Of Cols: ";
		cin >> col;

		cout << "Enter First Matrix !! \n";
		Matrix m1(row, col);
		cin >> m1;
		cout << m1;

		cout << "Enter Second Matrix !! \n";
		Matrix m2(row, col);
		cin >> m2;
		cout << m2;

		cout << "The subtraction Of The Matrices !! \n";
		m1 - m2;
	}
	else if (num == 3)
	{
		cout << "Welcome To Multiplication Calculator !!" << endl;
		cout << "\t---------------" << endl;


		cout << "Enter The Number Of Rows (First Matrix): ";
		cin >> row;
		cout << "Enter The Number Of Cols (First Matrix): ";
		cin >> col;

		cout << "Enter First Matrix !! \n";
		Matrix m1(row, col);
		cin >> m1;
		cout << m1;


		cout << "Enter The Number Of Rows (Second Matrix): ";
		cin >> row;
		cout << "Enter The Number Of Cols (Second Matrix): ";
		cin >> col;

		cout << "Enter Second Matrix !! \n";
		Matrix m2(row, col);
		cin >> m2;
		cout << m2;

		cout << "The Multiplication Of The Matrices !! \n";
		m1 * m2;

	}
	else if (num == 4)
	{
		cout << "Welcome To Transpose  Matrix !!" << endl;
		cout << "\t---------------" << endl;

		cout << "Enter The Number Of Rows: ";
		cin >> row;
		cout << "Enter The Number Of Cols: ";
		cin >> col;

		cout << "Enter First Matrix !! \n";
		Matrix m1(row, col);
		cin >> m1;
		cout << m1;

		m1.transpose();

	}
	system("pause");
	return 0;
}

