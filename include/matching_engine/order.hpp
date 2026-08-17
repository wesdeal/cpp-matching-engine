#pragma once
#include <matching_engine/types.hpp>

// define an order

enum class Side {
    buy, sell
};

class OrderId {
    int value;

    public:
        OrderId(int v) : value(v){}

        int get() const {
            return value;
        }
};


struct Order {
    OrderId id;
    me::Price price;
    me::Quantity quantity;
    Side side;
};