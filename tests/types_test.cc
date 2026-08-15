#include <gtest/gtest.h>
#include <matching_engine/types.hpp>
#include <iostream>
#include <cstdint>


float Add(float a, float b) {
    return a + b;
}

std::int64_t ReadPrice() {
    me::Price a{100};
    return a.ticks;
}

std::int64_t ConvertPrice(double y) {
    return me::price_from_dollars(y).ticks;
}



TEST(TypesSuite, Reads) {
    std::int64_t x {100};
    EXPECT_EQ(ReadPrice(), x);

    std::int64_t y = 1234;
    EXPECT_EQ(ConvertPrice(12.34), y);
}


TEST(AdditionTestSuite, FloatAsserts) {
    EXPECT_NE(Add(0.1, 0.2), 0.3);

}


TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}