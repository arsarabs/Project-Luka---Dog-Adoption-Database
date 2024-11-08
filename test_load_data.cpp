#include <iostream>
#include <map>
#include <array>
#include <list>
#include "Dog.hpp"

using namespace std;

// Prototypes
void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory);
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

int main() {

	map<string, array<list<Dog>, 3>> dogInventory;
	cout << "Testing load_data with valid data:" << endl;
	load_data("dogs_data.txt", dogInventory);
	display_inventory(dogInventory, 1);

	cout << "Testing load_data with a non-existent file:" << endl;
	load_data("invalid_file.txt", dogInventory);
	return 0;
}