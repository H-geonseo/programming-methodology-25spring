#include <gtest/gtest.h> // CMakeList.txt파일 덕분에 괜찮음
#include "calculator.h"
#include <limits>
#include <stdexcept>

TEST(CalculatorTest, Add) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, -1), -2);
}

TEST(CalculatorTest, Subtract) {
    Calculator calc;
    EXPECT_EQ(calc.sub(5, 2), 3);
    EXPECT_EQ(calc.sub(0, 10), -10);
}

TEST(CalculatorTest, Multiply) {
    Calculator calc;
    EXPECT_EQ(calc.mul(4, 3), 12);
    EXPECT_EQ(calc.mul(0, 99), 0);
}

TEST(CalculatorTest, Divide) {
    Calculator calc;
    EXPECT_EQ(calc.div(10, 2), 5);
    EXPECT_EQ(calc.div(9, 3), 3);
}

TEST(CalculatorTest, DivideByZero) {
    Calculator calc;
    EXPECT_THROW(calc.div(10, 0), std::invalid_argument);
}

TEST(CalculatorTest, AddOverflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::max();
    EXPECT_THROW(calc.add(a, 1), std::overflow_error);
}

TEST(CalculatorTest, AddUnderflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::min();
    EXPECT_THROW(calc.add(a, -1), std::overflow_error);
}

TEST(CalculatorTest, SubtractOverflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::max();
    EXPECT_THROW(calc.sub(a, -1), std::overflow_error);
}

TEST(CalculatorTest, SubtractUnderflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::min();
    EXPECT_THROW(calc.sub(a, 1), std::overflow_error);
}

TEST(CalculatorTest, MultiplyOverflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::max() / 2 + 1;
    EXPECT_THROW(calc.mul(a, 2), std::overflow_error);
}

TEST(CalculatorTest, MultiplyUnderflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::min() / 2;
    EXPECT_THROW(calc.mul(a, 3), std::overflow_error);
}

TEST(CalculatorTest, DivideOverflow) {
    Calculator calc;
    int a = std::numeric_limits<int>::min();
    EXPECT_THROW(calc.div(a, -1), std::overflow_error);
}