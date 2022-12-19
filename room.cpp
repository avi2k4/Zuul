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
		if (strcmp((*it)->getName(), item->getName()) == 0) {
			this->items.erase(it);
			return;
		}
	}
}

vector<Item *> Room::getItems() {
	return this->items;
}

Item * Room::getItem(int index) {
	return this->items[index];
}

void Room::addExit(char * exitName, Room * destination) {
	this->exits[exitName] = destination;
}

Room * Room::getExitDestination(char * exitName) {
	for (map<char *, Room *>::iterator it = this->exits.begin(); it != this->exits.end(); it++) {
		cout << it->first << endl;
		if (strcmp(it->first, exitName) == 0) {
			return it->second;
		}
	}
}

void Room::print() {
	cout << "\n---------------------------------------------------------" << endl;
	cout << "You are currently in: " << this->name << endl;
	cout << this->description << endl;
	cout << "\nItems:" << endl;

	int i = 1;
	for (vector<Item *>::iterator it = this->items.begin(); it != this->items.end(); it++, i++) {
		cout << "[" << i << "] Name: " << (*it)->getName() << endl;		
	}

	int x = 1;
	cout << "Exits: " << endl;
	for (map<char *, Room *>::iterator it = this->exits.begin(); it != this->exits.end(); it++, x++) {
		cout << "[" << x << "] Name: " << it->first << ", destination: " << it->second->getName() << endl;
	}
	cout << "---------------------------------------------------------\n" << endl;
}


