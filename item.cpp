#include <iostream>
#include <cstring>
#include "item.h"

Item::Item(char * name) {
	strcpy(this->name, name);
}

char * Item::getName() {
	return this->name;
}
