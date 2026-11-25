#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }
    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        // initially both are -1 , so when enqueue is callled front becomes 0 and rear keeps on adding up
        if (front == -1)
            front = 0;

        // Move rear forward and insert element
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {  // always rear >= front
            cout << "Queue Underflow\n";
            return;
        }

        // Print deleted element and move front forward
        cout << "Deleted: " << arr[front++] << endl;
    }

    void display() {

        if (front == -1 || front > rear) {   // always rear >= front
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}