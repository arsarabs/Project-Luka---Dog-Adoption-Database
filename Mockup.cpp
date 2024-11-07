#include <iostream>
#include <list>
#include <array>
#include <map>
#include <string>

using namespace std;

//Dog structure
struct Dog {
	string dogID;
	string dogBreed;
	int dogAge;
};

void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

int main() {
    // Initialize dogInventory with one breed and one dog in each list
    map<string, array<list<Dog>, 3>> dogInventory;
    dogInventory["Labrador"] = {
        list<Dog>{ { "D001", "Labrador", 3 } },  // Available
        list<Dog>{ { "D002", "Labrador", 5 } },  // Adopted
        list<Dog>{ { "D003", "Labrador", 2 } }   // Reserved
    };

    // Display the inventory for period 1
    display_inventory(dogInventory, 1);
	return 0;
}

void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period) {
    cout << "======== Inventory Status at Time Period " << period <<  "====" << endl;

    for (const auto& breedEntry : inventory) {
        const string& dogBreed = breedEntry.first;
        const array<list<Dog>, 3>& lists = breedEntry.second;

        cout << "Breed: " << dogBreed << endl;

        // Display Available Dogs
        cout << "Available Dogs:" << endl;

        // Display Adopted Dogs
        cout << "Adopted Dogs:" << endl;

        // Display Reserved Dogs
        cout << "Reserved Dogs:" << endl;

        // Separator between breeds
        cout << "----------------------------------------" << endl;
    }
}