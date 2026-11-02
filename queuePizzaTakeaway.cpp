
#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int front, rear;
    string orders[SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    // Add a new pizza order
    void enqueue() {
        if (isFull()) {
            cout << "Queue is full! Cannot accept more orders.\n";
            return;
        }

        string pizza;
        cout << "Enter pizza order: ";
        cin >> pizza;

        if (front == -1)
            front = 0;

        rear++;
        orders[rear] = pizza;

        cout << "Order accepted successfully!\n";
    }

    // Deliver the first order
    void dequeue() {
        if (isEmpty()) {
            cout << "No pending orders!\n";
            return;
        }

        cout << "Delivering order: " << orders[front] << endl;

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    // Display all waiting orders
    void display() {
        if (isEmpty()) {
            cout << "No waiting orders!\n";
            return;
        }

        cout << "\nWaiting Pizza Orders:\n";

        for (int i = front; i <= rear; i++) {
            cout << orders[i] << endl;
        }
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\n--- PIZZA PARLOUR TAKE-AWAY SYSTEM ---";
        cout << "\n1. Accept New Order";
        cout << "\n2. Deliver Order";
        cout << "\n3. Display Waiting Orders";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                q.enqueue();
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}
