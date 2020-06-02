#include <iostream>
#include "matrix.hpp"
#include <cmath>


Matrix::Matrix(int number)
{
    dimension = number;
    elements = new int*[number];
    for(int i =0; i < number; i++) 
    {
        elements[i] = new int[number];
    }
    for(int i =0; i < dimension; i++)
    {
        for (int j =0; i < dimension; i++)
            {
                elements[i][j] = 0;
            }
    }
};

Matrix::Matrix(const Matrix &m)
{   
    Matrix tmp{m.dimension};
    dimension = tmp.dimension;
    elements = tmp.elements;
    tmp.dimension = 0;
    tmp.elements = 0;
    
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            elements[i][j] = m.elements[i][j];
        }
    }
}


std::istream& operator>> (std::istream &in, Matrix &m)
{
    for (int i = 0; i < m.dimension; i++)
    {
        for (int j = 0; j < m.dimension; j++)
        {
            in >> m.elements[i][j];
        }
    }
    return in;
};

std::ostream& operator<< (std::ostream &out, const Matrix &m)
{
    for (int i = 0; i < m.dimension; i++)
    {
        for (int j = 0; j < m.dimension; j++)
        {
            out << std::abs(m.elements[i][j]) << "\t";
        }
        out << std::endl;

    }
    return out;
};


Matrix operator+ (const Matrix x, const Matrix y)
{
    Matrix tmp{x.dimension};
    for(int i = 0; i < x.dimension; i++)
    {
        for(int j = 0; j < x.dimension; j++)
        {
            tmp.elements[i][j] = x.elements[i][j] + y.elements[i][j];
        }
    }
    return tmp;
};

Matrix operator- (const Matrix x, const Matrix y)
{
    Matrix tmp{x.dimension};
    
    for(int i = 0; i < x.dimension; i++)
    {
        for(int j = 0; j < x.dimension; j++)
        {
            tmp.elements[i][j] = x.elements[i][j] - y.elements[i][j];
        }
    }
    return tmp;
};

Matrix operator* (const Matrix x, const Matrix y)
{
    Matrix tmp(x.dimension);
    
    
    for(int i = 0; i < x.dimension; i++)
    {
        for(int j = 0; j < x.dimension; j++)
        {
            
            for(int t = 0; t < x.dimension; t++)
            {
                tmp.elements[i][j] += x.elements[i][t] * y.elements[t][j];
                
            }
        }
    }
    return tmp;
};

Matrix &Matrix::operator*= (int num)
{
    
    //Matrix tmp(dimension);
    //elements = 0;
    for(int i = 0; i < dimension; i++)
    {   
        for(int j = 0; j < dimension; j++)
        {
            elements[i][j] = num * elements[i][j];
        }
    }
    return *this;
};

Matrix::~Matrix()
{

    for(int i = 0; i < dimension; i++)
    {
        delete[] elements[i];
    }
    delete[] elements;
    elements = nullptr;
};

Matrix &Matrix::operator=(const Matrix &m)
{
    
    elements = m.elements;
    elements = new int*[m.dimension];
    for(int i =0; i < dimension; i++) 
    {
        elements[i] = new int[m.dimension];
    }
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            elements[i][j] = m.elements[i][j];
        }
    }
    return *this;

};
