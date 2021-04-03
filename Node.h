#include <iostream>

#ifndef NODE_H
#define NODE_H


struct Node {
    std::string title;
    std::string author;
    int isbn;
    int quantity;
    struct Node *next;
};

void addToNode(struct Node** head, std::string nodeTitle, std::string nodeAuthor, int nodeIsbn, int nodeQuantity);
void searchBook(struct Node* head, std::string searchTitle);
void removeBook(struct Node* head, std::string bookTitle);
void display(struct Node* node);


#endif //NODE_H
