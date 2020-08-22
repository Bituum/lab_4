#include "library.hpp"
#include <istream>


Library *Library::pbeg = nullptr;
Library *Library::pend = nullptr;

Library::Library ()
    : id(0),
    name("unknown"),
    secname("unknown"),
    year(0),
    sum(0),
    title("unknown"),
    next(nullptr),
    prev(nullptr)
    {
        std::cout << "yey";
        if(!pbeg)
        {
            pend = pbeg = nullptr;
        }
        else
        {
            this->id = pend->id + 1;
            this->prev = pend;
            this->next = this;
            pend = this;
        }
    }
    
void Library::add()
{
    std::cout << "1";
    Library *top = new Library;
    while(top->next != nullptr)
    {
        top = top->next;
    }

    Library *lib = new Library;
    lib->next = nullptr;
    lib->prev = top;
    std::cout << "2";
}

std::istream& operator>>(std::istream&, Library*)
{
    
}

