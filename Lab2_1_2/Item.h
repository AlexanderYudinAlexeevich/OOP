#pragma once
#include <ostream>

using namespace std;

class Item
{
    virtual bool operator<(Item& other) = 0;
    virtual ostream& print(ostream& os) = 0;
    friend ostream& operator<<(ostream& out, Item& a) { return a.print(out); }
};
