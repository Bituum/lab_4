#include <iostream>
#include <string>



class Library
{
    private:
        //static int amount;
        int id;
        int udk;
        std::string name;
        std::string secname;
        int year;                  
        std::string title;
        Library *next;
        Library *prev;
        int sum;

        static Library *pbeg;
        static Library *pend;


    public:
        Library();
        ~Library();
};
