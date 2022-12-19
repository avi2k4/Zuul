#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

vector<Room *> rooms; 
vector<Item *> inventory;
Room * currentRoom; 

int main() {
	char * desc1 = "Bruh";
	Room * room1 = new Room(desc1);

	char * desc2 = "Lol nation";
	Room * room2 = new Room(desc2);

	currentRoom = room1;

	cout << currentRoom->getDescription() << endl;

	currentRoom = room2;

	cout << "New: " << currentRoom->getDescription() << endl;

	while (true) {
		
	}

	/*	
	for (auto& item : mymap) {
		delete item.first;
		item.first = nullptr;
	}
*/
 	return 0;
}
