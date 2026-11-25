#include <iostream>
using namespace std;

struct Node{
    int data;     
    Node* next;   
};

Node* head = NULL; 

// Insert at beginning
void insertBeg(int val){
    Node* newNode = new Node(); 
    newNode->data = val;        
    newNode->next = head;       
    head = newNode;            
}
// Insert at end
void insertEnd(int val){
    Node* newNode = new Node(); 
    newNode->data = val;        
    newNode->next = NULL;      

    if(head == NULL){
        head = newNode;        
    }else{
        Node* temp = head;      

        while(temp->next != NULL){  
            temp = temp->next;     
       
        }
        temp->next = newNode;  
    }
}


void insertPos(int val, int pos){
    Node* newNode = new Node(); 
    newNode->data = val;   

    if(pos == 1){
        insertBeg(val);
        return;
    }
 
    Node* temp = head; 

    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next; 
    }

    if(temp == NULL){
        cout << "Invalid position" << endl;
        return;
    }
    newNode->next = temp->next; 
    temp->next = newNode;   
}
// Display list
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    head = new Node{2,NULL};
    head->next = new Node{3,NULL};
    head->next->next= new Node{4,NULL};
    insertBeg(1);
    insertPos(5, 5);

    cout << "Linked List: ";
    display();

    return 0;
}