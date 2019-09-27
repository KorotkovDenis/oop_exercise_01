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
    if (l.m_cmp(r) > 0) {
        std::cout << "cmp: >\n";
    } else if (l.m_cmp(r) == 0) {
        std::cout << "cmp: =\n";
    } else {
        std::cout << "cmp: <\n";
    }
    std::cout << "sum: ";
    res = l.m_sum(r);
    res.m_print(std::cout);
    std::cout << "digital division: ";
    res = l.m_dig_div(div);
    res.m_print(std::cout);
    std::cout << "digital product: ";
    res = l.m_dig_prod(prod);
    res.m_print(std::cout);
    std::cout << "money division: " << l.m_div(r) << '\n';
}
