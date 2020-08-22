#include "library.hpp"


Library *Library::pbeg = nullptr;
Library *Library::pend = nullptr;

Library::Library ()
    : id(0),
    name("unknown"),
    secname("unknown"),
    //year(0),
    //sum(0),
    title("unknown"),
    next(nullptr),
    prev(nullptr)
    {

    if(!pbeg)
    pend = pbeg = this;

    else 
    {
    this->id = pend->id + 1;
    this->prev = pend;
    pend->next = this;
    pend = this;
  }
}

//void intA    


void Library::add() {
  Library *lib = new Library;
  std::cin >> lib;

  if(pbeg != pend) {
    Library *tmp = pbeg;

    while(tmp != pend) {
      if(*tmp == *lib) {
        delete lib;
        lib = nullptr;

        std::cout << "You already added this!"<< std::endl;
        return;
      }

      tmp = tmp->next;
    }
  }
}
std::istream& operator>>(std::istream &in,Library *lib)
{
    std::cout << "Enter the author name " <<"\n";
    in >> lib->name;
    std::cout << "Enter the author second name " << "\n";
    in >> lib->secname;
    std::cout << "Enter the title " << "\n";
    in >> lib->title;
    std::cout << "Enter the count of this book";
    in >> lib->sum;
    return in;
}

std::ostream& operator<<(std::ostream &out, const Library*lib)
{   out <<
    "Name:    " << lib->name << std::endl
    << "Secname:    " << lib->secname << std::endl
    << "title:    " << lib->title << std::endl
    << "count:    " << lib->sum;
    return out;
}

void Library::showInfo()
{ 
    if(!pbeg)
    {
        std::cout << "List is Empty!    ";
    }
    Library *tmp = pbeg;
    while(tmp != nullptr)
    {
        std::cout << tmp;
        tmp = tmp->next;
    }
}


bool operator==(const Library &first, const Library &second)
{
    return(first.name == second.name && first.secname == second.secname && first.title == second.title);
}


Library::~Library() {
  Library *p = this->next;

  while(p) {
    p->id--;
    p = p->next;
  }

  if(this == pbeg) {
    pbeg = pbeg->next;

    if(pbeg)
      pbeg->prev = nullptr;
  }

  else if(this == pend) {
    pend = pend->prev;
    pend->next = nullptr;
  }

  else {
    (this->prev)->next = this->next;
    (this->next)->prev = this->prev;
  }
}

void Library::takeABook()
{
    Library *search = pbeg;                                                                                                         
    Library *tmp;
    std::cout << "\nEnter the title of the book which you wish to take " << std::endl;
    std::cin >> tmp->title;
    if(!pbeg)
    {
        std::cout << "List is Empty";
    }
    
    while(search != nullptr)
    {
        if(tmp->title == search->title)
        {
            search->sum--;

            return;
        }
        search = search->next;
    }
}

//TODO take and bring!
