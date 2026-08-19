/* 
Purpose of Price and Quantity custom types:

C++ doesnt handle floats well which is typically what prices are represented by 0.1 + 0.2 != 0.3

Solution:
    define our own type to handle prices and price arithmetic and operations

    use ticks as main rep of price 1 tick is 1/100 cent. 

    $70 = 70000 (multiply by 10000 to get our decimal places at the end)

*/
#pragma once

#include <cstdint>
#include <iosfwd>   // forward-declares std::ostream only: enough to DECLARE
                    // operator<<, without paying for all of <iostream> in
                    // every file that includes this header.


namespace me {
    constexpr std::int64_t kTicksPerDollar {10000};

    struct Price {
        std::int64_t ticks{0}; // ticks for price. int64_t sets all ints to 64 bits

        constexpr Price up(std::int64_t n) const noexcept {
            return Price{ticks + n};
        }
        constexpr Price down(std::int64_t n) const noexcept {
            return Price{ticks - n};
        }
    };

    struct Quantity {
        std::int64_t shares{0};
    };

    // nanoseconds since midnight; resets everyday. fine for this engine that processes one day of trades
    struct Timestamp {
        std::int64_t ns{0};
    };

    // boundary func for testing and functionality.
    // Defined in src/types.cpp: it is not constexpr and never runs on the hot
    // path, so it does not need to be visible to every translation unit.
    // Keeping it out here also keeps <cmath> out of this header.
    Price price_from_dollars(double dollars) noexcept;


    // Operator Overloading

    // Price operators
    
    constexpr bool operator==(Price a, Price b) noexcept {
        return (a.ticks == b.ticks);
    }
    constexpr bool operator!=(Price a, Price b) noexcept {
        return (a.ticks != b.ticks);
    }
    constexpr bool operator>(Price a, Price b) noexcept {
        return (a.ticks > b.ticks);
    }
    constexpr bool operator<(Price a, Price b) noexcept {
        return (a.ticks < b.ticks);
    }
    constexpr bool operator>=(Price a, Price b) noexcept {
        return (a.ticks >= b.ticks);
    }
    constexpr bool operator<=(Price a, Price b) noexcept {
        return (a.ticks <= b.ticks);
    }


    // Quantity operators

    // arithmetic
    constexpr me::Quantity operator+(Quantity a, Quantity b) noexcept {
        return Quantity{a.shares + b.shares};   
    }
    constexpr me::Quantity operator-(Quantity a, Quantity b) noexcept {
        return Quantity{a.shares - b.shares};   
    }
    

    constexpr bool operator==(Quantity a, Quantity b) noexcept {
        return (a.shares == b.shares);
    }
    constexpr bool operator!=(Quantity a, Quantity b) noexcept {
        return (a.shares != b.shares);
    }
    constexpr bool operator>(Quantity a, Quantity b) noexcept {
        return (a.shares > b.shares);
    }
    constexpr bool operator<(Quantity a, Quantity b) noexcept {
        return (a.shares < b.shares);
    }
    constexpr bool operator>=(Quantity a, Quantity b) noexcept {
        return (a.shares >= b.shares);
    }
    constexpr bool operator<=(Quantity a, Quantity b) noexcept {
        return (a.shares <= b.shares);
    }


    // TODO
    // overload operator<< for Price Quantity

    //Price
    std::ostream& operator<<(std::ostream& os, const me::Price& p);

    //Quantity
    std::ostream& operator<<(std::ostream& os, const me::Quantity& q);

}