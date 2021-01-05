#include "Matrix.h"
#include <cstddef>
#include <iostream>
using namespace std;

Matrix::Matrix() {
	rowN = 0;
	colN = 0;
	data = new float [1];
	data[0] = 0.0f;
}

Matrix::Matrix(int rN, int cN) {
	rowN = rN;
	colN = cN;
	data = new float [rN * cN];
}

Matrix::~Matrix() {
	if(NULL!=data)
	    delete[] data;
}

int Matrix::getRowN()  const {
	return rowN;
}
int Matrix::getColN()  const {
	return colN;
}

float Matrix::getD(int i,int j) const {
	if (i < rowN && j < colN)
		return data[colN * i + j];
	else
		return 0;
}

void Matrix::setD(int i,int j,float c) {
	if(i<rowN && j <colN)
	    data[colN * i + j] = c;
}

void Matrix::MaxPoolAdd0(int w,int h) {//w:宽(x) h:高(y)
	int row = rowN / h;
	int col = colN / w;
	Matrix a = Matrix(row+2,col+2);
	for (int j = 0; j < col + 2; j++) {
		a.setD(j, 0, 0);
		a.setD(j, col + 1, 0);
	}
	for (int j = 0; j < row + 2; j++) {
		a.setD(0, j, 0);
		a.setD(row + 1, j, 0);
	}

	for (int i = 0; i < rowN; i += h) {
		for (int j = 0; j < colN; j += w) {
			
			float c = getD(i, j);
			if (getD(i, j+1) > c) c = getD(i, j+1);
			if (getD(i+1, j) > c) c = getD(i+1, j);
			if (getD(i+1, j+1) > c) c = getD(i+1, j+1);

			a.setD(i/h+1,j/w+1,c);

		}
	}
	
	rowN = a.rowN;
	colN = a.colN;
	data = a.data;
	a.data = NULL;
}
