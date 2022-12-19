#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

Room::Room(char * name, char * description) {
	strcpy(this->name, name);
	strcpy(this->description, description);
}

char * Room::getName() {
	return this->name;
}

char * Room::getDescription() {
	return this->description;
}

void Room::addItem(Item * item) {
	this->items.push_back(item);
}

void Room::removeItem(Item * item) {
	for (vector<Item *>::iterator it = this->items.begin(); it != this->items.end(); it++) {
		if (strcpy((*it)->getName(), item->getName()) == 0) {
			this->items.erase(it);
			return;
		}
	}
}

void Room::addExit(pair<char *, Room *> exit) {

}

void Room::print() {
	cout << "Hello man" << endl;
}


