#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;

};
Node* head = NULL;
    void forwardTraversal(){
        Node*temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            temp = temp -> next;
        }
        cout<<"NULL";
    }
    void backrwardTraversal(){
        Node*temp = head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        while(temp!=NULL){
            cout<< temp->data;
            temp = temp ->prev;
        }
    cout<<"NULL";
    }
int main(){
    head = new Node{10,NULL,NULL};
    head->next = new Node{20,head,NULL};
    head->next->next =new Node{30,head->next,NULL};
    head->next->next->next =new Node{40,head->next->next,NULL};

    forwardTraversal();
    backrwardTraversal();
}