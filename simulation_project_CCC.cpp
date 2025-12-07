#include<iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "\nQueue is FULL! Customer cannot join.\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = x;
        cout << "Customer " << x << " joined the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY! No customer to serve.\n";
            return;
        }

        int served = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        cout << "Customer " << served << " bought ticket and left the queue.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY!\n";
            return;
        }

        cout << "\nCurrent Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, id;

    cout << "=== Movie Ticket Counter Simulation ===\n";

    while (true) {
        cout << "\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer ID: ";
            cin >> id;
            q.enqueue(id);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "\nExiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
