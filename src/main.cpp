#include <iostream>
#include "money.hpp"

using namespace std;

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
