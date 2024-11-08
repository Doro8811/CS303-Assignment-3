#pragma once

#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the head of the list
void insertHead(shared_ptr<Node>& head, int val) {
    auto newNode = make_shared<Node>(val);
    newNode->next = head;
    head = newNode;
}

// Function to print the list
void printList(const shared_ptr<Node>& head) {
    auto current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// function for performing insertion sort on the linked list
shared_ptr<Node> insertionSort(const shared_ptr<Node>& head) {
    if (!head || !head->next) return head;

    shared_ptr<Node> sorted = nullptr; // start with an empty sorted list
    auto current = head;

    while (current != nullptr) {
        auto next = current->next;
        if (!sorted || sorted->data >= current->data) {
            // insert at the beginning of sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // locating the node before the insertion point
            auto temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}
