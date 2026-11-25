#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};
Node*head = NULL; 
// Traversal fxn
void display(){
    Node* temp = head; 
    while(temp != NULL){ 
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
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
    head = new Node{1,NULL};
    head->next = new Node{2,NULL};
    head->next->next = new Node{3,NULL};
    head->next->next->next = new Node{4,NULL};
    head->next->next->next->next = new Node{5,NULL};

    display();
    search(4);
}