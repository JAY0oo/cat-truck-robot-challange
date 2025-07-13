#include "table.hpp"

Table::Table(int w, int h)  : selfWidth(w), selfHeight(h) {};

bool Table::isValidPosition(int x, int y) {
    
    if (x < 0 || x > selfWidth || y < 0 || y > selfHeight ) {
        return false;
    } else return true;
    
}