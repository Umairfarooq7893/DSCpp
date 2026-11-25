// implementationg queue using libaray
#include <iostream>
#include <queue>   // queue library
using namespace std;

int main() {
    queue<int> q;   // create queue

    // ENQUEUE (insert elements)
    q.push(10);
    q.push(20);
    q.push(30);

    // FRONT (first element)
    cout << "Front element: " << q.front() << endl;

    // REAR (last element)
    cout << "Rear element: " << q.back() << endl;

    // DEQUEUE (remove element)
    q.pop();

    cout << "Front after dequeue: " << q.front() << endl;

    // CHECK EMPTY
    if (q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    // SIZE of queue
    cout << "Size of queue: " << q.size() << endl;

    return 0;
}