#include <iostream>
#include <fstream>

class Books {
   std::string title;
   std::string author;
   std::string ISBN;
   std::string qtyAvailable;

public:
    Books(std::string title, std::string author, std::string ISBN, std::string qtyAvailable) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->qtyAvailable = qtyAvailable;
    }
};

void readBooks(std::string fileName) {
    std::ifstream file(fileName);

    if(file.is_open()) {
        int count = 0;

        while(1){
            std::string title, author, isbn, quantity;

            
            getline(file, title);
            getline(file, author);
            getline(file, isbn);
            getline(file, quantity);

            
            
            Books books = *new Books(title, author, isbn, quantity);
            count++;

            if(file.eof()) {

                return;
            }
        }

    }
    else {
        std::cout << "Failed opening a file";
    }
    file.close();
    return;
}

int main() {

    readBooks("books.txt");


    return 0;

}
