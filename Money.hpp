#ifndef __MONEY__
#define __MONEY__
#include <iostream>


struct money {
    unsigned long long pound;
    unsigned char shilling;
    unsigned char pension;
    money();
    money(unsigned long long po, unsigned char sh, unsigned char pe);
    void m_print(std::ostream& os) const;
    void m_scan(std::istream& is);
    bool m_equal(const money& a) const;
    void m_sum(const money& lhs, const money& rhs);
    void m_dig_div(const money& m, const double a);
    double m_div(const money& m) const;
    void m_dig_prod(const money& m, const double a);
    void m_unif();
private:
    unsigned long long all;
};

#endif