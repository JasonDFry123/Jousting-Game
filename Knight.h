#ifndef KNIGHT_H
#define KnIGHT_H
#include<string>
#include"Weapon.h"
using namespace std;

class Knight{
  private:
    Weapon main;
    Weapon sub;
    string kname;
    int kstamina;
    bool mounted;

  public:
    Knight(Weapon main, Weapon sub, string name, int stamina);
    bool exhausted();
    bool are_you_on_your_horse();
    bool attack();
    void unhorse_yourself();
    void display();
};
#endif
