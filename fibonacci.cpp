#include "fibonacci.hpp"

template <FibonacciValue T>
T Fibonacci<T>::Compute(int n) {
    if (n <= 0) {
        return static_cast<T>(0);
    }
    if (n == 1) {
        return static_cast<T>(1);
    }

    T a = static_cast<T>(0);
    T b = static_cast<T>(1);

    for (int i = 2; i <= n; ++i) {
        const T next = a + b;
        a = b;
        b = next;
    }

    return b;
}

template class Fibonacci<int>;
template class Fibonacci<long long>;
