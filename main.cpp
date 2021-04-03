#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"

struct Node *head = NULL;

void readFile(std::string);

int main() {
    readFile("books.txt");

    while(true){
        int choice;
        std::string bookSearch, bookTitle, bookAuthor;
        int bookIsbn, bookQuantity;

        std::cin >> choice;
        switch(choice) {
            case 1:
                display(head);
                break;
            case 2:
                std::cout << "Enter Title of the Book\n";
                std::cin.ignore();
                std::getline(std::cin, bookSearch);
                searchBook(head, bookSearch);
                break;
            case 3:
                std::cout << "Add Book to Database\nEnter Book Title: \n";
                std::cin.ignore();
                std::getline(std::cin, bookTitle);
                std::cout << "Enter Book Author: \n";
                std::getline(std::cin, bookAuthor);
                std::cout << "Enter Book ISBN: \n";
                std::cin >> bookIsbn;
                std::cout << "Enter Book Quantity: \n";
                std::cin >> bookQuantity;

                addToNode(&head, bookTitle, bookAuthor, bookIsbn, bookQuantity);
                break;
            case 4:
                std::cout << "Remove Book from Database\nEnter Book Title:\n";
                std::cin.ignore();
                std::getline(std::cin, bookTitle);
                removeBook(head, bookTitle);
            case 0:
                return true;
            default:
                std::cout << "Invalid Choice";
        }
    }
    return 0;
}

void readFile(std::string fileName) {

    std::ifstream file(fileName);

    std::string line;
    std::string title, author, isbn, quantity;
    int isbnInt, quantityInt;


    if(file.is_open()) {
        while(std::getline(file, line)){

            std::stringstream ss(line);

            getline(ss, title, '\t');
            getline(ss, author, '\t');
            getline(ss, isbn, '\t');
            getline(ss, quantity, '\t');

            isbnInt = stol(isbn);
            quantityInt = stol(quantity);

            addToNode(&head, title, author, isbnInt, quantityInt);

        }
    }
    else {std::cout << "Failed opening a file";}
    file.close();

}
