#include <iostream>
using namespace std;
// Node structure for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};
// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
public:
    // Constructor: initialize head to nullptr
    DoublyLinkedList() : head(NULL) {}
    // Insert a new node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL)
        {   // Move head to new node
        	head = newNode;
		}
		else
		{  // If list is not empty, update previous head's prev pointer
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

    // Insert a new node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    // Insert a new node at a specific position (1-indexed)
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
        newNode->data = value;    // Class version initializes automatically via constructor
        Node* temp = head;
        // Traverse to the node before the desired position
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    // Delete the first node of the list
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }

    // Delete the last node of the list
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) { // Only one node in the list
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    // Delete a node at a specific position (1-indexed)
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        // Traverse to the node at the specified position
        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range." << endl;
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        delete temp;
    }

    // Display the list from beginning to end
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display the list from end to beginning
    void displayBackward() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Traverse backward using prev pointers
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Insertion examples:
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtPosition(15, 3); // Insert 15 at position 3

    cout << "Doubly Linked List (Forward): ";
    dll.displayForward();
    cout << "Doubly Linked List (Backward): ";
    dll.displayBackward();

    // Deletion examples:
    dll.deleteFromBeginning();
    cout << "After deleting from beginning (Forward): ";
    dll.displayForward();

    dll.deleteFromEnd();
    cout << "After deleting from end (Forward): ";
    dll.displayForward();

    dll.insertAtEnd(25); // Adding nodes to test deletion from a specific position
    dll.insertAtEnd(30);
    dll.deleteFromPosition(2);
    cout << "After deleting from position 2 (Forward): ";
    dll.displayForward();

    return 0;
}

