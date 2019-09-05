#include <iostream>
#include <sstream>
#include <string>

#include <cmath>

#include "money.hpp"


using namespace std;


Money::Money(){};
Money::Money(unsigned long long r,
        unsigned char p):rub(r + p / 100), pen(p % 100){};

Money operator+ (const Money &lhs, const Money &rhs) {
    unsigned long long overflow = 0;
    if (lhs.pen + rhs.pen >= 100) overflow = 1;

    return(Money(lhs.rub+rhs.rub+overflow, (lhs.pen + rhs.pen) % 100));
}

Money operator- (const Money &lhs, const Money &rhs) {
    if (lhs < rhs) {
        cout << "Вы банкрот ";
        return(Money(0,0));
    }
    unsigned long long underflow = 0;
    unsigned char pen;
    if (lhs.pen < rhs.pen) { underflow = 1; }

    return(Money(lhs.rub-rhs.rub-underflow, (100 - (rhs.pen - lhs.pen)) % 100));
}

bool operator< (const Money &lhs, const Money &rhs) {
    return (lhs.rub < rhs.rub || (lhs.rub == rhs.rub && lhs.pen < rhs.pen));
}

bool operator> (const Money &lhs, const Money &rhs) {
    return (lhs.rub > rhs.rub || (lhs.rub == rhs.rub && lhs.pen > rhs.pen));
}

bool operator== (const Money &lhs, const Money &rhs) {
    return (lhs.rub == rhs.rub && lhs.pen == rhs.pen);
}

std::ostream& operator<< (std::ostream &out, Money mon) {
    out << mon.rub << "." << int(mon.pen);

    return out;
}

std::istream& operator>> (std::istream &in, Money &mon) {

    unsigned long long r;
    unsigned char p;

    string rub;
    in >> rub;
    if (rub.at(0) == '-') { 
        r = 0; 
    } else {
        stringstream rub_stream(rub);
        rub_stream >> r; 
    }

    string pen;
    in >> pen;
    if (pen.at(0) == '-') { 
        p = 0; 
    } else { 
        stringstream pen_stream(pen);
        pen_stream >> p; 
    }

    mon.rub = r / 100;
    mon.pen = p % 100;

    return in;
}

Money operator* (const Money &lhs, double num) {
    unsigned long long rub_overflow = 0;
    unsigned long long pen_overflow = 0;
    if (lhs.pen * num >= 100) rub_overflow = lhs.pen * num / 100;
    if (fmod(lhs.rub * num, 1) != 0) pen_overflow = fmod(lhs.rub * num, 1.0) * 100;

    return(Money((lhs.rub * num) + rub_overflow, 
                (unsigned char)(lhs.pen * num) % 100 + pen_overflow));
}

Money operator/ (const Money &lhs, double num) {
    unsigned long long rub_overflow = 0;
    unsigned long long pen_overflow = 0;
    if (lhs.pen / num >= 100) rub_overflow = (lhs.pen / num) / 100;
    if (fmod(lhs.rub / num, 1) != 0) pen_overflow = fmod(lhs.rub / num, 1.0) * 100;

    return(Money((lhs.rub / num) + rub_overflow, 
                (unsigned char)(lhs.pen / num) % 100 + pen_overflow));
}

