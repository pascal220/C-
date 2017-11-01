#include <iostream>
#include <string>
#include <cmath>
#include "Class_Def.h"
#include "Func_Def.h"

using namespace std;

/*With this function we print the rules of the game for the player. Instructing her/him how to play.*/
void Manual()
{
cout<<"|-----This is the Predator-Prey game!-----|"<<endl;
sleep(2);
cout<<"|-----YOU are the Prey!-----|"<<endl;
sleep(2);
cout<<"|-----A any number of predators will try to catch you.-----|"<<endl;
sleep(3);
cout<<"|-----On a maps of various sizes.-----|\n"<<endl;
sleep(2);
cout<<"|-----Your goal is to escape the map before the predators catch you. The game is turn based. During your turn, you can move forward or backward; or turn on the spot, left or right. First you move then all the predators, then you again etc. Till either you lose or the predators make a mistake.-----|\n"<<endl;
sleep(20);
cout<<"|-----May the odds by ever in your favor!-----|"<<endl;
sleep(5);
};
