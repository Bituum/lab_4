#include "library.hpp"
#include <iostream>
#include <istream>
#include <string>
#include <algorithm>

int int_check(void)
{
        int tmp;
        while(!(std::cin >> tmp) || tmp <= 0)
        {
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cout << "You should write a natural number! Please, try again!";
           std::cin.ignore(1024, '\n');
           std::cout << "Press enter to continue . . . ";
            std::cin.get();
        } 
       std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               
    return tmp;
}

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
        lib=nullptr;
        delete lib;
        
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
    std::cin.ignore(1);
    std::getline(in,lib->name);
    std::cout << "Enter the author second name " << "\n";
    std::cin.ignore(-1);
    std::getline(in, lib->secname);
    std::cout << "Enter the title " << "\n";
    std::cin.ignore(-1);
    std::getline(in, lib->title);
    std::cout << "Enter the count of this book\n";
    lib->sum = int_check();
    std::cout << "Enter the udk number\n";
    lib->udk = int_check();
    lib->year = int_check(); //dateCheck
    return in;
}

std::ostream& operator<<(std::ostream &out, const Library*lib)
{   out <<
    "Name:       " << lib->name << std::endl
    << "Secname:    " << lib->secname << std::endl
    << "title:      " << lib->title << std::endl
    << "count:      " << lib->sum << std::endl;
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
        std::cout << "\nEnter the title of the book which you wish to take " << std::endl;
        std::string str;
        std::cin >> str;

        Library *lib = pbeg;
        while(lib)
        {
            if(lib->title == str)
            {
                if(lib->sum == 0)
                {
                    std::cout << "There are no book in the library!!";
                }
                else
                {
                lib->sum--;
                std::cout << "You have take 1 book " << std::endl;
                }
            lib = lib->next;
        }   
    }
}
void Library::bringABook()
{
    std::cout << "\nEnter the title of the book which you wish to take " << std::endl;
       std::string str;                                 
       std::cin >> str;                                 
                                                        
       Library *lib = pbeg;                             
       while(lib)                                       
       {                                                
           if(lib->title == str)                        
           {                                            
               lib->sum++;
               std::cout << "You have take 1 book " << std::endl;
                                                          
           }                                              
           lib = lib->next;                               
        }    
}

/*std::istream &operator>>(std::istream &in, std::string &string)
{
    do {
        if (std::any_of(string.begin(), string.end(),
                    [](const auto p) { return isdigit(p); }) ||
        std::all_of(string.begin(), string.end(),
                    [](const auto p) { return (p == ' ' || p == '\t'); }) ||
        string.empty()) {
      std::cerr << "\nНекорректный ввод\n" << std::endl;
      continue;
    }

    for (int i = 0; i < string.size(); i++) {
      if (i == 0 && (string[i] == ' ' || string[i] == '\t')) {
        int count = 0;
        for (int j = i; string[j] == ' ' || string[j] == '\t'; j++)
          count++;
        string.erase(0, count);
        continue;
      }

      int count = 0;
      if ((string[i] == ' ' || string[i] == '\t') &&
          (string[i + 1] == ' ' || string[i + 1] == '\t' || string[i + 1] == '\0')) {
        for (int j = i;
            string[j + 1] == ' ' || string[j + 1] == '\t' || string[j + 1] == '\0'; j++)
          count++;
        string.erase(i, count);
      }
    }

    break;
  }
while (true);
    return in;
}
*/

