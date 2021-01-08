#include "Matrix.h"
#include <cstddef>
#include <iostream>
#include <opencv2/core/cvdef.h>
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
	for (int i = 0; i < rN * cN; i++) data[i] = 0.0f;
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
	
	float t1 = 0, t2 = 0, t3 = 0;
	for (int i = 0; i < rowN; i += h) {
		for (int j = 0; j < colN; j += w) {
			
			t1 = MAX(getD(i, j),getD(i,j+1));
			t2 = MAX(getD(i+1,j),getD(i+1,j+1));
			t3 = MAX(t1,t2);

			a.setD(i/h+1,j/w+1,t3);
		}
	}
	
	float* trans = data;
	rowN = a.rowN;
	colN = a.colN;
	data = a.data;
	a.data = trans;
}
