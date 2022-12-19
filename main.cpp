// Zuul by Avighnash Kumar, 12/18/22
// Escape Avi's Manor by collecting the Alpha, Beta, and Gamma keys!

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
	rooms.push_back(northHall);

	char * eastHallName = "East Hall";
	char * eastHallDesc = "The East hall";
	Room * eastHall = new Room(eastHallName, eastHallDesc);
	rooms.push_back(eastHall);

	char * southHallName = "South Hall";
	char * southHallDesc = "The South hall.";
	Room * southHall = new Room(southHallName, southHallDesc);
	rooms.push_back(southHall);

	char * westHallName = "West Hall";
	char * westHallDesc = "The West hall.";
	Room * westHall = new Room(westHallName, westHallDesc);
	rooms.push_back(westHall);

	char * masterKitchenName = "Master Kitchen";
	char * masterKitchenDesc = "The Master kitchen used by only the greatest of chefs.";
	Room * masterKitchen = new Room(masterKitchenName, masterKitchenDesc);
	rooms.push_back(masterKitchen);

	char * theatreName = "Theatre";
	char * theatreDesc = "This theatre room has an iMax screen.";
	Room * theatre = new Room(theatreName, theatreDesc);
	rooms.push_back(theatre);

	char * closetName = "Closet";
	char * closetDesc = "The North hall";
	Room * closet = new Room(closetName, closetDesc);
	rooms.push_back(closet);

	char * garageName = "Garage";
	char * garageDesc = "The North hall";
	Room * garage = new Room(garageName, garageDesc);
	rooms.push_back(garage);

	char * northBathName = "North Wing Bathroom";
	char * northBathDesc = "This bathroom is particularly spooky...";
	Room * northBath = new Room(northBathName, northBathDesc);
	rooms.push_back(northBath);

	char * southBathName = "South Wing Bathroom";
	char * southBathDesc = "A very large bathroom.";
	Room * southBath = new Room(southBathName, southBathDesc);
	rooms.push_back(southBath);

	char * basementName = "Basement";
	char * basementDesc = "The very scary basement...";
	Room * basement = new Room(basementName, basementDesc);
	rooms.push_back(basement);

	char * wineCellarName = "Wine Cellar";
	char * wineCellarDesc = "The wine cellar with a large assortment of wines. Don't get drunk on your mission!";
	Room * wineCellar = new Room(wineCellarName, wineCellarDesc);
	rooms.push_back(wineCellar);

	char * foyerName = "Foyer";
	char * foyerDesc = "There are a lot of flowers in this foyer!";
	Room * foyer = new Room(foyerName, foyerDesc);
	rooms.push_back(foyer);

	char * diningRoomName = "Dining Room";
	char * diningRoomDesc = "The dining table is overflowing with food... there is a lot of meat.";
	Room * diningRoom = new Room(diningRoomName, diningRoomDesc);
	rooms.push_back(diningRoom);

	// Setting up exits
	lobby->addExit("NORTH", northHall);
	lobby->addExit("EAST", eastHall);
	lobby->addExit("SOUTH", southHall);
	lobby->addExit("WEST", westHall);

	northHall->addExit("SOUTH", lobby);
	northHall->addExit("NORTH", northBath);
	northHall->addExit("WEST", masterKitchen);
	northHall->addExit("EAST", foyer);

	foyer->addExit("EXIT", northHall);
	northBath->addExit("EXIT", northHall);
	masterKitchen->addExit("EXIT", northHall);

	eastHall->addExit("SOUTH", theatre);
	eastHall->addExit("EAST", closet);
	eastHall->addExit("WEST", lobby);

	theatre->addExit("EXIT", eastHall);
	closet->addExit("EXIT", eastHall);
	closet->addExit("NORTH", wineCellar);
	wineCellar->addExit("EXIT", closet);

	westHall->addExit("NORTH", garage);
	westHall->addExit("WEST", basement);
	westHall->addExit("EAST", lobby);

	garage->addExit("EXIT", westHall);
	basement->addExit("EXIT", westHall);

	southHall->addExit("NORTH", lobby);
	southHall->addExit("EAST", southBath);
	southHall->addExit("WEST", diningRoom);

	diningRoom->addExit("EXIT", southHall);
	southBath->addExit("EXIT", southHall);

	// Setting up items
	wineCellar->addItem(alphaKey);
	southBath->addItem(betaKey);
	basement->addItem(gammaKey);
	westHall->addItem(spoon);
	lobby->addItem(apple);

	cout << "\n\nWelcome to Zuul!" << endl;
	cout << "You are trapped in Avi's Manor; to leave, you have to find the Alpha Key, the Beta Key, and the Gamma Key and return them to the lobby." << endl;
	cout << "Good luck!\n" << endl;
	cout << "Commands:" << endl;
	cout << "To pick up an item: PICK" << endl;
	cout << "To drop an item: DROP" << endl;
	cout << "To use an exit: GO" << endl;
	cout << "To quit: QUIT\n" << endl; 

	// Start in the lobby
	currentRoom = lobby;
	
	while (true) {
		// Check for win condition, if the user is in the lobby with the alpha, beta, and gamma keys.
		if (currentRoom == lobby) {
			if ((find(inventory.begin(), inventory.end(), alphaKey) != inventory.end()) &&
			    (find(inventory.begin(), inventory.end(), betaKey) != inventory.end()) &&
			    (find(inventory.begin(), inventory.end(), gammaKey) != inventory.end())) {
				cout << "\n--------------!!--------------" << endl;
				cout << "You have escaped! Congrats!" << endl;
				cout << "--------------!!--------------\n" << endl;
				break;
			}
		}

		currentRoom->print();

		char input[10];
		cin >> input;
		clearInput();

		if (strcmp(input, "PICK") == 0) {
			// If there are no items in the room
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
			// If the user's inventory contains no items
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
			cout << "Enter the exact name of the exit you want to take!" << endl;
			
			char goInput[25];
			cin.get(goInput, sizeof(goInput));
			cin.get();

			Room * destination = currentRoom->getExitDestination(goInput);
			currentRoom = destination;
		}
		else if (strcmp(input, "QUIT") == 0) {
			break;
		}
	}

 	return 0;
}

void clearInput() {
	cin.ignore(25, '\n');
}
