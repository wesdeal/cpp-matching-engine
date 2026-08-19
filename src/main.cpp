#include <iostream>
#include <optional>

int main() {
    double x {};
    std::optional<int> o {2};
    std::cout << o.value() << '\n';
    return 0;

}