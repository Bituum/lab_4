#include <iostream>
#include "matrix.hpp"
 
Matrix::Matrix(int number)
{
    dimension = number;
    elements = new int*[number];
    for (int i =0; i < number; i++)
    {
        elements[i] = new int[number];
    }
    for (int i =0; i < dimension; i++)
    {
        for (int j =0; i < dimension; i++)
            {
                elements[i][j] = 0;
            }
    }

};

Matrix::Matrix(const  Matrix &m)
{
    dimension = m.dimension;
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; i < dimension; j++)
        {
            elements[i][j] = m.elements[i][j];
        }
    }
};

std::istream& operator>> (std::istream &in, const Matrix &m)
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
            out << m.elements[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
};


Matrix operator+ (const Matrix &x, const Matrix &y)
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