#pragma once

#include <memory>
#include <stdexcept>
#include <initializer_list>

template <class T>
class Array {
private:
    size_t _size;
    std::unique_ptr<T[]> _arr;

public:
    Array();
    Array(size_t size);
    Array(const std::initializer_list<T>& list);
    Array(const Array<T>& other);
    Array(Array<T>&& other) noexcept;

    Array<T>& operator=(const Array<T>& other);
    Array<T>& operator=(Array<T>&& other) noexcept;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
    void remove(size_t index);
};

