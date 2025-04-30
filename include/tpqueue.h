// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
     struct  node {
       T data;
       node* next;
     };
     node* head, * tail;
 public:
     TPQueue() :head(nullptr), tail(nullptr) {}
     ~TPQueue();
     void push(T);
     T pop();
     bool isEmpty();
};

template<typename T>
TPQueue<T>::~TPQueue() {
    while (head) {
        node* next = head->next;
        delete head;
        head = next;
        }
    tail = nullptr;
}

template<typename T>
bool TPQueue<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void TPQueue<T>::push(T value) {
    node* temp = new node;
    temp->data = value;
    temp -> next = nullptr;
    if (isEmpty()) {
        head = tail = temp;
    } else {
        int pr = value.prior;
        node* current = head;
        if (pr > head->data.prior) {
            head = temp;
            temp->next = current;
            return;
        }
        while (current->next && pr <= current->next->data.prior) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        if (temp->next == nullptr) {
            tail = temp;
        }
    }
}

template<typename T>
T TPQueue<T>::pop() {
    if (isEmpty()) {
        throw std::string("Queue is empty");
    }
    node* old_head = head;
    T data = old_head->data;
    head = head->next;
    delete old_head;
    if (isEmpty())
        tail = nullptr;
    return data;
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
