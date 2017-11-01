#include <iostream>
#include <string>
#include <cmath>
#include "Class_Def.h"
#include "Func_Def.h"

using namespace std;

/*The options function. Here we can change the number of robots we play against or the size of the map.*/
void Options(int* robots,int* mapx,int* mapy)
{
//Initialise some variables
string answer_opt;
float answer_map;
bool flag_opt;

do{
do{
cout<<"|---------------OPTIONS---------------|"<<endl;//What option the player would like to choose, what parameter to change
cout<<"To change number of predators: Press 1"<<endl<<"To change map size: Press 2"<<endl<<"To go back: Press 3"<<endl;
getline(cin,answer_opt);

if (answer_opt == "1"||answer_opt == "2"||answer_opt == "3")
{
flag_opt = true;
}
else
{
cout<<"Please chose a valid option."<<endl<<"|------------------||----------------|"<<endl;
}
}while (flag_opt == false);//Making sure that the option picked is valabule. 

if (answer_opt == "1")//If option 1 we change the numebr of oponents
{
do
{
cout<<"How many opponents would you like to defeat?"<<endl;
cin>>*robots;
if (*robots<=1)//No less than 2 robots can be picked.
{
cout<<"Robot number has to be bigger then one. Don't make it to easy for your self."<<endl;
}
}while(*robots<=1);
}
else if (answer_opt == "2")//Option 2 let's change the size of the map in both y and x-axis.
{
cout<<"Please specify height of your map."<<endl;
cin>>answer_map;
*mapy = (int) abs(answer_map);//To make sure the user does not use negativ values
cout<<"Please specify width of your map."<<endl;
cin>>answer_map;//To make sure the user does not use negativ values
*mapx = (int) abs(answer_map);
}

}while (answer_opt!="3");//Option 3 leaves the options menu
};
