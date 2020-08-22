#pragma once
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
        
        //static roots for list
        static Library *pbeg;
        static Library *pend;


    public:
        Library();
        ~Library();        
        static void add();        
        static void take();
        static void showInfo();
        static void takeABook();
        friend std::istream &operator>> (std::istream &in, Library *lib);
        friend std::ostream &operator<< (std::ostream&, const Library *lib);
        friend bool operator==(const Library &first, const Library &second);
};
