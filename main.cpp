#include<iostream>
#include<stdlib.h>
#include<time.h>

const int minimum_size = 5;
const int maximum_size = 20;



int generateMapArray(int width, int length)
{

}

int getSize()
{
	return (rand() % (maximum_size - minimum_size)) + minimum_size;
}

int main()
{
        srand(time(NULL));

	int map [22] [22]; // Create largest size map possible
	std::cout << "Hey, We are alive.\n";
	const int width = getSize();
	const int length = getSize();
	std::cout << "The length is " << length << ".\n";
}
