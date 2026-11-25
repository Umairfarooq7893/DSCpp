#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
class CQ{
    node* rear;
public:
    CQ(){
        rear = NULL;
    }
    void enqueue(int x){
        node* temp = new node(x);

        if(rear == NULL){
            temp->next = temp;
            rear = temp;
        }else{
            temp->next = rear->next;
            rear->next = temp;
            rear = temp;
        }
        cout<<x<<" enqueued\n";
    }
    void dequeue(){
        if (rear == NULL){
            cout<<"Queue underflow\n";
            return;
        }
        node* front = rear->next;
        if(rear == front){
            cout<< front->data<< " deleted\n";
            delete front;
            rear = NULL;
        }else{
            rear->next = front->next;
            cout<< front->data<< " deleted\n";
            delete front;
        }

    }
    void display(){
        if(rear == NULL){
            cout<<"Queue is empty \n";
            return;
        }
        node* temp = rear->next;
        cout<<"Queue ";
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=rear->next);
        cout<<endl;
    }
};
int  main(){
    CQ q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();
    return 0;


}