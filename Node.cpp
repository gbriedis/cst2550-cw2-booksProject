#include "Node.h"

#include <utility>

void addToNode(struct Node** head, std::string nodeTitle, std::string nodeAuthor, int nodeIsbn, int nodeQuantity){
    struct Node* newNode = new Node;
    struct Node* lastNode = *head;

    newNode->title = nodeTitle;
    newNode->author = nodeAuthor;
    newNode->isbn = nodeIsbn;
    newNode->quantity = nodeQuantity;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    while (lastNode->next != nullptr)
        lastNode = lastNode->next;
    lastNode->next = newNode;

    if(newNode->title == nodeTitle){
        std::cout << "Added Book Title: [" << newNode->title << "] Book Author: [" << newNode->author << "] Book ISBN: [" << newNode->isbn << "] Book Quantity: [" << newNode->quantity << "]\n";
    }
}

void searchBook(struct Node* head, std::string searchTitle) {
    Node* current = head;
    while(current != nullptr){
        if(current->title == searchTitle) {
            std::cout<< "Title: [" <<current->title << "] Author: [" << current->author << "] ISBN: ["<< current->isbn << "] Quantity: [" << current->quantity<<"]\n";
            return;
        }
        current = current->next;

    }
    std::cout << searchTitle << " was not found in the list.\n";
}

void removeBook(struct Node* head, std::string bookTitle) {
    Node* previousHead = head;
    Node* currentHead = head->next;
    while(currentHead != nullptr){
        if(currentHead->title == bookTitle){
            break;
        }
        currentHead = currentHead->next;
    }
    if(currentHead == nullptr){
        std::cout << "Couldn't find the Book Title\nFailed to Delete the Book\n";
    }
    else {
        std::cout << "Deleting: " << currentHead->title << "\n";
        previousHead->next = currentHead->next;
        delete currentHead;
        return;
    }
}

void display(struct Node* node){
    while (node != nullptr){
        std::cout<< "Title: [" <<node->title << "] Author: [" << node->author << "] ISBN: ["<< node->isbn << "] Quantity: [" << node->quantity<<"]\n";
        node = node->next;
    }
}