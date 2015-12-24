#include<iostream>
#include<stdlib.h>
#include<time.h>

const int minimum_size = 5;
const int maximum_size = 20;

int** generateMapArray(int width, int length)
{
	int** array; 
	array = new int*[width];
	for(int i = 0; i < width; i++)
		array[i] = new int[length];
	
	for(int i = 0; i < width; i++)
		for(int j = 0; j < length; j++)
			if(i == 0 || i == width-1 || j == 0 || j == length-1) {
				array[i][j] = 1;
			} else
				array[i][j] = 0;

	return array;
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

	int** map = generateMapArray(width,length);

	for(int i = 0; i < width; i++) {
		std::cout << "\n";
		for(int j = 0; j < length; j++) {
			if(map[i][j] == 0) {
				std::cout << " ";
			} else if(map[i][j] == 1)
				std::cout << "#";
		}
	}

	std::cout << "\n" << "\n";

	for(int i = 0; i < width; i++)
		delete[] map[i];
	delete[] map;
}
