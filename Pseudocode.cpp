// Include necessary headers
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <array>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

//Dog structure
struct Dog {
	string dogID;
	string dogBreed;
	int dogAge;
};

//Prototypes
 
// Function to load data from external file
void loadData(const string& fileName, map<string, array<list<Dog>, 3>>& invetory);

//// Function to process events for a given time period
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period);

// Function to display the current state of the inventory
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

int main() {
	// Initialize dogInventory map
	map<string, array<list<Dog>, 3>> dogInventory;

	// Load initial data from external file
	loadData("dogs_data.txt", dogInventory);

    // Simulate 25 time periods
    for (int period = 0; period < 25; period++) {
        // Display inventory before processing events
        display_inventory(dogInventory, period);

        // Process events for this period
        process_events(dogInventory, period);

        // Display inventory after processing events
        display_inventory(dogInventory, period);
    }

	return 0;
}

// Function to load data from external file
void loadData(const string& fileName, map<string, array<list<Dog>, 3>>& invetory) {

}

//// Function to process events for a given time period
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period) {

}
 
// Function to display the current state of the inventory
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period) {

}