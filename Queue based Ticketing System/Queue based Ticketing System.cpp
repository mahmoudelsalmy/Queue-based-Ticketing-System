/*
------------------------------------------------------------
    Project: Queue Based Ticketing System
    Data Structure Project - C++

    Description:
    This program simulates a queue-based ticketing system
    similar to those used in banks, hospitals, and customer
    service centers. Clients take a ticket number and wait
    in a queue to be served in a First-Come-First-Serve (FCFS)
    manner.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data = 0;
    Node* next = nullptr;
};

template <typename T>
class Queue {
private:

    Node<T>* front = nullptr;
    Node<T>* rear = nullptr;
    int sizeC = 0;

public:

    void enqueue(T dat) {
        Node<T>* n = new Node<T>;
        n->data = dat;
        n->next = nullptr;

        if (isEmpty()) {
            front = rear = n;
        }
        else {
            rear->next = n;
            rear = n;
        }
        sizeC++;
    }

    T dequeue() {
        if (front != nullptr) {
            Node<T>* oldFront = front;
            T data = oldFront->data;
            front = front->next;
            delete oldFront;
            sizeC--;

            if (isEmpty())
                rear = nullptr;

            return data;
        }
        return -1;
    }

    T getFront() {
        if (front != nullptr)
            return front->data;
        else
            return -1;
    }

    T getRear() {
        if (rear != nullptr)
            return rear->data;
        else
            return -1;
    }


    bool isEmpty() {
        return (front == nullptr);
    }

    int size() {
        return sizeC;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "\n--- Front ";
        Node<T>* iterator = front;
        while (iterator) {
            cout << "[ " << iterator->data << " ] ";
            iterator = iterator->next;
        }
        cout << " Rear ---\n\n";
    }

    void clear() {
        while (!isEmpty())
            dequeue();
    }

};


void displayMenu() {
    cout << "\nPlease Choose From List Below" << endl;
    cout << "1. Add Client to Queue" << endl;
    cout << "2. View First Client in Queue" << endl;
    cout << "3. Serve First Client in Queue Now" << endl;
    cout << "4. Display Full Client From Queue" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    cout << "========================================" << endl;
    cout << "===== Queue based ticketing system =====" << endl;
    cout << "========================================" << endl;

    Queue<int> q;

    int choice = 0;
    bool exitProgram = false;
    while (!exitProgram) {
        displayMenu();
		cout << "\nPlease Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (q.isEmpty()) {
                q.enqueue(1);
                cout << "\nClient no " << 1 << " is added to queue" << endl;
            }
            else
            {
                cout << "\nClient no " << q.getRear() + 1 << " is added to queue" << endl;
                q.enqueue(q.getRear() + 1);
            }
            break;

        case 2:
            if (q.isEmpty()) {
                cout << "\nQueue is Empty " << endl;
            }
            else {
                cout << "\nFirst client is no " << q.getFront() << endl;
            }
            break;

        case 3:
            if (q.isEmpty()) {
                cout << "\nQueue is Empty" << endl;
            }
            else {
                cout << "\nClient no " << q.getFront() << " is served \n";
                q.dequeue();
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
        {
            cout << "\nAre you sure you want to exit? (Yes/No): ";

            string confirm;
            cin >> confirm;

            if (confirm == "y" || confirm == "Y" || confirm == "yes" || confirm == "Yes")
                exitProgram = true;

            break;
        }

        default:
            cout << "\nWrong choice detected please enter number from the list below to execute" << endl;
        }
        cout << endl;
    }

}

