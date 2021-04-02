#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Book.h"
#include "Collection.h"

void outputChoice() {
    std::cout << "Press 1 to see all the books\n";
    std::cout << "Press 2 to see Search Book by its Title\n";
    std::cout << "Press 3 to Add/Remove Book\n";
    std::cout << "Press 4 to Load new data from different text file\n";
    std::cout << "Press 0 to Exit the program\n";
}

int main() {

    // read book from file
    std::ifstream file("books.txt");

    std::string line;
    std::string title, author, isbn, quantity;
    int isbnInt, quantityInt;

    Book book;
    Collection collection;

    if(file.is_open()) {
        while(std::getline(file, line)){

            std::stringstream ss(line);

            getline(ss, title, '\t');
            getline(ss, author, '\t');
            getline(ss, isbn, '\t');
            getline(ss, quantity, '\t');

            isbnInt = stol(isbn);
            quantityInt = stol(quantity);

            book.setTitle(title);
            book.setAuthor(author);
            book.setIsbn(isbnInt);
            book.setQuantity(quantityInt);
            collection.add(Book(title, author, isbnInt, quantityInt));
        }
    }
    else {std::cout << "Failed opening a file";}
    file.close();


    while(true){
        outputChoice();
        int choice;
        std::string bookSearch;
        std::cin >> choice;

        switch(choice) {
            case 1:
                collection.output();
                break;
            case 2:
                std::cout << "Enter a book you'd like to search\n";
                std::cin.ignore();
                std::getline(std::cin, bookSearch);
                std::cout << collection.find(bookSearch);
                break;
            case 3:
                std::cout << "Enter ";

            case 0:
                return 0;
            default:
                std::cout << "Invalid choice\n";
                break;
        }


    }
    return 0;
}
