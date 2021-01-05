#pragma once

class Matrix
{
private:
	int rowN;
	int colN;
	float* data;

public:
	Matrix();
	Matrix(int rN, int cN);
  
	~Matrix();
  
	int getRowN() const;
	int getColN() const;
	float getD(int i,int j) const;
	void setD(int i, int j, float c);
	void MaxPoolAdd0(int w,int h);//w:宽(x) h:高(y)

};
