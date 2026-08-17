#include <gtest/gtest.h>
#include <matching_engine/types.hpp>
#include <matching_engine/order.hpp>
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



TEST(OrderSuite, ConstructingOrder) {
    Order order {98765, me::Price{678900}, me::Quantity{5} , Side::buy};
    EXPECT_EQ(order.id.get(), 98765);
    EXPECT_EQ(order.price.ticks, 678900);
    EXPECT_EQ(order.quantity.shares, 5);
    EXPECT_EQ(order.side, Side::buy);
    std::cout << "SIZE OF ORDER" << sizeof(Order);
}

TEST(PriceTypeSuite, Operations) {

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

TEST(PriceTypeSuite, Movements) {
     me::Price p {123400};
     me::Price better = p.up(100);
     EXPECT_EQ(better, me::Price{123500});

     me::Price q {123400};
     me::Price better_q = q.down(100);
     EXPECT_EQ(better_q, me::Price{123300});
}

TEST(TypesSuite, Reads) {
    std::int64_t x {100};
    EXPECT_EQ(ReadPrice(), x);

    EXPECT_EQ(ConvertPrice(12.34), me::Price{123400});
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