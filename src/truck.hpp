#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "table.hpp"
#include <iostream>
#include <string>

using namespace std;

// Truck class representing a movable truck robot on a table.
class Truck {
public:
    // constructors
    Truck();
    Truck(int x, int y, string f, Table& table);

    enum class Direction {
        NORTH, 
        SOUTH,
        EAST,
        WEST,
        ERROR
    };

    // moves the truck one unit forward in the direction (f) its facing. Blocks out of bounds movement.
    void move();

    // turns truck 90 degrees left
    void left();

    // turns truck 90 degrees right
    void right();

    // prints the truck’s current position and facing direction
    void report();

private:

    int selfX, selfY;
    Direction facing;

    // pointer to the Table object representing the map
    Table* tablePtr;

    // helper function to conver a string to the corresponding Direction enum
    static Direction setDirection(const string& f);

};

// overloaded << operator to output direction enum as text
ostream& operator<<(ostream& os, Truck::Direction facing);

#endif
