#include <iostream>
using namespace std;

struct Node {

    int data;      // Stores queue data
    Node* next;    // Pointer to next node

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularQueue {
    Node* rear;
// front can be accessed using: rear->next

public:
    CircularQueue() {
        rear = NULL;
    }
    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == NULL) {
            temp->next = temp;
            rear = temp;
        }
        else {
            temp->next = rear->next;
            rear->next = temp;
            rear = temp;
        }
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (rear == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }

        Node* front = rear->next;

        // If only one node exists
        if (rear == front) {
            cout << front->data << " dequeued\n";
            delete front;
            rear = NULL;
        }
        else {
            // rear skips first node 
            rear->next = front->next;

            cout << front->data << " dequeued\n";
            delete front;
        }
    }


    void peek() {
        if (rear == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << rear->next->data << endl;
    }

    // DISPLAY OPERATION
    void display() {

        if (rear == NULL) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = rear->next;

        cout << "Queue: ";
        do {
            cout << temp->data << " ";

            temp = temp->next;
        } while (temp != rear->next);

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.peek();

    return 0;
}