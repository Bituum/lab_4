#include "library.hpp"


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
        if(!pbeg)
        {
            pend = pbeg =nullptr;
        }
        else
        {
            this->id = pend->id + 1;
            this->prev = pend;
            this->next = this;
            pend = this;
        }
    }
    

