#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void deletebeg(){
    if (head == NULL){
        cout<<"list is empty";
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd(){
    if(head == NULL){
        cout<<"List is empty";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node*temp = head;
    while(temp->next->next!=NULL){
        temp = temp-> next;
    }
    delete temp->next;
    temp->next = NULL;
}
void deletePos(int pos){
    if(head==NULL){
    cout<<"List is empty";
    return;
    }
    if(pos == 1){
        deletebeg();
        return;
    }
    Node*temp = head;
    for(int i =0; i<pos -1 && temp !=NULL;i++){
        temp =temp->next;
    }
    if (temp == NULL || temp -> next == NULL){
        cout<<"Invalid position";
        return;
    }

    Node * dell = temp -> next;
    temp->next = dell;
    delete ndel
    


}
int main(){

}
int main(){
    head = new Node{1,NULL};
    head->next = new Node{2,NULL};
    head->next->next = new Node{3,NULL};
    head->next->next->next = new Node{4,NULL};
    head->next->next->next->next = new Node{5,NULL};

    deletebeg();
    deleteEnd();
    deletePos(4);
}