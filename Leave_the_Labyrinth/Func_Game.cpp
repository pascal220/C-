#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include "Class_Def.h"
#include "Func_Def.h"

using namespace std;

/*The game fucntion. Where all the cool and exciting stuff is hapenning.*/
void In_Game(int* no_robots,int* mapx,int* mapy)//Start function
{
//Initialise all the aprameters ===============================================================================================
char map[*mapy][*mapx];
Prey player;
Predator robots[*no_robots];
bool flag_exit, flag_game, flag;
int i=0,j=0,position_x=0,position_y=0;
string answer;

//Say cool stuff to the player ================================================================================================
cout<<"\nLet the games beggin! Be careful, Predators like to feed on the weak."<<endl<<"Move your robot by typing in commands: 'move forward', 'move backwards', 'turn left', 'turn right'."<<endl<<"Best of luck!"<<endl;
sleep(5);

//The main game do/while loop =================================================================================================
do
{
//Set do/while loop flags -----------------------------------------------------------------------------------------------------
flag_exit = false;
flag_game = false;
flag = false;
srand(time(NULL));//Intilize randomiser with time
//Initialise the player. About in the middle of the map in a 2x2 box ----------------------------------------------------------
player.setXPos(1,"i");
player.setYPos(1,"i");
player.setXPos(*mapx/2 - (rand() % 1),"m");
player.setYPos(*mapy/2 - (rand() % 1),"m");
//Initialise the robots. Randomly anywhere on the map. Every robot is palced at a different location. -------------------------
for (i=0;i<*no_robots;i++)
{
robots[i].setXPos(1,"i");
robots[i].setYPos(1,"i");
robots[i].setXPos((rand() % *mapx),"m");
robots[i].setYPos((rand() % *mapy),"m");
}

//The chasing eachother do/while loop, where the robots hunt the player =======================================================
do
{
//Fill map with some stuff ----------------------------------------------------------------------------------------------------
for(i=0;i<*mapy;i++)//Empty spaces are filled with a '0'
{
for(j=0;j<*mapx;j++)
{
map[i][j]='0';
}
}
map[player.getYPos()-1][player.getXPos()-1]='X';//We mark the player with an 'X'
for(i=0;i<*no_robots;i++)
{
map[robots[i].getYPos()-1][robots[i].getXPos()-1]='R';//We mark the robots with an 'R'
}
//Print the map and educating the player -------------------------------------------------------------------------------------
cout<<"\n* ------------ The Map ------------ *"<<endl;
for(i=0;i<*mapy;i++)
{
for(j=0;j<*mapx;j++)
{
cout<<" "<<map[i][j]<<" ";
}
cout<<endl;
}
sleep(1);
cout<<"Your direction is: "<<player.getDir()<<endl;
sleep(1);
for (i=0;i<*no_robots;i++)
{
cout<<"Robot "<<i+1<<" direction(y/x) is: "<<robots[i].getDir()<<"("<<robots[i].getYPos()<<"/"<<robots[i].getXPos()<<")"<<endl;
sleep(1);
}
sleep(1);
// The palyer has to make a decision based on where he/she is and how big of a mess they are in ==============================
do
{
//Here we ask the biggest palyer (aka. hindrance) what does it want to do? ---------------------------------------------------------
cout<<"\nHow would you like to escape?"<<endl;
getline(cin,answer);//Read in players decision into a string
//Change the string into all capitals and no spaces.
for (i=0;i<answer.length();i++)
{
if(answer[i]==' ')
{
answer.erase(i,1);
i--;
}else {answer[i] = toupper(answer[i]);}
}
//Let's see what does player want to do --------------------------------------------------------------------------------------
if (answer=="MOVEFORWARD"||answer=="MOVEBACKWARD"||answer=="TURNLEFT"||answer=="TURNRIGHT")
{
flag = true;
}
else
{
cout<<"We apologise, but you typed an incorect instruction."<<endl;//If the player taped an incorrect command we infrom them of it. 
}
}while(flag != true);
//Player moving -------------------------------------------------------------------------------------------------------------
if (answer=="MOVEFORWARD") {player.moveForward();}
else if (answer=="MOVEBACKWARD") {player.moveBackward();}
else if (answer=="TURNLEFT") {player.turnLeft();}
else if (answer=="TURNRIGHT") {player.turnRight();}
//Let's check if the player won ---------------------------------------------------------------------------------------------
if (player.getYPos()<1 || player.getXPos()<1 || player.getYPos()>*mapy || player.getXPos()>*mapx)
{
flag_game = true;
sleep(1);
cout<<"\n-----CONGRATULATIONS YOU WON!!!(We hoped you would loose :D)-----"<<endl;//yaa...they won. :(
}
else{
//If the player did not win it is time for the robots to catch him =========================================================
for (i=0;i<*no_robots;i++)
{
robots[i].Catch_Prey(player.getYPos(),player.getXPos(),player.getDir());
}

//Now, did any of the robots catch the palyer? ------------------------------------------------------------------------------
for (i=0;i<*no_robots;i++)
{
if (robots[i].getYPos()==player.getYPos())
{
if (robots[i].getXPos()==player.getXPos())
{
flag_game = true;
sleep(1);
cout<<"As expected you loose. May be next time. :D"<<endl;//yaa...the player lost. :)
}}}}

}while(flag_game != true);//End of the game loop. Either the robots or the palyer won.


//We can play some more if we want to ======================================================================================
cout<<"Would you like another game?[Y/N]"<<endl;
cin>>answer;//Read in asnwer
for (i=0;i<answer.length();i++)//A pointless safe fail
{
answer[i] = toupper(answer[i]);
}
if (answer == "N"){flag_exit = true;}//If we don't want to play anymore we set the exit flag to "true"
}while(flag_exit != true);//Exit the game function --------------------------------------------------------------------------
}

