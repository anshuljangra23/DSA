#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isempty() {
        return top == -1;
    }

    // Check if stack is full
    bool isfull() {
        return top == MAX - 1;
    }

    // Push operation
    void push(int x) {
        if (isfull()) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into the stack" << endl;
        }
    }

    // Pop operation
    void pop() {
        if (isempty()) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << arr[top] << " popped from the stack" << endl;
            top--;
        }
    }

    // Peek operation
    void peek() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element of the stack is " << arr[top] << endl;
        }
    }

    // Display all elements
    void display() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack Elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();

    st.pop();
    st.pop();

    st.peek();

    return 0;
}
