#include <iostream>
#include "matrix.hpp"



int main(int argc, char const *argv[])
{std::cout << "parametr_start" << std::endl;
    Matrix A{3};

    std::cin >> A;
    
    //Matrix B{3};
   
    //std::cin >> B;

    Matrix C{3};
    
    
    C = A*2;
    std::cout << C << "\n";
    std::cout << "YES";
        
    return 0;
}