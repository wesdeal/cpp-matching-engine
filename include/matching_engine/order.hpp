#pragma once
#include <matching_engine/types.hpp>
#include <cstdint>

// define an order

namespace me {
    
    enum class Side {
        buy, sell
    };

    struct OrderId {
        std::uint64_t id{0};
    };


    struct Order {
        OrderId id;
        Price price;
        Quantity quantity;
        Side side;
        Timestamp timestamp;
    };


}

