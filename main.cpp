#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include "player.h"

//declarations
std::string PickDirection();

const int minimum_size = 5;
const int maximum_size = 20;

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

	
	array = new int*[width];
	for(int i = 0; i < width; i++)
		array[i] = new int[length];
	
	for(int i = 0; i < width; i++)
		for(int j = 0; j < length; j++)
			if(i == 0 || i == width-1 || j == 0 || j == length-1) {
				array[i][j] = 1;
			} else
				array[i][j] = 0;
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

	while(map[player1.getX()][player1.getY()] != 2) {
		for(int j = 0; j < length; j++) {
			std::cout << "\n";
			for(int i = 0; i < width; i++) {
				if(player1.getX() == i && player1.getY() == j) {
					std::cout << "i";
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

	for(int j = 0; j < length; j++) {
		std::cout << "\n";
		for(int i = 0; i < width; i++) {
			if(player1.getX() == i && player1.getY() == j) {
				std::cout << "i";
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

	for(int i = 0; i < width; i++)
		delete[] map[i];
	delete[] map;
}
