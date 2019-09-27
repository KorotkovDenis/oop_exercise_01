#include "Money.hpp"
#include <iostream>


signed main() {
    money l;
    l.m_scan(std::cin);
    unsigned long long rpo;
    int rsh, rpe;
    double div, prod;
    std::cin >> rpo >> rsh >> rpe;
    std::cin >> div >> prod;
    money r {rpo, (unsigned char)(rsh), (unsigned char)(rpe)};
    money res {};
    if (l.m_equal(r)) {
        std::cout << "equal: YES\n";
    } else {
        std::cout << "equal: NO\n";
    }
    std::cout << "sum: ";
    res.m_sum(l, r);
    res.m_print(std::cout);
    std::cout << "digital division: ";
    res.m_dig_div(l, div);
    res.m_print(std::cout);
    std::cout << "digital product: ";
    res.m_dig_prod(l, prod);
    res.m_print(std::cout);
    std::cout << "money division: " << l.m_div(r) << '\n';
}
