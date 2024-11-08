//DISCLAIMER!!!!! I ARCHIVED BOTH MOCKUP.CPP AND PSEUDOCODE.CPP IN ORDER TO CREATE MAIN!!
//so if you see alot of copying and pasting, its due to the fact that the code was already written

#include <iostream>
#include <list>
#include <array>
#include <map>
#include <string>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

// Define the Dog structure
struct Dog {
    string dogID;
    string dogBreed;
    int dogAge;
};

// Function Prototypes
void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory);
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period);
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

int main() {
    // Step 1: Initialize the dogInventory map
    map<string, array<list<Dog>, 3>> dogInventory;

    // Step 2: Load data from the external file
    load_data("dogs_data.txt", dogInventory);

    return 0;
}

void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory) {

}
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period) {

}
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period) {

}