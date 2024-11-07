#pragma once

#include <iostream>
using namespace std;

//class defined with the template class
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int currentSize;

public: //public functions of the program as designated
    Queue();             // constructor
    ~Queue();            // destructor
    void push(T value);  // pushes an item to the rear of the queue
    void pop();          // removes the front item of the queue
    T front();           // returns the front item
    int size() const;    // returns the size of the queue
    bool empty() const;  // checks if the queue is empty
    void move_to_rear(); // moves the front item to the rear
};

// constructor
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), currentSize(0) {}

// destructor
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// pushing a new item to the rear of the queue
template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    currentSize++;
}

// removing the front item from the queue
template <typename T>
void Queue<T>::pop() {
    if (!empty()) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        currentSize--;
        if (currentSize == 0) {
            rearNode = nullptr;
        }
    }
}

// returns the front item from the queue
template <typename T>
T Queue<T>::front() {
    if (!empty()) {
        return frontNode->data;
    } else {
        throw runtime_error("Queue is empty");
    }
}

// returns the size of the queue
template <typename T>
int Queue<T>::size() const {
    return currentSize;
}

// checks if the queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return currentSize == 0;
}

// moves the front item to the rear of the queue
template <typename T>
void Queue<T>::move_to_rear() {
    if (size() > 1) {
        T frontElement = front();
        pop();
        push(frontElement);
    }
}
