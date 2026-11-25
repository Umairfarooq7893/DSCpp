#include <iostream>
using namespace std;
// Structure for a node in the circular linked list
struct Node {
    int data;
    Node* next;
};
// Define the Circular Linked List class
class CircularLinkedList {
    Node* head;
public:
    // Constructor initializes head to NULL
    CircularLinkedList() : head(NULL) {}
    // Function to insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    // Function to insert a node at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head && position > 2) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        delete temp;
    }
    // Function to delete a node from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
    // Function to delete a node at a specific position
    void deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        
        for (int i = 1; i < position && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == head && position > 1) {
            cout << "Position out of range." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
    // Function to display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};
// Main function
int main() {
    CircularLinkedList list1;
    // Insert elements at the end
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    // Insert element at the beginning
    list1.insertAtBeginning(5);
    // Insert element at a specific position
    list1.insertAtPosition(15, 3);
    cout << "Circular Linked List after insertions: ";
    list1.display();
    // Delete element from the beginning
    list1.deleteFromBeginning();
    cout << "Circular Linked List after deleting from beginning: ";
    list1.display();
    // Delete element from the end
    list1.deleteFromEnd();
    cout << "Circular Linked List after deleting from end: ";
    list1.display();
    // Delete element from a specific position
    list1.deleteFromPosition(2);
    cout << "Circular Linked List after deleting from position 2: ";
    list1.display();
    return 0;
}
