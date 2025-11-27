#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
            head->prev = newNode;

        head = newNode;
        cout << value << " inserted at beginning" << endl;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            cout << value << " inserted at end" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;

        cout << value << " inserted at end" << endl;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        cout << temp->data << " deleted from beginning" << endl;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete" << endl;
            return;
        }

        Node* temp = head;

        if (temp->next == nullptr) {
            cout << temp->data << " deleted from end" << endl;
            delete temp;
            head = nullptr;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << temp->data << " deleted from end" << endl;
        temp->prev->next = nullptr;
        delete temp;
    }

    // Delete by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found" << endl;
            return;
        }

        // Case 1: deleting head
        if (temp == head) {
            deleteFromBeginning();
            return;
        }

        // Case 2: deleting last node
        if (temp->next == nullptr) {
            deleteFromEnd();
            return;
        }

        // Case 3: deleting middle node
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        cout << value << " deleted from list" << endl;
        delete temp;
    }

    // Display forward traversal
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "List (forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display backward traversal
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "List (backward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.displayForward();
    list.displayBackward();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.displayForward();

    list.deleteByValue(30);
    list.displayForward();

    return 0;
}
