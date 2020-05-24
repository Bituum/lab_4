#pragma once

class Matrix
{
    protected:
    int dimension;
    int **elements;

    public:
    Matrix(int num = 1);
    Matrix(const Matrix *m);
   
    friend std::istream& operator>> (std::istream &in, const Matrix &m);
    friend std::ostream& operator<< (std::ostream &out, const Matrix &m);
    friend Matrix operator+ (const Matrix &x, const Matrix &y);
    friend Matrix operator- (const Matrix &x, const Matrix &y);
};

