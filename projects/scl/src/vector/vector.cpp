#include "vector.hpp"


template <typename T>
Browka::Vector<T>::Vector() noexcept {
    arr = new T[capacity];
}


template <typename T>
Browka::Vector<T>::~Vector() noexcept {
    delete[] arr;
    arr = nullptr;
};


template <typename T>
void Browka::Vector<T>::push_back(const T& value) noexcept {
    if (vec_size >= capacity) {
        capacity *= 2;
        T* temp = new T[capacity];
        for (std::size_t i = 0; i < vec_size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    arr[vec_size++] = value;
};


template <typename T>
bool Browka::Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < vec_size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }

    return false;
};


template <typename T>
bool Browka::Vector<T>::insert(const int position, const T& value) {
    if (position < 0 || position > vec_size) {
        return false;
    }

    if (vec_size >= capacity) {
        capacity *= 2;
        T* temp = new T[capacity];
        for (std::size_t i = 0; i < position; i++) {
            temp[i] = arr[i];
        }

        temp[position] = value;
        for (std::size_t i = position; i < vec_size; i++) {
            temp[i + 1] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }
    else {
        for (std::size_t i = vec_size; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = value;
    }

    vec_size++;
    return true;
};


template <typename T>
void Browka::Vector<T>::print() const noexcept {
    for (std::size_t i = 0; i < vec_size; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
};


template <typename T>
bool Browka::Vector<T>::remove_first(const T& value) noexcept {
    for (std::size_t i = 0; i < vec_size; i++) {
        if (arr[i] == value) {
            for (std::size_t j = i; j < vec_size - 1; j++) {
                arr[j] = arr[j + 1];
            }

            vec_size--;
            return true;
        }
    }

    return false;
};