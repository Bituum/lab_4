#include <iostream>
#include "matrix.hpp"





int main(int argc, char const *argv[])
{
    Matrix A{3};

    std::cin >> A;
    
    Matrix B{3};
    std::cout <<"\n";
    std::cin >> B;

    Matrix C{3};
    C = (A - B) * ((A*A) + B);
    C *=2;
    
    
    
    
    std::cout << C << "\n";
    std::cout << "YES";
        
    return 0;
}