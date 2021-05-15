#include"Knight.h"
#include"Weapon.h"
#include<string>
#include<iostream>
using namespace std;

Knight::Knight(Weapon main, Weapon sub, string name, int stamina)
  : main(main), sub(sub), kname(name), kstamina(stamina), mounted(true)
{
}



bool Knight::exhausted()
{
  if(kstamina<=0)
    return true;
  else
    return false;
}





bool Knight::are_you_on_your_horse()
{
  return mounted;
}




bool Knight::attack()
{
  // Stamina effect
  int main_stam=main.what_is_stamina_cost();
  int sub_stam=sub.what_is_stamina_cost();
  kstamina-= (main_stam + sub_stam);

  //Hit Chance


  bool hit_main=main.did_I_hit();
  bool hit_sub=sub.did_I_hit();
  if((hit_main||hit_sub)==true)
    return true;
  else
    return false;
}


void Knight::unhorse_yourself()
{
  mounted=false;
}





void Knight::display()
{

  cout << kname << "is";

  if(kstamina>0)
    cout << "not";

  cout << "exhausted (Stamina=" << kstamina << ") and ";

  if(mounted=false)
    cout << "has fallen off the horse!\n";
  else
    cout << "is still on the horse.\n";

 cout << "Primary weapon: " << main.display(); 
  cout << "Secondary weapon: " << sub.display();
}




