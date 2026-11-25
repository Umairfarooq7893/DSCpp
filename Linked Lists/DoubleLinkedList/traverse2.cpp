#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
int main() {
    Node* head = new Node();
    Node* second = new Node();

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = NULL;

    Node* temp = head;
    cout << "Forward traverse:\nNULL -> ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";


    temp = head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    cout << "Backward traverse:\nNULL -> ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;             
    }
    cout << "NULL\n";

    return 0;
}