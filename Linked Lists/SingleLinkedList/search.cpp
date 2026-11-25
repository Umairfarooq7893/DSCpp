#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void search(int key){
    Node* temp = head;
    int pos = 1;
    while (temp != NULL){
        if(temp->data == key){
            cout << "Element found at position " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found";
}

int main(){
    head = new Node{10,NULL};
    head->next = new Node{20,NULL};
    head->next->next = new Node{30,NULL};

    search(20);

    return 0;
}