#include "Matrix.h"

Matrix::Matrix(int r, int c)
{
	row = r;
	col = c;
	mtrx = new int*[row];
	for (int i = 0; i < row; i++){
		mtrx[i] = new int[col];
	}
}

istream& operator>>(istream& input,const Matrix& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			input >> mat.mtrx[i][j];
		}
	}

	return input;
}

ostream& operator<<(ostream& out, const Matrix& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			out << mat.mtrx[i][j] <<'\t';
		}
		out << endl;
	}

	return out;
}

void Matrix::operator+(const Matrix& matrix)
{
	if (row != matrix.row || col != matrix.col)
	{
		cout << "Addition not complate !!" << endl;
	}
	else
	{

		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				cout << mtrx[i][j] + matrix.mtrx[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
void Matrix::operator-(const Matrix& matrix)
{
	if (row != matrix.row || col != matrix.col)
	{
		cout << "Subtraction not complate !!" << endl;
	}
	else
	{
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				cout << mtrx[i][j] - matrix.mtrx[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
void Matrix::operator*(const Matrix& matrix)
{
	if (col != matrix.row)
	{
		cout << "Multiplication not complate !! " << endl;
	}
	else
	{
		//dynamic alocation for the multiplication matrix
		int **multi = new int*[col];
		for (int i = 0; i < col; i++){
			multi[i] = new int[matrix.row];
		}

		//calculation here
		for (int i = 0; i < row; i++){
			for (int j = 0; j < matrix.col; j++){
				multi[i][j] = 0;
				for (int k = 0; k < col; ++k)
				{
					multi[i][j] += mtrx[i][k] * matrix.mtrx[k][j];
				}
			}
		}

		//for print matrix 
		for (int i = 0; i < row; i++){
			for (int j = 0; j < matrix.col; j++){
				cout << multi[i][j] << "\t";
			}
			cout << endl;
		}

		//for Destroy matrix
		/*for (int i = 0; i < row; i++){
			delete[] multi[i];
		}
		delete[] multi;*/
	}
}
void Matrix::transpose()
{
	//dynamic alocation for the multiplication matrix
	int **trans = new int*[col];
	for (int i = 0; i < col; i++){
		trans[i] = new int[row];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			trans[j][i] = mtrx[i][j];
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << trans[i][j] << '\t';
		}
		cout << endl;
	}

	//for Destroy matrix
	for (int i = 0; i < col; i++){
		delete[] trans[i];
	}
	delete[] trans;
}


Matrix::~Matrix()
{
	for (int i = 0; i < row; i++){
		delete[] mtrx[i];
	}
	delete[] mtrx;
}
