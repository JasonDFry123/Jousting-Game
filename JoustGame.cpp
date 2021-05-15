#include"Weapon.h"
#include"Knight.h"
#include"Random.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// FIGHT!

int main() 
{
  ifstream gif;
  gif.open("joustdata.txt");
  string somestring;

    if(!gif.good())
    {
      cerr << "Can't open file!\n";
      return(1);
    }

  // Knight1 name
  string Knight1;
  getline(gif, Knight1, '|');


  // Knight Stamina
  getline(gif, somestring, '|');
  int Knight1_stam=stoi(somestring);


  // Main weapon
  string Knight1_main;
  getline(gif, Knight1_main, '|');


  // Main weapon cost
  getline(gif, somestring, '|');
  int Knight1_main_stam=stoi(somestring);


  // Main weapon hit chance
  getline(gif, somestring, '|');
  int Knight1_main_hit=stoi(somestring);


  // Sub weapon
  string Knight1_sub;
  getline(gif, Knight1_sub, '|');


  // Sub weapon stamina
  getline(gif, somestring, '|');
  int Knight1_sub_stam=stoi(somestring);

  // Sub weapon hit chance
  getline(gif, somestring, '|');
  int Knight1_sub_hit=stoi(somestring);




  // Knight2 name
  string Knight2;
  getline(gif, Knight2, '|');


  // Knight Stamina
  getline(gif, somestring, '|');
  int Knight2_stam=stoi(somestring);


  // Main weapon
  string Knight2_main;
  getline(gif, Knight2_main, '|');


  // Main weapon cost
  getline(gif, somestring, '|');
  int Knight2_main_stam=stoi(somestring);


  // Main weapon hit chance
  getline(gif, somestring, '|');
  int Knight2_main_hit=stoi(somestring);


  // Sub weapon
  string Knight2_sub;
  getline(gif, Knight2_sub, '|');


  // Sub weapon stamina
  getline(gif, somestring, '|');
  int Knight2_sub_stam=stoi(somestring);

  // Sub weapon hit chance
  getline(gif, somestring, '|');
  int Knight2_sub_hit=stoi(somestring);
  gif.close();


  // Knight 1 Weapons
  Weapon Main_1(Knight1_main, Knight1_main_hit, Knight1_main_stam);
  Weapon Sub_1(Knight1_sub, Knight1_sub_hit, Knight1_sub_stam);

  // Knight 2 Weapons
  Weapon Main_2(Knight2_main, Knight2_main_hit, Knight2_main_stam);
  Weapon Sub_2(Knight2_sub, Knight2_sub_hit, Knight2_sub_stam); 

  // Knight 1
  Knight Knight_alpha(Main_1, Sub_1, Knight1, Knight1_stam);

  // Knight 2
  Knight Knight_beta(Main_2, Sub_2, Knight2, Knight2_stam);



  // Knights Info

  cout << "######## THE KNIGHT ########\n";
  cout << Knight_alpha.display() << endl;
  cout << Knight_beta.display() << endl;

  //LET THE BATTLE BEGIN!

  cout << "######## LET THE BATTLE BEGIN ########\n";
 
  int round=1;
  
  do
  {
    cout << "######## ROUND " << round << " ########\n";

    bool joust;
    joust=Knight_alpha.attack();
    if(joust==true)
      Knight_beta.unhorse_yourself();
    joust=Knight_beta.attack();
    if(joust==true)
      Knight_alpha.unhorse_yourself();

    round++;

    Knight_alpha.display();
    Knight_beta.display();
  }
  while((Knight_alpha.are_you_on_your_horse() && Knight_beta.are_you_on_your_horse() == true) && (Knight_alpha.exhausted() && Knight_beta.exhausted() == false);

    return 0;
  }
