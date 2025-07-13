#include "table.hpp"
#include "truck.hpp"

#include <sstream>
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    static Table table;
    Truck* robotTruck = nullptr;
    
    // process each command passed as a CLI arguement
    for (int i = 1; i < argc; i++) {
        string command = argv[i];

        if(command == "PLACE") {
            // Expected format: PLACE x,y,DIRECTION - as one arguement as per CLI example
            stringstream ss(argv[++i]);

            string xStr, yStr, fStr;
            getline(ss, xStr, ',');
            getline(ss, yStr, ',');
            getline(ss, fStr, ',');
            
            // Attempt to place the robot on the table handle invalid position or direction
            try {
                robotTruck = new Truck(stoi(xStr), stoi(yStr), fStr, table);
            } catch (const invalid_argument& e) {
                cout << e.what() <<endl;
            };
  
        }
        else if (robotTruck != nullptr) {

            if (command == "MOVE") robotTruck->move();
            else if (command == "RIGHT") robotTruck->right();
            else if (command == "LEFT") robotTruck->left();
            else if (command == "REPORT") robotTruck->report();

            else cout << "Uknowm command: " << command <<endl;

        } else cout << "Robot Missing!!" <<endl;

    };

    if(robotTruck != nullptr) delete robotTruck;

    return 0;
}