#include <iostream>
#include <string>
#include <cmath>
#include "Class_Def.h"
#include "Func_Def.h"

using namespace std;

/*The main file. The start menu is here, and all the options for the game.*/
int main(int argc, char *argv[])
{
//Initialise the some variables, as well as the defult size of map and number of robots
string answer;
bool flag = false;
int map_x = 7, map_y = 5, no_robots = 2;

cout<<"-----------------| Welcome to Predator and Prey |------------------ "<<endl;//Welcome!

do{
do{
cout<<"|------------GAME MENU------------|"<<endl;//Game menu
cout<<"Start the Game: Press 1"<<endl<<"How to play: Press 2"<<endl<<"Options: Press 3"<<endl<<"Quit game: Press 4"<<endl;
getline(cin,answer);

if (answer=="1"||answer=="2"||answer=="3"||answer=="4")//Making sure that the user picked one of the 4 valabule options
{
flag = true;
}
else
{
cout<<"Please chose a valid option."<<endl<<"|-----------------||--------------|"<<endl;//If the player did not...
}
}while (flag == false);

if (answer == "3")//Option 3 leads to the options menu to set map size and robot numebr
{
Options(&no_robots,&map_x,&map_y);
}
else if (answer == "2")//Option 2 leads to the game manual
{
Manual();
}
else if (answer == "1")//Option 1 let's play the game and have fun. 
{
In_Game(&no_robots,&map_x,&map_y);
}

}while (answer!="4");//Option 4 quits the game 

cout<<"|--------Goodbey thank you for playing--------|"<<endl;//Bey bey
return 0;
}
