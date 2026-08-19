#pragma once
#include <matching_engine/types.hpp>
#include <cstdint>
#include <iosfwd>   // don't rely on types.hpp to drag std::ostream in for us

// define an order

// id=0  price=8  quantity=16  side=24  [4 bytes padding]  timestamp=32   → 40

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

    std::ostream& operator<<(std::ostream& os, const Order& o);


}

