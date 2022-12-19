#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

void clearInput();

vector<Room *> rooms; 
vector<Item *> inventory;
Room * currentRoom; 

int main() {
	// Initializing Items
	char * alphaKeyName = "The Alpha Key";
	Item * alphaKey = new Item(alphaKeyName); 
	
	char * betaKeyName = "The Beta Key";
	Item * betaKey = new Item(betaKeyName);

	char * gammaKeyName = "The Gamma Key";
	Item * gammaKey = new Item(gammaKeyName);

	char * appleName = "Apple";
	Item * apple = new Item(appleName);

	char * spoonName = "Large Spoon";
	Item * spoon = new Item(spoonName);

	// Initializing Rooms
	char * lobbyName = "Lobby";
	char * lobbyDesc = "This is the lobby. Nothing special about it.";
	Room * lobby = new Room(lobbyName, lobbyDesc);
	rooms.push_back(lobby);

	char * northHallName = "North Hall";
	char * northHallDesc = "The North hall";
	Room * northHall = new Room(northHallName, northHallDesc);

	char * eastHallName = "East Hall";
	char * eastHallDesc = "The East hall";
	Room * eastHall = new Room(eastHallName, eastHallDesc);

	char * southHallName = "South Hall";
	char * southHallDesc = "The South hall.";
	Room * southHall = new Room(southHallName, southHallDesc);

	char * westHallName = "West Hall";
	char * westHallDesc = "The West hall.";
	Room * westHall = new Room(westHallName, westHallDesc);

	char * masterKitchenName = "Master Kitchen";
	char * masterKitchenDesc = "The Master kitchen used by only the greatest of chefs.";
	Room * masterKitchen = new Room(masterKitchenName, masterKitchenDesc);

	char * theatreName = "Theatre";
	char * theatreDesc = "This theatre room has an iMax screen.";
	Room * theatre = new Room(theatreName, theatreDesc);

	char * closetName = "Closet";
	char * closetDesc = "The North hall";
	Room * closet = new Room(closetName, closetDesc);

	char * garageName = "Garage";
	char * garageDesc = "The North hall";
	Room * garage = new Room(garageName, garageDesc);

	char * northBathName = "North Wing Bathroom";
	char * northBathDesc = "The North hall";
	Room * northBath = new Room(northBathName, northBathDesc);

	char * southBathName = "South Wing Bathroom";
	char * southBathDesc = "The North hall";
	Room * southBath = new Room(southBathName, southBathDesc);

	char * basementName = "Basement";
	char * basementDesc = "The very scary basement...";
	Room * basement = new Room(basementName, basementDesc);

	char * wineCellarName = "Wine Cellar";
	char * wineCellarDesc = "The wine cellar with a large assortment of wines. Don't get drunk on your mission!";
	Room * wineCellar = new Room(wineCellarName, wineCellarDesc);

	char * foyerName = "Foyer";
	char * foyerDesc = "A very flower filled foyer";
	Room * foyer = new Room(foyerName, foyerDesc);

	char * diningRoomName = "Dining Room";
	char * diningRoomDesc = "Dining room desc";
	Room * diningRoom = new Room(diningRoomName, diningRoomDesc);

	lobby->addExit("NORTH", northHall);
	lobby->addItem(apple);

	cout << "\n\nWelcome to Zuul!" << endl;
	cout << "You are trapped in Avi's Manor; to leave, you have to find the Alpha Key, the Beta Key, and the Gamma Key and return them to the lobby." << endl;
	cout << "Good luck!\n" << endl;
	cout << "Commands:" << endl;
	cout << "To pick up an item: PICK" << endl;
	cout << "To drop an item: DROP" << endl;
	cout << "To use an exit: GO" << endl;
	cout << "To quit: QUIT\n" << endl; 

	currentRoom = lobby;

	while (true) {
		currentRoom->print();

		char input[10];
		cin >> input;
		clearInput();

		if (strcmp(input, "PICK") == 0) {
			if (currentRoom->getItems().empty()) {
				cout << "[!!!] There are no items you can pick up!" << endl;
			}
			else {
				cout << "Enter the associated number of the item you want to pick up!" << endl;

				int pickInput;
				cin >> pickInput;
				clearInput();
	
				Item * pickedItem = currentRoom->getItem(pickInput - 1);
				cout << "Sucessfully picked up " << pickedItem->getName() << endl;
				inventory.push_back(pickedItem);
				currentRoom->removeItem(pickedItem);
			}
		}
		else if (strcmp(input, "DROP") == 0) {
			if (inventory.empty()) {
				cout << "[!!!] There are no items you can drop!" << endl;
			}
			else {
				cout << "Inventory:" << endl;

				int i = 1;
				for (vector<Item *>::iterator it = inventory.begin(); it != inventory.end(); it++, i++) {
					cout << "[" << i << "] Name: " << (*it)->getName() << endl;
				}
				cout << "\nEnter the associated number of the item you want to drop!" << endl;

				int dropInput;
				cin >> dropInput;
				clearInput();

				Item * droppedItem = inventory[dropInput - 1];
				cout << "Successfully dropped " << droppedItem->getName() << endl;
				inventory.erase(inventory.begin() + (dropInput - 1));
				currentRoom->addItem(droppedItem);
			}

		}
		else if (strcmp(input, "GO") == 0) {
			cout << "Enter the exacct name of the exit you want to take!" << endl;

		}
		else if (strcmp(input, "QUIT") == 0) {
			break;
		}
	}

	/*	
	for (auto& item : mymap) {
		delete item.first;
		item.first = nullptr;
	}
*/
 	return 0;
}

void clearInput() {
	cin.ignore(25, '\n');
}
