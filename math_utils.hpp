#pragma once

#include <concepts>

template <std::integral T>
class MathUtils final {
public:
    static T Fibonacci(int n);
    static T Factorial(int n);
};