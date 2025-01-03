//
// Created by vudan on 1/1/2025.
//

#include "LinkedList.h"
#include "iostream"
#include "Medicine.h"
#include "Client.h"
#include "Order.h"

using namespace std;


template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template<typename T>
int LinkedList<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    return 1;
}
template<typename T>
void LinkedList<T>::display() {
    if (head == nullptr) {
        cout << "Danh sách trống." << endl;
        return;
    }
    Node<T>* current = head; // Bắt đầu từ nút đầu danh sách
    while (current != nullptr) {
        cout << current->data << endl; // Hiển thị dữ liệu của nút
        current = current->next;        // Di chuyển tới nút tiếp theo
    }
}

template<typename T>
int LinkedList<T>::update(T value, T new_value) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            current->data = new_value;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

template<typename T>
int LinkedList<T>::remove(T value) {
    Node<T>* current = head;
    Node<T>* previous = nullptr;
    while (current != nullptr) {
        if (current->data == value) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}
template class LinkedList<Medicine>;
template class LinkedList<Client>;
template class LinkedList<Order>;