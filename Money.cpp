#include "Money.hpp"
#include <iostream>

money::money() {
    pound = 0;
    shilling = 0;
    pension = 0;
}


money::money(unsigned long long po, unsigned char sh, unsigned char pe) {
    pound = po;
    shilling = sh;
    pension = pe;
}


unsigned long long money::m_all() const {
    return this->pension + this->shilling * 12 + this-> pound * 12 * 20;
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
}


int money::m_cmp(const money &a) const {
    if ((*this).m_all() > a.m_all()) return 1;
    else if ((*this).m_all() == a.m_all()) return 0;
    else return -1;

}


money money::m_sum(const money &m) const{
    money res;
    res.pound = this->pound + m.pound;
    res.shilling = this->shilling + m.shilling;
    res.pension = this->pension + m.pension;
    return res;
}


money money::m_dig_div(const double a) const{
    money res;
    unsigned long long all = (*this).m_all() / a;
    res.pound = all / 240;
    all %= 240;
    res.shilling = all / 12;
    all %= 12;
    res.pension = all;
    return res;
}


money money::m_dig_prod(const double a) const{
    money res;
    unsigned long long all = (*this).m_all() * a;
    res.pound = all / 240;
    all %= 240;
    res.shilling = all / 12;
    all %= 12;
    res.pension = all;
    return res;
}


double money::m_div(const money &m) const {
    return (*this).m_all() / m.m_all();
}


void money::m_unif() {
    this->pound += this->shilling / 20;
    this->shilling = this->shilling % 20;
    this->shilling += this->pension / 12;
    this->pension = this->pension % 12;
    this->pound += this->shilling / 20;
    this->shilling = this->shilling % 20;
}


