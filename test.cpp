#include <gtest/gtest.h>
#include <concepts>

#include "fibonacci.hpp"

static_assert(FibonacciValue<int>);
static_assert(FibonacciValue<long long>);
static_assert(!FibonacciValue<double>);

template <typename T>
concept HasFibonacciCompute = requires {
    { Fibonacci<T>::Compute(5) } -> std::same_as<T>;
};

static_assert(HasFibonacciCompute<int>);
static_assert(HasFibonacciCompute<long long>);
static_assert(!HasFibonacciCompute<double>);

TEST(FibonacciTest, HandlesZeroAndOne) {
    EXPECT_EQ(Fibonacci<int>::Compute(0), 0);
    EXPECT_EQ(Fibonacci<int>::Compute(1), 1);
    EXPECT_EQ(Fibonacci<long long>::Compute(0), 0);
    EXPECT_EQ(Fibonacci<long long>::Compute(1), 1);
}

TEST(FibonacciTest, ComputesSmallValues) {
    EXPECT_EQ(Fibonacci<int>::Compute(2), 1);
    EXPECT_EQ(Fibonacci<int>::Compute(3), 2);
    EXPECT_EQ(Fibonacci<int>::Compute(10), 55);

    EXPECT_EQ(Fibonacci<long long>::Compute(2), 1);
    EXPECT_EQ(Fibonacci<long long>::Compute(3), 2);
    EXPECT_EQ(Fibonacci<long long>::Compute(10), 55);
}

TEST(FibonacciTest, HandlesNegativeValues) {
    EXPECT_EQ(Fibonacci<int>::Compute(-1), 0);
    EXPECT_EQ(Fibonacci<int>::Compute(-10), 0);
    EXPECT_EQ(Fibonacci<long long>::Compute(-1), 0);
    EXPECT_EQ(Fibonacci<long long>::Compute(-10), 0);
}
