#ifndef CLASS_DEF
#define CLASS_DEF
#include <string>

using namespace std;

//The Class player. Most of the functionality is embedded in this class
class Prey
{
protected://Protected variables that will be shared with all the children of the class
int pos_x;
int pos_y;
string robot_dir;

public://All public functions for the class that can be used in any part of the program
Prey();
~Prey();

int getXPos();
int getYPos();
std::string getDir();

void setXPos(int,string);
void setYPos(int,string);
void setDir(string);

void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
};

//The robot class. It contains the one additional function of catching the player.
class Predator: public Prey
{
public:

void Catch_Prey(int PlayerY, int PlayerX, string PlayerDir);
};

#endif

