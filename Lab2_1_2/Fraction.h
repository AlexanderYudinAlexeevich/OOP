#pragma once
#include "Item.h"

class Fraction : public Item
{
public:
    int numerator;
    int denominator;

    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den)
    {
        if (den == 0)
        {
            denominator = std::numeric_limits<int>::max();
        }
    }

    ostream& print(ostream& os) override {
        os << numerator << "/" << denominator;
        return os;
    }

    friend ostream& operator<<(ostream& out, Fraction& frac)
    {
        return frac.print(out);
    }

    bool operator<(Item& other) override
    {
        Fraction& f = dynamic_cast<Fraction&>(other);
        return (double)numerator / denominator < (double)f.numerator / f.denominator;
    }

    double abs() const
    {
        return std::abs((double)numerator / denominator);
    }
};
