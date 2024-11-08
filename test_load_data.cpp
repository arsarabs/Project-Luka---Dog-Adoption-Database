#include <iostream>
#include <map>
#include <array>
#include <list>
#include "Dog.hpp"

using namespace std;

// Prototypes
void load_data(const string& fileName, map<string, array<list<Dog>, 3>>& inventory);
void display_inventory(const map<string, array<list<Dog>, 3>>& inventory, int period);

