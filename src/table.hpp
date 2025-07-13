#ifndef TABLE_HPP
#define TABLE_HPP


// Table class representing a 2D grid/table used to define boundries and valid positions for the truck
class Table{

public:
    // constructor. Defaults to 5x5 grid unless specified.
    Table(int w = 5, int h = 5);

    int selfWidth, selfHeight;

    // returns true if robots (x, y) is within the table boundries
    bool isValidPosition(int x, int y);
};

#endif