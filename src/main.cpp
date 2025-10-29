#include <iostream>
#include <vector>
#include <memory>
#include "figure_array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

int main() {
    // Создаем массив умных указателей на базовый класс Figure
    Array<std::shared_ptr<Figure<double>>> figures(3);

    // Создаем и вводим данные для фигур
    std::cout << "--- Creating Pentagon ---\n";
    figures[0] = std::make_shared<Pentagon<double>>();
    std::cin >> *figures[0];

    std::cout << "\n--- Creating Hexagon ---\n";
    figures[1] = std::make_shared<Hexagon<double>>();
    std::cin >> *figures[1];

    std::cout << "\n--- Creating Octagon ---\n";
    figures[2] = std::make_shared<Octagon<double>>();
    std::cin >> *figures[2];

    std::cout << "\n--- Figures Info ---\n";
    double totalArea = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        std::cout << "Points: " << *figures[i] << "\n";
        Point<double> center = figures[i]->getCenter();
        double area = figures[i]->getArea();
        totalArea += area;
        std::cout << "Center: " << center << "\n";
        std::cout << "Area: " << area << "\n\n";
    }

    std::cout << "Total area of all figures: " << totalArea << std::endl;

    // Демонстрация удаления
    if (figures.size() > 1) {
        std::cout << "\n--- Removing figure at index 1 ---\n";
        figures.remove(1);

        std::cout << "Array size after removal: " << figures.size() << std::endl;
        totalArea = 0;
        for (size_t i = 0; i < figures.size(); ++i) {
            totalArea += figures[i]->getArea();
        }
        std::cout << "New total area: " << totalArea << std::endl;
    }

    return 0;
}