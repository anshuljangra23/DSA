#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // INSERT AT BEGINNING
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cout << value << " inserted at beginning\n";
    }

    // INSERT AT END (O(1))
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << value << " inserted at end\n";
    }

    // INSERT AT POSITION
    void insertAtPosition(int value, int pos)
    {
        if (pos == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node(value);
        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail)
        {
            tail = newNode;
        }

        cout << value << " inserted at position " << pos << endl;
    }

    // DELETE AT BEGINNING
    void deleteAtBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;

        cout << temp->data << " deleted from beginning\n";
        delete temp;
    }

    // DELETE AT END
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head == tail)
        {
            cout << head->data << " deleted\n";
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        cout << tail->data << " deleted from end\n";
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // DELETE AT POSITION
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1)
        {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;

        if (del == tail)
            tail = temp;

        cout << del->data << " deleted from position " << pos << endl;
        delete del;
    }

    // DISPLAY LIST
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2);

    list.display();

    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteAtPosition(2);

    list.display();

    return 0;
}