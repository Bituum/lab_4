#include <cstdlib>
#include <iostream>
#include "library.hpp"


/*
*   Составить программу, которая содержит текущую информацию о
*   книгах в библиотеке. Сведения о книгах включают:
*   номер УДК; фамилию и инициалы автора;
*   название; год издания;!
*   количество экземпляров данной книги в библиотеке. Программа
*   должна обеспечивать:
*   начальное формирование данных обо всех книгах в библиотеке в
*   виде списка;
*   при выдаче каждой книги на руки вводится номер УДК, и программа
*   уменьшает значение количества книг на единицу или выдает
*   сообщение о том, что требуемой книги в библиотеке нет или
*   требуемая книга находится на руках;
*   при возвращении каждой книги вводится номер УДК, и программа
*   увеличивает значение количества книг на единицу;
*   по запросу выдаются сведения о наличии книг в библиотеке.
*/

int main()
{
    short int key;
    bool exitkey = true;
    while(exitkey){
    std::cout <<
        "\n Enter the function:\n" << 
        "1.\tAdd new elements..." << std::endl <<
        "2.\tShow information... \n" <<
        "3:\tTake a book... \n" <<
        "4:\tBring a book...\n" <<
        "5:\tExit\n"
        ;
    
        std::cin >> key;
        switch(key)                                          
        {                                                    
            case 1:
                Library::add();
                std::system("clear");
                break;
            case 2:
                Library::showInfo();
                break;
            case 3:
                Library::takeABook();
                break;
            case 4:
                Library::bringABook();
                break;
            case 5:
               exitkey = false;
               break;
            default: std::cout << " error! ";
                break;
        }

    }
   
    return 0;
}
