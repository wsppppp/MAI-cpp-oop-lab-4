#include "../include/figure_array.h"

template <class T>
Array<T>::Array() : _size(0), _arr(nullptr) {}

template <class T>
Array<T>::Array(size_t size) : _size(size), _arr(std::make_unique<T[]>(size)) {}

template <class T>
Array<T>::Array(const std::initializer_list<T>& list) : _size(list.size()), _arr(std::make_unique<T[]>(list.size())) {
    size_t i = 0;
    for (const auto& item : list) {
        _arr[i++] = item;
    }
}

template <class T>
Array<T>::Array(const Array<T>& other) : _size(other._size), _arr(std::make_unique<T[]>(other._size)) {
    for (size_t i = 0; i < _size; ++i) {
        _arr[i] = other._arr[i];
    }
}

template <class T>
Array<T>::Array(Array<T>&& other) noexcept : _size(other._size), _arr(std::move(other._arr)) {
    other._size = 0;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        _size = other._size;
        _arr = std::make_unique<T[]>(_size);
        for (size_t i = 0; i < _size; ++i) {
            _arr[i] = other._arr[i];
        }
    }
    return *this;
}

template <class T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        _size = other._size;
        _arr = std::move(other._arr);
        other._size = 0;
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _arr[index];
}

template <class T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _arr[index];
}

template <class T>
size_t Array<T>::size() const {
    return _size;
}

template <class T>
void Array<T>::remove(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    auto new_arr = std::make_unique<T[]>(_size - 1);
    for (size_t i = 0, j = 0; i < _size; ++i) {
        if (i != index) {
            new_arr[j++] = std::move(_arr[i]);
        }
    }
    _arr = std::move(new_arr);
    _size--;
}