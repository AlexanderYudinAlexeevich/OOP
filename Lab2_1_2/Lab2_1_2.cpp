#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

#include "Airplane.h"
#include "Fraction.h"
#include "Item.h"

using namespace std;


void push(list<shared_ptr<Item>>& list, const shared_ptr<Item>& newItem)
{
    auto it = lower_bound(list.begin(), list.end(), newItem);
    list.insert(it, newItem);
}

void pop(list<shared_ptr<Item>>& list)
{
    if (!list.empty())
    {
        list.pop_back();
    }
}

int main()
{
    setlocale(0, "RU");
    list<shared_ptr<Item>> fractionList;

    push(fractionList, make_shared<Fraction>(Fraction(1, 2)));
    push(fractionList, make_shared<Fraction>(Fraction(3, 4)));
    push(fractionList, make_shared<Fraction>(Fraction(5, 6)));
    push(fractionList, make_shared<Fraction>(Fraction(-2, 3)));
    push(fractionList, make_shared<Fraction>(Fraction(7, 8)));

    push(fractionList, make_shared<Airplane>(Airplane(10, 1000.0, "Prod 1", "Aeroflot", 800)));

    cout << "Ёлементы списка (исходный):" << endl;
    for (shared_ptr<Item>& item : fractionList)
    {
        cout << *item << endl;
    }

    return 0;
}
