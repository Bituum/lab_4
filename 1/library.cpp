#include "library.hpp"
#include <cstdlib>
#include <iostream>
#include <istream>
#include <iterator>
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

int date_check()
{
    int tmp = int_check();
    bool trigger = true;
    do {
        if(tmp < 1300 || tmp > 2020)
        {
            std::system("clear");
            std::cout << "\n\tIncorect date!\n";
            break;
        }
        else
        {
            trigger = false;
        }
    }while (trigger);
    return tmp;
}

/*std::string word_check(std::string string)
{
    std::string str;
    int counter = 0;
    str = string;

    for(int i = 0; i < str.size(); i++)
    {
        if((str[i] == ' ' ||  str[i] == '\t') && (str[i+1] == ' ' || str[i+1] == '\t'))
        {
            counter++;                                                                                                                   
            str.erase(i, counter);
            str[i] = '\0';
        }
    }
            
    return str; 
}*/

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
    //std::string tmpstr;
    std::cout << "Enter the author name " <<"\n";
    std::cin.ignore(1);
    getline(in, lib->name);
    std::cout << "Enter the author second name " << "\n";
    std::cin.ignore(-1);
    std::getline(in, lib->secname);
    std::cout << "Enter the title " << "\n";
    std::cin.ignore(-1);
    std::getline(in, lib->title);
    std::cout << "Enter the count of this book\n";
    lib->sum = int_check();
    std::cout << "Enter udk number\n";
    lib->udk = int_check();
    std::cout << "Enter the year of publishing\n";
    lib->year = date_check();
    return in;
}

std::ostream& operator<<(std::ostream &out, const Library*lib)
{   out <<
    "Name:       " << lib->name << std::endl
    << "Secname:    " << lib->secname << std::endl
    << "title:      " << lib->title << std::endl
    << "count:      " << lib->sum << std::endl
    << "udk:        " << lib->udk << std::endl
    << "year:       " <<lib->year << std::endl;
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
    std::cout << "\n";
}


bool operator==(const Library &first, const Library &second)
{
    return(first.name == second.name && first.secname == second.secname && first.title == second.title && first.udk == second.udk
          && first.year == second.year);
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
                    std::cout << "There are no book in the library!!\n";
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


