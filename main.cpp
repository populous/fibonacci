#include <iostream>
#include <string>

#include "fibonacci.hpp"

int main(int argc, char* argv[]) {
    int n = 10;

    if (argc > 1) {
        try {
            n = std::stoi(argv[1]);
        } catch (const std::exception&) {
            std::cerr << "Invalid number: " << argv[1] << std::endl;
            return 1;
        }
    }

    std::cout << "fibonacci(" << n << ") = "
              << Fibonacci<long long>::Compute(n) << std::endl;
    return 0;
}