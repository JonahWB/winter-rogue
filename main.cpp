#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include "player.h"

//declarations
std::string PickDirection();

//sets the max and min size of the room
const int minimum_size = 5;
const int maximum_size = 20;

//returns the map array. It's a 2d array and currently a single room with walls and a door
int** generateMapArray(int width, int length)
{
	int** array; 
	int doorWallLength;
	int doorPosition;

	//pick wall
	std::string doorWall = PickDirection();

	//Get position of door on the door wall
	if (doorWall == "East" || doorWall == "West")
		doorWallLength = length - 2;
	if (doorWall == "North" || doorWall == "South")
		doorWallLength = width - 2;
	doorPosition = (rand() % doorWallLength) + 1;

	//create the actual array	
	array = new int*[width];
	for(int i = 0; i < width; i++)
		array[i] = new int[length];
	
	for(int i = 0; i < width; i++)
		for(int j = 0; j < length; j++)
			if(i == 0 || i == width-1 || j == 0 || j == length-1) {
				array[i][j] = 1;
			} else
				array[i][j] = 0;
	
	//place the door
	if (doorWall == "East"){
		array[width - 1][doorPosition] = 2;
	}
	if (doorWall == "West"){
		array[0][doorPosition] = 2;
	}
	if (doorWall == "North"){
		array[doorPosition][0] = 2;
	}
	if (doorWall == "South"){
		array[doorPosition][length - 1] = 2;
	}

	return array;
}

//Returns "North" "South" "East" or "West" randomly
std::string PickDirection(){
	int DirectionNumber;
	DirectionNumber = (rand() % 4)+1;
	switch (DirectionNumber)
	{
		case 1: return "North";
			break;
		case 2: return "East";
			break;
		case 3: return "West";
			break;
		case 4: return "South";
			break;
	}
}

//returns a random number that fits the min and max room sizes
int getSize()
{
	return (rand() % (maximum_size - minimum_size)) + minimum_size;
}

int main()
{
        srand(time(NULL));

	int width = getSize();
	int length = getSize();

	std::string input;

	int** map = generateMapArray(width,length);

	player player1(1,1);

	//this is the game loop. It terminates when the player is on a door
	while(map[player1.getX()][player1.getY()] != 2) {
		for(int j = 0; j < length; j++) {
			std::cout << "\n";
			for(int i = 0; i < width; i++) {
				if(player1.getX() == i && player1.getY() == j) {
					std::cout << "X";
				} else if(map[i][j] == 0) {
					std::cout << " ";
				} else if(map[i][j] == 1) {//wall
					std::cout << "#";
				} else if(map[i][j] == 2)//Door
					std::cout << " ";
			}
		}

		std::cout << "\n" << "\n";

		std::cout << "what now? ";

		std::cin >> input;

		player1.move(input,map);

	}

	//draws the map one more time
	for(int j = 0; j < length; j++) {
		std::cout << "\n";
		for(int i = 0; i < width; i++) {
			if(player1.getX() == i && player1.getY() == j) {
				std::cout << "X";
			} else if(map[i][j] == 0) {
				std::cout << " ";
			} else if(map[i][j] == 1) {//wall
				std::cout << "#";
			} else if(map[i][j] == 2)//Door
				std::cout << " ";
		}
	}

	std::cout << "\n" << "\n";

	std::cout << "You Won!\n";

	//deletes the map
	for(int i = 0; i < width; i++)
		delete[] map[i];
	delete[] map;
}
