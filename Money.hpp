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
    int m_cmp(const money& a) const;
    money m_sum(const money& m) const;
    money m_dig_div(const double a) const;
    double m_div(const money& m) const;
    money m_dig_prod(const double a) const;
    void m_unif();
private:
    unsigned long long m_all() const;
};

#endif