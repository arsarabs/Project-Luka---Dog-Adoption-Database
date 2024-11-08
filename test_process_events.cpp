#include <iostream>
#include <map>
#include <array>
#include <list>
#include "Dog.hpp"

using namespace std;

// Prototypes
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period);
void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory);
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

int main() {
    map<string, array<list<Dog>, 3>> dogInventory;

    load_data("dogs_data.txt", dogInventory);
    display_inventory(dogInventory, 0); // Initial state

    process_events(dogInventory, 1);
    display_inventory(dogInventory, 1); // After processing events
}