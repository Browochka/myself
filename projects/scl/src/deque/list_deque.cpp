#include "list_deque.hpp"


template<typename T>
Browka::ListDeque<T>::~ListDeque() noexcept {
    Node* current = begin;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
};


template<typename T>
bool Browka::ListDeque<T>::empty() const noexcept {
    return begin == nullptr;
};


template<typename T>
void Browka::ListDeque<T>::pop_back() noexcept {
    if (begin == nullptr) {
        return;
    }
    if (begin == end) {
        delete begin;
        begin = nullptr;
        end = nullptr;
        return;
    }
    Node* temp = begin;
    while (temp->next != end) {
        temp = temp->next;
    }
    delete end;
    end = temp;
    end->next = nullptr;
};


template<typename T>
void Browka::ListDeque<T>::pop_front() noexcept {
    if (begin == nullptr) {
        return;
    }
    Node* temp = begin;
    begin = begin->next;
    delete temp;
    if (begin == nullptr) {
        end = nullptr;
    }
};


template<typename T>
void Browka::ListDeque<T>::push_back(const T& value) noexcept {
    Node* newNode = new Node(value);
    if (begin == nullptr) {
        begin = newNode;
    }
    else {
        end->next = newNode;
    }

    end = newNode;
};


template<typename T>
void Browka::ListDeque<T>::push_front(const T& value) noexcept {
    Node* newNode = new Node(value);
    if (begin == nullptr) {
        end = newNode;
    }
    else {
        newNode->next = begin;
    }

    begin = newNode;
};


template<typename T>
std::size_t Browka::ListDeque<T>::size() const noexcept {
    std::size_t size = 0;
    Node* current = begin;
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
};


template<typename T>
T Browka::ListDeque<T>::back() const noexcept {
    if (end != nullptr) {
        return end->value;
    }
    return false;
};


template<typename T>
T Browka::ListDeque<T>::front() const noexcept {
    if (begin != nullptr) {
        return begin->value;
    }
    return false;
}