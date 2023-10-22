#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include <iostream>
using namespace std;


int main() {
    // mage testing

    /*
    Mage defaultMage();
    cout << defaultMage.setName("defaultMage") << " is a Level "
    defaultMage.setRace("elf");
    defaultMage.setVitality(-10);
    defaultMage.
    Mage testing("bro123", "ELF", -10, 4, 8, true, "elemental", "wand", true);
    cout << "Name: " << testing.getName() << endl;
    cout << "Race: " << testing.getRace() << endl;
    cout << "Vitality: " << testing.getVitality() << endl;
    cout << "Armor: " << testing.getArmor() << endl;
    cout << "Level: " << testing.getLevel() << endl;
    cout << "Enemy: " << testing.isEnemy() << endl;
    cout << "School: " << testing.getSchool() << endl;
    cout << "Weapon: " << testing.getCastingWeapon() << endl;
    cout << "Summon: " << testing.hasIncarnateSummon() << endl;

    return 0;

    cout << endl;

    */


    /*
    // scoundrel testing

    Scoundrel testing("bro123", "ELF", -10, 4, 8, true, "bronze", "shadowblade", true);
    cout << "Name: " << testing.getName() << endl;
    cout << "Race: " << testing.getRace() << endl;
    cout << "Vitality: " << testing.getVitality() << endl;
    cout << "Armor: " << testing.getArmor() << endl;
    cout << "Level: " << testing.getLevel() << endl;
    cout << "Enemy: " << testing.isEnemy() << endl;
    cout << "Dagger: " << testing.getDagger() << endl;
    cout << "Faction: " << testing.getFaction() << endl;
    cout << "Disguise: " << testing.hasDisguise() << endl;

    return 0;
    */

   
   // ranger testing

   Ranger testing("bro123", "ELF", -10, 4, 8, true);
   cout << "Name: " << testing.getName() << endl;
   cout << "Race: " << testing.getRace() << endl;
   cout << "Vitality: " << testing.getVitality() << endl;
   cout << "Armor: " << testing.getArmor() << endl;
   cout << "Level: " << testing.getLevel() << endl;
   cout << "Enemy: " << testing.isEnemy() << endl;
   cout << "Arrows: " << testing.addArrows("wood", 7) << endl;

   
   /*
   // barbarian testing

   Barbarian testing("bro123", "ELF", -10, 4, 8, true, "sword", "shield", false);
   cout << "Name: " << testing.getName() << endl;
   cout << "Race: " << testing.getRace() << endl;
   cout << "Vitality: " << testing.getVitality() << endl;
   cout << "Armor: " << testing.getArmor() << endl;
   cout << "Level: " << testing.getLevel() << endl;
   cout << "Enemy: " << testing.isEnemy() << endl;
   cout << "Main Weapon: " << testing.getMainWeapon() << endl;
   cout << "Secondary Weapon: " << testing.getSecondaryWeapon() << endl;
   cout << "Enraged: " << testing.getEnrage() << endl;

   return 0;
   */
}

