#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            denominator = std::numeric_limits<int>::max(); 
        }
    }

    friend ostream& operator<<(ostream& out, const Fraction& frac) {
        out << frac.numerator << "/" << frac.denominator;
        return out;
    }

    bool operator<(const Fraction& other) const {
        return (double)numerator / denominator < (double)other.numerator / other.denominator;
    }

    double abs() const {
        return std::abs((double)numerator / denominator); 
    }
};

void push(list<Fraction>& fractionList, const Fraction& newFraction) {
    auto it = lower_bound(fractionList.begin(), fractionList.end(), newFraction);
    fractionList.insert(it, newFraction);
}

void pop(list<Fraction>& fractionList) {
    if (!fractionList.empty()) {
        fractionList.pop_back();
    }
}

list<Fraction> filter(const list<Fraction>& fractionList, double a) {
    list<Fraction> filteredList(fractionList);
    filteredList.remove_if([a](const Fraction& frac) {
        return frac.abs() > a;
    });
    return filteredList;
}

int main() {
    list<Fraction> fractionList;

    push(fractionList, Fraction(1, 2));
    push(fractionList, Fraction(3, 4));
    push(fractionList, Fraction(5, 6));
    push(fractionList, Fraction(-2, 3));
    push(fractionList, Fraction(7, 8));

    cout << "Элементы списка (исходный):" << endl;
    for (const Fraction& frac : fractionList) {
        cout << frac << endl;
    }

    double a = 0.7;
    list<Fraction> filteredList = filter(fractionList, a);

    cout << "Элементы списка (отфильтрованный, a = " << a << "):" << endl;
    for (const Fraction& frac : filteredList) {
        cout << frac << endl;
    }

    return 0;
}