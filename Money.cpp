#include "Money.hpp"
#include <iostream>

money::money() {
    pound = 0;
    shilling = 0;
    pension = 0;
    all = 0;
}


money::money(unsigned long long po, unsigned char sh, unsigned char pe) {
    pound = po;
    shilling = sh;
    pension = pe;
    all = pe + sh * 12 + po * 12 * 20;
}


void money::m_print(std::ostream& os) const {
    unsigned char zer = 0;
    os << this->pound << ' ' << this->shilling - zer << ' ' << this->pension - zer << '\n';
}


void money::m_scan(std::istream& is) {
    int sh, pe;
    is >> this->pound >> sh >> pe;
    this->shilling = sh;
    this->pension = pe;
    this->all = this->pension + this->shilling * 12 + this->pound * 12 * 20;
}


bool money::m_equal(const money &a) const {
    return this->pound == a.pound && this->shilling == a.shilling && this->pension == a.pension;
}


void money::m_sum(const money &lhs, const money &rhs) {
    this->pound = lhs.pound + rhs.pound;
    this->shilling = lhs.shilling + rhs.shilling;
    this->pension = lhs.pension + rhs.pension;
    this->all = lhs.all + rhs.all;
}


void money::m_dig_div(const money &m, const double a) {
    this->pound = m.pound / a;
    this->shilling = m.shilling / a;
    this->pension = m.pension / a;
    this->all = this->pension + this->shilling * 12 + this->pound * 12 * 20;
}


void money::m_dig_prod(const money &m, const double a) {
    this->pound = m.pound * a;
    this->shilling = m.shilling * a;
    this->pension = m.pension * a;
    this->all = this->pension + this->shilling * 12 + this->pound * 12 * 20;
}


double money::m_div(const money &m) const {
    return this->all / m.all;
}


void money::m_unif() {
    this->pound += this->shilling / 20;
    this->shilling = this->shilling % 20;
    this->shilling += this->pension / 12;
    this->pension = this->pension % 12;
    this->pound += this->shilling / 20;
    this->shilling = this->shilling % 20;
}


