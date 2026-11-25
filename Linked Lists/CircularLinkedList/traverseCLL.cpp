#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void display() {
    if (head == NULL) {  
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "head";
}

int main() {
 
    head = new Node{10, NULL};

    head->next = new Node{20, NULL};           // second node
    head->next->next = new Node{30, NULL};     // third node

    head->next->next->next = head;             // make circular

    display();

    return 0;
}