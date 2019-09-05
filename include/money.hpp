#ifndef __money_hpp__
#define __money_hpp__

#include <iostream>

using namespace std;

class Money {
    unsigned long long rub;
    unsigned char pen;
    
    public:
        Money();
        Money(unsigned long long r, unsigned char p);
        
        friend Money operator + (const Money &lhs, const Money &rhs);
        friend Money operator - (const Money &lhs, const Money &rhs);

        friend Money operator * (const Money &lhs, double num);
        friend Money operator / (const Money &lhs, double num);

        friend bool operator < (const Money &lhs, const Money &rhs);
        friend bool operator > (const Money &lhs, const Money &rhs);

        friend std::ostream& operator<< (std::ostream &out, Money mon);
        friend std::istream& operator>> (std::istream &in, Money &mon);
};


#endif
