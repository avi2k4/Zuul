#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class Room {
	public: 
		Room(char * name, char * description);
		~Room() { }

		char * getName();
		char * getDescription();
		void addItem(Item * item);
		void removeItem(Item * item);
		void addExit(pair<char *, Room *> exit);
		void print();

	private:
		char name[25];
		char description[150];
		vector<Item *> items;
		map<char *, Room *> exits;
};
