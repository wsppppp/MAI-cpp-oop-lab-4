#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Point.h"

template <is_scalar T>
class Figure {
public:
    // Конструктор, принимающий количество вершин
    Figure(size_t vertices_count) : n(vertices_count), p(std::make_unique<Point<T>[]>(vertices_count)) {}
    
    // Виртуальный деструктор
    virtual ~Figure() = default;

    // Чисто виртуальные функции
    virtual Point<T> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual operator double() const = 0;

    // Операторы сравнения
    bool operator==(const Figure<T>& other) const {
        return (operator double()) == (double)other;
    }

protected:
    size_t n; // Количество вершин
    std::unique_ptr<Point<T>[]> p; // Умный указатель на массив точек

    // Дружественные функции для ввода/вывода
    template <is_scalar F>
    friend std::istream& operator>>(std::istream& is, Figure<F>& figure);
    template <is_scalar F>
    friend std::ostream& operator<<(std::ostream& os, const Figure<F>& figure);
};

