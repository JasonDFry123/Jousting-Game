#include"Random.h"
#include"Weapon.h"
#include<iostream>
#include<string>
using namespace std;

Weapon::Weapon(string type, int to_hit, int stam_cost)
  : equip(type), hit_chance(to_hit), weap_stamina(stam_cost), broken(false), num_uses(0)
{
}

int Weapon::what_is_stamina_cost()
{
  return weap_stamina;
}

bool Weapon::did_I_hit()
{
 Random roll;  
  if(roll.get() < num_uses*20)
    broken=true;

  ++num_uses;

  if(broken==true)
    return false;
  else
  {
    Random roll(1,100);
    if(roll.get() <= hit_chance)
      return true;
    else
      return false;
  }
}

void Weapon::display()
{

  if(broken==true)
    cout <<  "BROKEN ";

      cout << equip << " that cost " << weap_stamina << " stamina and has a " << hit_chance << "%" << " chance to hit.\n";
};
