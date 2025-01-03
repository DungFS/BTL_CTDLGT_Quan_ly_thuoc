//
// Created by vudan on 1/1/2025.
//

#ifndef CTDL_LINKEDLIST_H
#define CTDL_LINKEDLIST_H


template <typename T>
struct Node{
    T data;           // Dữ liệu của nút
    Node* next;       // Con trỏ tới nút tiếp theo
    //Constructor để khởi tạo nút
    Node(T value) : data(value), next(nullptr) {}
};




template <typename T>
class LinkedList {
public:
    Node<T>* head; // Con trỏ tới nút đầu danh sách
    LinkedList();
    int append(T value);
    int remove(T value);
    int update(T value, T new_value);
    void display();
};



#endif //CTDL_LINKEDLIST_H
