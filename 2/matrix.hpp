#pragma once

class Matrix
{
    protected:
    int dimension;
    int **elements;

    public:
    
    Matrix(int number = 1);
    Matrix(const Matrix &m);
    ~Matrix();
   
    friend std::istream& operator>> (std::istream &in, Matrix &m);
    friend std::ostream& operator<< (std::ostream &out, const Matrix &m);
    friend Matrix operator+ (const Matrix x, const Matrix y);
    friend Matrix operator- (const Matrix x, const Matrix y);
    friend Matrix operator* (const Matrix x, const Matrix y);
    Matrix &operator*= (int num);
    Matrix &operator=(const Matrix &m);

    
   

};

