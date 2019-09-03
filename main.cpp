#include <iostream>

using namespace std;

class Money {
    unsigned long long rub;
    unsigned char pen;
    
    public:
        Money() {};
        Money(unsigned long long r, unsigned char p) {
            rub = r;
            pen = p;
        }
        
        friend Money operator + (const Money &lhs, const Money &rhs);
        friend Money operator - (const Money &lhs, const Money &rhs);

        friend Money operator * (const Money &lhs, double num);
        friend Money operator / (const Money &lhs, double num);

        friend bool operator < (const Money &lhs, const Money &rhs);
        friend bool operator > (const Money &lhs, const Money &rhs);

        friend std::ostream& operator<< (std::ostream &out, Money mon);
        friend std::istream& operator>> (std::istream &in, Money &mon);
};

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

int main(void) {

    double num = 2;
    Money mon1;
    Money mon2;

    cout << "Считываем первое число:" << endl;
    cin >> mon1;
    cout << "Считываем второе число:" << endl;
    cin >> mon2;


    cout << "Складываем\t" << mon1 << " и " << mon2 << endl;
    cout << "Результат:\t" << mon1 + mon2 << endl;

    cout << endl;
    cout << "Вычитаем\t" << mon1 << " и " << mon2 << endl;
    cout << "Результат:\t" << mon1 - mon2 << endl;

    cout << endl;
    cout << "Сравниваем\t" << mon1 << " < " << mon2 << endl;
    cout << "Результат:\t" << (mon1 < mon2) << endl;

    cout << endl;
    cout << "Сравниваем\t" << mon1 << " > " << mon2 << endl;
    cout << "Результат:\t" << (mon1 > mon2) << endl;

    double mult = 1.5;
    cout << endl;
    cout << "Умножаем\t" << mon1 << " на " << mult << endl;
    cout << "Результат:\t" << (mon1 * mult) << endl;

    double div = 0.5;
    cout << endl;
    cout << "Делим:  \t" << mon1 << " на " << div << endl;
    cout << "Результат:\t" << (mon1 / div) << endl;
}
