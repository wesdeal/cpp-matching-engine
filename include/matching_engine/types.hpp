/* 
Purpose of Price and Quantity custom types:

C++ doesnt handle floats well which is typically what prices are represented by 0.1 + 0.2 != 0.3

Solution:
    define our own type to handle prices and price arithmetic and operations

    use ticks as main rep of price 1 tick is 1 cent. 

    $70 = 7000 (multiply by 100 to get our decimal places at the end
                dollars only multi by 100; cents keep same)

*/
#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>


namespace me {
    constexpr std::int64_t kTicksPerDollar {10000};

    struct Price {
        std::int64_t ticks{0}; // ticks for price. int64_t sets all ints to 64 bits


        Price up(std::int64_t n) const noexcept {
            return Price{ticks + n};
        }
        Price down(std::int64_t n) const noexcept {
            return Price{ticks - n};
        }
    };

    struct Quantity {
        std::int64_t shares{0};
    };



    inline Price price_from_dollars(double dollars) noexcept {
        return Price{std::llround(dollars * kTicksPerDollar)};
    }






    // Operator Overloading
    
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



}