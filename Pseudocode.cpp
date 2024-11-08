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
        else if (status == "Adopted") {
            inventory[breed][1].push_back(dog); //using pushback
        }
        else if (status == "Reserved") {
            inventory[breed][2].push_back(dog); //using pushback
        }
        else {
            cout << "ERROR: Unknown " << status << " for dog ID " << dogID << endl;
        }
    }

    // Close the file
    file.close();
}

//// Function to process events for a given time period
void process_events(map<string, array<list<Dog>, 3>>& inventory, int period) {
    // Initialize random number generator
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    mt19937 generate(seed);
    uniform_int_distribution<int> eventDist(1, 4); // 1: Adopt, 2: Return, 3: Reserve, 4: Cancel Reservation

    //Simulate adoptions
  
     // Loop through each breed and its associated lists in the inventory map
    for (auto& entry : inventory) {
        string breed = entry.first; // Extract the breed name (map key)
        auto& lists = entry.second;  // Extract the array of lists for this breed (map value)

        //check to see if dogs avaiable
        //here's my reasoning for the code below
        if (!lists[0].empty()) { // Check if there are dogs available for adoption in the first list
            int event = eventDist(generate); // Randomly decide an event type
            if (event == 1) {  // If the event is an adoption (event == 1)
                //adpot a dog
                uniform_int_distribution<int> adoptDist(0, lists[0].size() - 1); // Distribution to randomly select a dog from the available list
                int adoptIndex = adoptDist(generate); // Get a random index for the dog to adopt
                auto it = lists[0].begin(); // Iterator pointing to the beginning of the available list
                advance(it, adoptIndex); // advance the iterator to randomly selected dog
                cout << "Adopted dog " << it->dogID << " from " << breed << "breed" << endl;
                lists[1].push_back(*it); // move adopted dog to appropriate list
                lists[0].erase(it); //  // remove adopted dog to appropriate list
            }
        }

    //Simulate returns
    // Randomly decide if a dog is returned
    // If returned, move dog from Adopted list back to Available list
        if (!lists[1].empty()) { 
            int event = eventDist(generate); 
            if (event == 2) {  
                //adpot a dog
                uniform_int_distribution<int> returnDist(0, lists[1].size() - 1); 
                int returnIndex = returnDist(generate);
                auto it = lists[0].begin();
                advance(it, returnIndex);
                cout << "Returned dog " << it->dogID << " from " << breed << "breed" << endl;
                lists[0].push_back(*it); 
                lists[1].erase(it); 
            }
        }


  //Simulate reservations
   // Randomly decide if a dog is reserved
   // If reserved, move dog from Available list to Reserved list
        if (!lists[0].empty()) {
            int event = eventDist(generate);
            if (event == 3) {
                //adpot a dog
                uniform_int_distribution<int> reserveDist(0, lists[0].size() - 1);
                int reserveIndex = reserveDist(generate);
                auto it = lists[0].begin();
                advance(it, reserveIndex);
                cout << "Reserved dog " << it->dogID << " from " << breed << "breed" << endl;
                lists[2].push_back(*it);
                lists[0].erase(it);
            }
        }

    //Simulate reservations cancellations
    // Randomly decide if a reservation is canceled
    // If canceled, move dog from Reserved list back to Available list
        if (!lists[2].empty()) {
            int event = eventDist(generate);
            if (event == 4) {
                //adpot a dog
                uniform_int_distribution<int> adoptDist(0, lists[2].size() - 1);
                int adoptIndex = adoptDist(generate);
                auto it = lists[2].begin();
                advance(it, adoptIndex);
                cout << "Adopted dog " << it->dogID << " from " << breed << "breed" << endl;
                lists[0].push_back(*it);
                lists[2].erase(it);
            }
        }
    }

}
 
// Function to display the current state of the inventory
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period) {
    cout << "======== Inventory Status at Time Period " << period << "====" << endl;

    for (const auto& breedEntry : inventory) {
        const string& dogBreed = breedEntry.first;
        const array<list<Dog>, 3>& lists = breedEntry.second;

        cout << "Breed: " << dogBreed << endl;

        // Display Available Dogs
        cout << "Available Dogs:" << endl;
        for (const auto& dog : lists[0]) {
            cout << "ID: " << dog.dogID << ", Breed: " << dog.dogBreed << ", Age: " << dog.dogAge << endl;
        }

        // Display Adopted Dogs
        cout << "Adopted Dogs:" << endl;
        for (const auto& dog : lists[1]) {
            cout << "ID: " << dog.dogID << ", Breed: " << dog.dogBreed << ", Age: " << dog.dogAge << endl;
        }

        // Display Reserved Dogs
        cout << "Reserved Dogs:" << endl;
        for (const auto& dog : lists[2]) {
            cout << "ID: " << dog.dogID << ", Breed: " << dog.dogBreed << ", Age: " << dog.dogAge << endl;
        }

        // Separator between breeds
        cout << "==========================================================================" << endl;
    }
}