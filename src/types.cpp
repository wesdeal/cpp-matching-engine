#include <matching_engine/order.hpp>
#include <matching_engine/types.hpp>
#include <cmath>
#include <ostream>

// Types Output

//Price
namespace me {
std::ostream& operator<<(std::ostream& os, const Price& p) {
    return os << p.ticks;
}
//Quantity
std::ostream& operator<<(std::ostream& os, const Quantity& q) {
    return os << q.shares;
}
//Order
std::ostream& operator<<(std::ostream& os, const Order& o) {
    return os << "Order{id=" << o.id.id << ", price=" << o.price
              << ", qty=" << o.quantity << "}";
}

// Boundary conversion. No `inline` here: an inline function defined in a .cpp
// is invisible to every other TU, which would be a link error in the tests.
Price price_from_dollars(double dollars) noexcept {
    return Price{std::llround(dollars * kTicksPerDollar)};
}

}
