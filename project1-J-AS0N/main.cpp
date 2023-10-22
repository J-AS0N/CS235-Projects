#include "Character.hpp"
#include <iostream>
using namespace std;

int main(){
    Character Ron("bro123", "ELF", -10, 4, 8, true);
    cout << Ron.getName() << endl;
    cout << Ron.getRace() << endl;
    cout << Ron.getVitality() << endl;
    cout << Ron.getArmor() << endl;
    cout << Ron.getLevel() << endl;
    cout << Ron.isEnemy() << endl;

    cout << endl;

    Character Dude("246123", "skajsaf", -1, -2, -3, false);
    cout << Dude.getName() << endl;
    cout << Dude.getRace() << endl;
    cout << Dude.getVitality() << endl;
    cout << Dude.getArmor() << endl;
    cout << Dude.getLevel() << endl;
    cout << Dude.isEnemy() << endl;
    
}