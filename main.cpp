#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Book.h"
#include "Collection.h"

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



    return 0;
}
