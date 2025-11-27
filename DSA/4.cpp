#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value)
    {
        if ((rear + 1) % SIZE == front)
        {
            cout << "Queue Overflow! Cannot insert" << endl;
            return;
        }

        if (front == -1)
        { // queue empty
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = value;
        cout << value << " inserted into the queue" << endl;
    }

    // Dequeue operation
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow! Cannot delete" << endl;
            return;
        }

        cout << arr[front] << " deleted" << endl;

        if (front == rear)
        {
            front = rear = -1; // queue becomes empty
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    // Display queue elements
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Driver code
int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
