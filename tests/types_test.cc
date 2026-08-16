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

me::Price ConvertPrice(double y) {
    return me::price_from_dollars(y);
}



TEST(PriceTypeSuit, Operations) {

    //Equal to ==
    me::Price a {1234};
    me::Price b {1234};
    EXPECT_EQ(a == b, true);

    me::Price x {1234};
    me::Price y {1235};
    EXPECT_EQ(x != y, true);


    EXPECT_EQ(me::Price {1234} > me::Price {1233}, true);
    EXPECT_EQ(me::Price {1234} < me::Price {1235}, true);

    EXPECT_EQ(me::Price {1234} >=me::Price {1233}, true);
    EXPECT_EQ(me::Price {1234} <=me::Price {1235}, true);
    
    EXPECT_EQ(me::Price {1234} >= me::Price {1234}, true);
    EXPECT_EQ(me::Price {1234} <= me::Price {1234}, true);

}



TEST(TypesSuite, Reads) {
    std::int64_t x {100};
    EXPECT_EQ(ReadPrice(), x);

    EXPECT_EQ(ConvertPrice(12.34), me::Price{1234});
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