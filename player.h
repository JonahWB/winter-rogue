#include<string>
#include<iostream>

#ifndef PLAYER_H
#define PLAYER_H

class player
{
	public:
		player(int, int); //starting x, y
		bool IsWalkable(int);
		void move(std::string, int**);
		int getX();
		int getY();

	private:		
		int x;
		int y;
	
};

#endif
