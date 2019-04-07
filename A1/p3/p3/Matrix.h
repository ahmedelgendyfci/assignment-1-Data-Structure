#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
public:
	Matrix(int, int);
	~Matrix();

	friend istream& operator>>(istream&, const Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
	void operator+(const Matrix&);
	void operator-(const Matrix&);
	void operator*(const Matrix&);
	void transpose();
private:
	int row;
	int col;
	int **mtrx;
};

