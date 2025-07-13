#include "truck.hpp"
#include "table.hpp"

#include <iostream>
#include <string>

Truck::Truck(int x, int y, string f, Table& table) : selfX(x), selfY(y), facing(setDirection(f)), tablePtr(&table) {

    // checks initial placement of the truck as its constructed
    if (!table.isValidPosition(selfX, selfY)) throw invalid_argument("TRUCK OUT OF BOUNDS!!");
    
    if (facing == Direction::ERROR) throw invalid_argument("Invalid Direction!!");

};

void Truck::move() {

    int newX = selfX, newY = selfY;

    switch (facing) {
        case Direction::NORTH:
            newY += 1;
            break;
        
        case Direction::SOUTH:
            newY -= 1;
            break;
        
        case Direction::WEST:
            newX -= 1;
            break;
        
        case Direction::EAST:
            newX += 1;
            break;
    };

    // update position only if the new location is within table bounds
    if (tablePtr->isValidPosition(newX, newY)) {
        selfX = newX;
        selfY = newY;
    } else cout << "Movement blocked! Truck will fall!!" <<endl;

};

void Truck::left() {

    switch (Truck::facing) {
        case Direction::NORTH:
           facing = Direction::WEST;
            break;
        
        case Direction::SOUTH:
            facing = Direction::EAST;
            break;
        
        case Direction::WEST:
            facing = Direction::SOUTH;
            break;
        
        case Direction::EAST:
            facing = Direction::NORTH;
            break;
    };
};

void Truck::right() {

        switch (Truck::facing) {
        case Direction::NORTH:
           facing = Direction::EAST;
            break;
        
        case Direction::SOUTH:
            facing = Direction::WEST;
            break;
        
        case Direction::WEST:
            facing = Direction::NORTH;
            break;
        
        case Direction::EAST:
            facing = Direction::SOUTH;
            break;
    };
}

void Truck::report() {

    cout << "Position: (x:" << selfX << ", y:" << selfY << ") " << "Facing: " << facing <<endl;
}


Truck::Direction Truck::setDirection(const string& facing) {

    if (facing == "NORTH") return Truck::Direction::NORTH;
    if (facing == "SOUTH") return Truck::Direction::SOUTH;
    if (facing == "EAST") return Truck::Direction::EAST;
    if (facing == "WEST") return Truck::Direction::WEST;

    return Truck::Direction::ERROR;
}

ostream& operator<<(ostream& os, Truck::Direction facing) {

    switch (facing) {
        case Truck::Direction::NORTH: return os << "NORTH";
        case Truck::Direction::SOUTH: return os << "SOUTH";
        case Truck::Direction::EAST: return os << "EAST";
        case Truck::Direction::WEST:return os << "WEST";

    };
}



