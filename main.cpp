#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"

struct Node *head = NULL;

void displayOptions();
void readFile(std::string);

int main() {
    readFile("books.txt");
    int choice;
    std::string bookSearch, bookTitle, bookAuthor, fileName;
    int bookIsbn, bookQuantity;

    while(true){
        displayOptions();
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
                break;
            case 5:
                std::cout << "Enter file name: \n";
                std::cin.ignore();
                std::getline(std::cin, fileName);

                readFile(fileName);
                break;
            case 0:
                return true;
            default:
                std::cout << "Invalid Choice";
        }
    }
}

void displayOptions() {
    std::cout << "Press 1 to View Books\n";
    std::cout << "Press 2 to Search Book [By Full Title]\n";
    std::cout << "Press 3 to Add Book\n";
    std::cout << "Press 4 to Remove a Book\n";
    std::cout << "Press 5 to Read new Books from Different File\n";
    std::cout << "Press 0 to Exit the Program\n";
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
