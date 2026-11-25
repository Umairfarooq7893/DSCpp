#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node*head = NULL;

void deleteBeg(){
    if(head == NULL){
    cout<<"List is Empty";
    return;
    }


    Node* temp = head;  
    head = head->next;  
    delete temp;      
}
void deleteEnd(){
    if(head == NULL){
        cout<<"list is empty";
    return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;  // update head with NULL
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next; 
    }
    delete temp->next; 
    temp->next = NULL; 
}
void deletePos(int pos){
    if(pos == 1){
        deleteBeg();
        return;
    }
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    //otherwise
    Node* temp = head; // list starts
    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){  // bez temp must exist
        cout << "Invalid position";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next; 
    delete del;
}

void display(){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){

    head = new Node{1,NULL};
    head->next = new Node{2,NULL};
    head->next->next = new Node{3,NULL};
    head->next->next->next = new Node{4,NULL};
    head->next->next->next->next = new Node{5,NULL};
    deleteBeg();
    deletePos(2);
    deleteEnd();

    display();
    return 0;
}