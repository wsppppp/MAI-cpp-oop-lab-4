#pragma once

#include <type_traits>

// Концепт для проверки, является ли тип скалярным (арифметическим типом)
template <class T>
concept is_scalar = std::is_arithmetic_v<T>;