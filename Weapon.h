#ifndef WEAPON_H
#define WEAPON_H
#include<string>
using namespace std;

class Weapon{
  private:
    string equip;
    int hit_chance;
    int weap_stamina;
    bool broken;
    int num_uses;

  public:
    Weapon(string type, int to_hit, int stam_cost);
    void display();
    int what_is_stamina_cost();
    bool did_I_hit();
};
#endif
