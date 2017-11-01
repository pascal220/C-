#include <iostream>
#include <string>
#include <cmath>
#include "Class_Def.h"
#include "Func_Def.h"

using namespace std;

//Contructors and Destructors
Prey::Prey()//Constructor for Prey
{
pos_x = 0;
pos_y = 0;
robot_dir = "north";
}

Prey::~Prey(){}//Destructor for Prey

//Getting functions --------------------------
int Prey::getXPos()
{
return pos_x;
}

int Prey::getYPos()
{
return pos_y;
}

std::string Prey::getDir()
{
return robot_dir;
}

//Setting functions -------------------------
void Prey::setXPos(int val, std::string flag)
{
if(flag == "m"){
pos_x += val;}
else{pos_x = val;}
}

void Prey::setYPos(int val, std::string flag)
{
if(flag == "m"){
pos_y += val;}
else{pos_y = val;}
}

void Prey::setDir(string val)
{
robot_dir = val;
}

//Functioning functions --------------------
void Prey::moveForward()
{
if (getDir() == "north")
{
setYPos(-1,"m");
}
else if (getDir() == "south")
{
setYPos(1,"m");
}
else if (getDir() == "east")
{
setXPos(1,"m");
}
else if (getDir() == "west")
{
setXPos(-1,"m");
}
};

void Prey::moveBackward()
{
if (getDir() == "north")
{
setYPos(1,"m");
}
else if (getDir() == "south")
{
setYPos(-1,"m");
}
else if (getDir() == "east")
{
setXPos(-1,"m");
}
else if (getDir() == "west")
{
setXPos(1,"m");
}
};

void Prey::turnLeft()
{
if (getDir() == "north")
{
setDir("west");
}
else if (getDir() == "south")
{
setDir("east");
}
else if (getDir() == "east")
{
setDir("north");
}
else if (getDir() == "west")
{
setDir("south");
}
};

void Prey::turnRight()
{
if (getDir() == "north")
{
setDir("east");
}
else if (getDir() == "south")
{
setDir("west");
}
else if (getDir() == "east")
{
setDir("south");
}
else if (getDir() == "west")
{
setDir("north");
}
};

//THE function. Chasing strategy for the Robots to catch the player. (seems to work best when scaled)
void Predator::Catch_Prey(int PlayerY, int PlayerX, string PlayerDir)
{
//Saving the current position of the robot as a variables
int PosY = getYPos();
int PosX= getXPos();

//THe distance between the player and current Robot in both y and x-axis
int diffY = abs(PlayerY-PosY);
int diffX = abs(PlayerX-PosX);

//If the difference is the same in both axis we are on the diagonal from the player. We would like to move so as to crosse his path based on the current direction
if (diffY==diffX)
{
	if (PlayerDir == "north" || PlayerDir == "south")//If the player is facing the y-axis
	{
		if (PlayerX<PosX)//To the right of the player
		{
			if (getDir()=="west"){moveForward();}
			else if (getDir()=="east"){moveBackward();}
			else if (getDir()=="north"){turnLeft();}
			else if (getDir()=="south"){turnRight();}
		}
		else if (PlayerX>PosX)//To the left of the player
		{
			if (getDir()=="west"){moveBackward();}
			else if (getDir()=="east"){moveForward();}
			else if (getDir()=="north"){turnRight();}
			else if (getDir()=="south"){turnLeft();}
		}
	}
	else if (PlayerDir == "east" || PlayerDir == "west")//If the player is facing the x-axis
	{
		if (PlayerY<PosY)//Bellow the player
		{
			if (getDir()=="west"){turnRight();}
			else if (getDir()=="east"){turnLeft();}
			else if (getDir()=="north"){moveForward();}
			else if (getDir()=="south"){moveBackward();}
		}
		else if (PlayerY>PosY)//Above the player
		{
			if (getDir()=="west"){turnLeft();}
			else if (getDir()=="east"){turnRight();}
			else if (getDir()=="north"){moveBackward();}
			else if (getDir()=="south"){moveForward();}
		}
	}
}
else if (diffY>diffX)//The bigger difference is in the y-axis so we want to make that one smaller
{
	if (PlayerY<PosY)//The robot is bellow the player 
	{
		if (getDir()=="west"){turnRight();}
		else if (getDir()=="east"){turnLeft();}
		else if (getDir()=="north"){moveForward();}
		else if (getDir()=="south"){moveBackward();}
	}
	else if (PlayerY>PosY)//The robot is above the player
	{
		if (getDir()=="west"){turnLeft();}
		else if (getDir()=="east"){turnRight();}
		else if (getDir()=="north"){moveBackward();}
		else if (getDir()=="south"){moveForward();}
	}

}
else if (diffY<diffX)//The bigger difference is in the x-axis so we want to make that one smaller
{
	if (PlayerX<PosX)//The robot is to the right of the player
	{
		if (getDir()=="west"){moveForward();}
		else if (getDir()=="east"){moveBackward();}
		else if (getDir()=="north"){turnLeft();}
		else if (getDir()=="south"){turnRight();}
	}
	else if (PlayerX>PosX)//Is to the left of the player
	{
		if (getDir()=="west"){moveBackward();}
		else if (getDir()=="east"){moveForward();}
		else if (getDir()=="north"){turnRight();}
		else if (getDir()=="south"){turnLeft();}
	}
}
};


















