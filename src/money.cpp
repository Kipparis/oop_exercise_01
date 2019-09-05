#include <iostream>

#include "money.hpp"

using namespace std;


Money::Money(){};
Money::Money(unsigned long long r,
        unsigned char p):rub(r), pen(p){};

Money operator + (const Money &lhs, const Money &rhs) {
    unsigned long long overflow = 0;
    if (lhs.pen + rhs.pen >= 100) overflow = 1;

    return(Money(lhs.rub+rhs.rub+overflow, (lhs.pen + rhs.pen) % 100));
}

Money operator - (const Money &lhs, const Money &rhs) {
    if (lhs < rhs) {
        cout << "Вы банкрот ";
        return(Money(0,0));
    }
    unsigned long long underflow = 0;
    if (lhs.pen < rhs.pen) underflow = 1;

    return(Money(lhs.rub-rhs.rub-underflow, (lhs.pen + rhs.pen) % 100));
}

bool operator < (const Money &lhs, const Money &rhs) {
    return (lhs.rub < rhs.rub || (lhs.rub == rhs.rub && lhs.pen < rhs.pen));
}

bool operator > (const Money &lhs, const Money &rhs) {
    return (lhs.rub > rhs.rub || (lhs.rub == rhs.rub && lhs.pen > rhs.pen));
}

std::ostream& operator<< (std::ostream &out, Money mon) {
    out << mon.rub << "." << int(mon.pen);

    return out;
}

std::istream& operator>> (std::istream &in, Money &mon) {
    in >> mon.rub;
    unsigned int pen;
    in >> pen;
    mon.pen = (unsigned char)(pen);

    return in;
}

Money operator * (const Money &lhs, double num) {
    unsigned long long overflow = 0;
    if (lhs.pen * num >= 100) overflow = 1;

    return(Money((lhs.rub*num)+overflow, (unsigned char)(lhs.pen * num) % 100));
}

Money operator / (const Money &lhs, double num) {
    unsigned long long overflow = 0;
    if (lhs.pen / num >= 100) overflow = 1;

    return(Money((lhs.rub/num)+overflow, (unsigned char)(lhs.pen / num) % 100));
}

