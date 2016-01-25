#include "player.h"

player::player(int setx, int sety) //will set the x and y on creation 
{
	x = setx;
	y = sety;
}

bool player::IsWalkable(int tileID) { //takes an item id, and returns true or false depending if the player can walk on the tile
	switch(tileID){
		case 0: return true;//floor
			break;
		case 1: return false;//wall
			break;
		case 2: return true;//door
			break;
		case 3: return true;//???? tbd
			break;

	}
}

void player::move(std::string input, int** map) { //for each direction, it tests if the direction is walkable, then moves into it

	if (input == "up" | input == "u") {
		if(this->IsWalkable(map[this->x][this->y - 1]))  {
			this->y--;
		} else { std::cout << "\nthat's a wall\n"; }

	} else if (input == "down" | input == "d") {
		if(this->IsWalkable(map[this->x][this->y + 1])) {
			this->y++;
		} else { std::cout << "\nthat's a wall\n"; }

	} else if (input == "right" | input == "r") {
		if(this->IsWalkable(map[this->x + 1][this->y])) {
			this->x++;
		} else { std::cout << "\nthat's a wall\n"; }

	} else if (input == "left" | input == "l") {
		if(this->IsWalkable(map[this->x - 1][this->y])) {
			this->x--;
		} else { std::cout << "\nthat's a wall\n"; }
	}
}

int player::getX()
{
	return x;
}

int player::getY()
{
	return y;
}
