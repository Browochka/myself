#include <iostream>


#include "doubly_linked_list.hpp"


namespace Browka {

   

    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
        Node* tmp;
        while (begin != nullptr) {
            tmp = begin;
            begin = begin->next;
            delete tmp;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::push_back(const T& value) noexcept {
        Node* new_node = new Node(value);
        new_node->next = nullptr;
        new_node->prev = end;
        if (end != nullptr)
            end->next = new_node;
        if (begin == nullptr)
            begin = new_node;
        end = new_node;

    }

    template<typename T>
    bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
        Node* current = begin;

        while (current->value != value && current->next != nullptr) {
            current = current->next;
        }

        if (current->value != value)
            return false;
        return true;
    }


    template<typename T>
    void DoublyLinkedList<T>::print() const noexcept {
        Node* current = begin;

        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }

    template<typename T>
    bool DoublyLinkedList<T>::remove_first(const T& value) noexcept { 
        if (has_item(value) == false) {
            return false; //здесь в зависимости от логики, то есть, если этого элемента не было, то и удаления не было
        }

        Node* current = begin;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next; //то есть если это не начало, то связываем предыдущий (current->prev)->next и следующий
                else
                    begin = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev; //те если это не конец, то то связываем следующий и предыдущий
                else
                    end = current->prev;

                delete current;
            }
            current = current->next;
        }

        return true;
    }

    template<typename T>
    std::size_t DoublyLinkedList<T>::size() const noexcept {
        std::size_t count = 0;
        Node* current = begin;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
}