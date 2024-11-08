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
void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory);

//// Function to process events for a given time period
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period);

// Function to display the current state of the inventory
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

int main() {
	// Initialize dogInventory map
	map<string, array<list<Dog>, 3>> dogInventory;

	// Load initial data from external file
	load_data("dogs_data.txt", dogInventory);

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
void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory) {

    string dogID, breed, status;
    int age;
    // Open the file
    // If file does not open, print an error and exit
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        exit(1);
    }

    // Read data from file line by line
        // For each line, extract dogID, breed, age, and status
        // Create a Dog object with the extracted data
        // Insert the Dog object into the appropriate list within the map based on breed and status

    while (file >> dogID >> breed >> age >> status) {
        Dog dog = { dogID, breed, age };

        //here, i'm going to insert a dog object to the appropriate list based on its status
        if (status == "Available") {
            inventory[breed][0].push_back(dog); //using pushback
        }
        else if (status == "Available") {
            inventory[breed][0].push_back(dog); //using pushback
        }
        else if (status == "Available") {
            inventory[breed][0].push_back(dog); //using pushback
        }
        else if (status == "Available") {
            inventory[breed][0].push_back(dog); //using pushback
        }
    }

    // Close the file
    file.close();
}

//// Function to process events for a given time period
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period) {
    //For each breed in map, we're going to do the following..............

    //Simulate adoptions
      // Randomly decide if a dog is adopted
      // If adopted, move dog from Available list to Adopted list


    //Simulate returns
     // Randomly decide if a dog is returned
     // If returned, move dog from Adopted list back to Available list


   //Simulate reservations
    // Randomly decide if a dog is reserved
    // If reserved, move dog from Available list to Reserved list


    //Simulate reservations cancellations
     // Randomly decide if a reservation is canceled
     // If canceled, move dog from Reserved list back to Available list
}
 
// Function to display the current state of the inventory
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period) {
    // Print header with current time period

  // Iterate through each breed in the map
      // Print breed name
      // Print Available Dogs
          // Iterate through Available list and print dog details
      // Print Adopted Dogs
          // Iterate through Adopted list and print dog details
      // Print Reserved Dogs
          // Iterate through Reserved list and print dog details
      // Print separator
}