#pragma once
#include <string>

#include "Item.h"

using namespace std;

class Airplane : public Item
{
private:
    int capacity;
    float flightRange;
    string producer;
    string name;
    float maxSpeed;

public:
    Airplane(int capacity, float flight_range, const string& producer, const string& name, float max_speed)
        : capacity(capacity),
          flightRange(flight_range),
          producer(producer),
          name(name),
          maxSpeed(max_speed)
    {
    }

    bool operator<(Item& other) override
    {
        Airplane& a = dynamic_cast<Airplane&>(other);
        return true;
    }

    ostream& print(ostream& os) override {
        os << name;
        return os;
    }

    friend ostream& operator<<(ostream& out, Airplane& a) {
        return a.print(out);
    }
};
