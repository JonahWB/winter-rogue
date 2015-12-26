#include "player.h"

player::player(int setx, int sety) 
{
	x = setx;
	y = sety;
}

bool player::IsWalkable(int tileID) {
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

void player::move(std::string input, int** map) {

	if (input == "up") {
		if(this->IsWalkable(map[this->x][this->y - 1]))  {
			this->y--;
		} else { std::cout << "\nthat's a wall\n"; }

	} else if (input == "down") {
		if(this->IsWalkable(map[this->x][this->y + 1])) {
			this->y++;
		} else { std::cout << "\nthat's a wall\n"; }

	} else if (input == "right") {
		if(this->IsWalkable(map[this->x + 1][this->y])) {
			this->x++;
		} else { std::cout << "\nthat's a wall\n"; }

	} else if (input == "left") {
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