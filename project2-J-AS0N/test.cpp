#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include <iostream>
using namespace std;

int main() {
/* 2.1.1 Instantiate a default Mage
  - Sets its name, race, vitality, and armor levels using the appropriate setter functions */

    Mage default_Mage;

    default_Mage.setName("defaultMage");
    default_Mage.setRace("ELF");
    default_Mage.setVitality(5);
    default_Mage.setArmor(3);
    default_Mage.setLevel(2);
    default_Mage.setEnemy();

    cout << default_Mage.getName() << " is a Level " << default_Mage.getLevel() << " " << default_Mage.getRace() << "."
        << "\nVitality: " << default_Mage.getVitality()
        << "\nArmor: " << default_Mage.getArmor()
        << "\nThey are " << (default_Mage.isEnemy() ? "an enemy" : "not an enemy")
        << "\nSchool of Magic: " << default_Mage.getSchool()
        << "\nWeapon: " << default_Mage.getCastingWeapon()
        << "\nSummon Incarnate: " << (default_Mage.hasIncarnateSummon() ? "TRUE" : "FALSE")
        << "\n" << endl;

/* 2.1.2 Instantiate a Mage with the parameterized constructor with the following character details:
Name: SPYNACH
Race: ELF
Vitality: 6
Armor: 4
Level: 4
Enemy: FALSE

2.1.3 Set SPYNACH's unique private member variables to the following:
School of Magic: Illusion
Weapon: Wand
Summon Incarnate: TRUE */

    Mage new_Mage("SPYNACH", "ELF", 6, 4, 4, false);

    new_Mage.setSchool("Illusion");
    new_Mage.setCastingWeapon("Wand");
    new_Mage.setIncarnateSummon(true);

    cout << new_Mage.getName() << " is a Level " << new_Mage.getLevel() << " " << new_Mage.getRace() << "."
        << "\nVitality: " << new_Mage.getVitality()
        << "\nArmor: " << new_Mage.getArmor()
        << "\nThey are " << (new_Mage.isEnemy() ? "an enemy" : "not an enemy")
        << "\nSchool of Magic: " << new_Mage.getSchool()
        << "\nWeapon: " << new_Mage.getCastingWeapon()
        << "\nSummon Incarnate: " << (new_Mage.hasIncarnateSummon() ? "TRUE" : "FALSE")
        << "\n" << endl;

/* 2.2.1 Instantiate a default Scoundrel
  - Sets its name, race, vitality, and armor levels using the appropriate setter functions */

    Scoundrel default_Scoundrel;

    default_Scoundrel.setName("defaultScoundrel");
    default_Scoundrel.setRace("HUMAN");
    default_Scoundrel.setVitality(6);
    default_Scoundrel.setArmor(4);
    default_Scoundrel.setLevel(3);
    default_Scoundrel.setEnemy();

    cout << default_Scoundrel.getName() << " is a Level " << default_Scoundrel.getLevel() << " " << default_Scoundrel.getRace() << "."
        << "\nVitality: " << default_Scoundrel.getVitality()
        << "\nArmor: " << default_Scoundrel.getArmor()
        << "\nThey are " << (default_Scoundrel.isEnemy() ? "an enemy" : "not an enemy")
        << "\nDagger: " << default_Scoundrel.getDagger()
        << "\nFaction: " << default_Scoundrel.getFaction()
        << "\nDisguise: " << (default_Scoundrel.hasDisguise() ? "TRUE" : "FALSE")
        << "\n" << endl;

/* 2.2.2 Instantiate a Scoundrel with the parameterized constructor with the following character details:
Name: FLEA
Race: DWARF
Level: 7
Vitality: 12
Enemy: FALSE

2.2.3 Set FLEA's unique private member variables to the following:
Dagger: Adamant
Faction: Cutpurse
Disguise: TRUE
*/

    Scoundrel new_Scoundrel("FLEA", "DWARF", 12, 7, 5, false);

    new_Scoundrel.setDagger("Adamant");
    new_Scoundrel.setFaction("Cutpurse");
    new_Scoundrel.setDisguise(true);

    cout << new_Scoundrel.getName() << " is a Level " << new_Scoundrel.getLevel() << " " << new_Scoundrel.getRace() << "."
        << "\nVitality: " << new_Scoundrel.getVitality()
        << "\nArmor: " << new_Scoundrel.getArmor()
        << "\nThey are " << (new_Scoundrel.isEnemy() ? "an enemy" : "not an enemy")
        << "\nDagger: " << new_Scoundrel.getDagger()
        << "\nFaction: " << new_Scoundrel.getFaction()
        << "\nDisguise: " << (new_Scoundrel.hasDisguise() ? "TRUE" : "FALSE")
        << "\n" << endl;

/* 2.3.1 Instantiate a default Ranger
  - Sets its name, race, vitality, and armor levels using the appropriate setter functions
Name: defaultRanger
Race: UNDEAD
Vitality: 8
Armor: 4
Level: 5
Enemy: TRUE */

    Ranger default_Ranger;
    default_Ranger.setName("defaultRanger");
    default_Ranger.setRace("UNDEAD");
    default_Ranger.setVitality(8);
    default_Ranger.setArmor(4);
    default_Ranger.setLevel(5);
    default_Ranger.setEnemy();

     cout << default_Ranger.getName() << " is a Level " << default_Ranger.getLevel() << " " << default_Ranger.getRace() << "."
        << "\nVitality: " << default_Ranger.getVitality()
        << "\nArmor: " << default_Ranger.getArmor()
        << "\nThey are " << (default_Ranger.isEnemy() ? "an enemy" : "not an enemy")
        << "\nVector of arrows: ";

        vector<Arrows> arrows = default_Ranger.getArrows();

        for (const Arrows& arrow : arrows) {
            cout << arrow.type_ << ", " << arrow.quantity_ << ". ";
        }

        cout << "\nAffinities: ";

        vector<string> affinities = default_Ranger.getAffinities();
        for (const string& affinity : affinities) {
            cout << affinity << ". ";
        }
        cout << "\nAnimal Companion: " << (default_Ranger.getCompanion() ? "TRUE" : "FALSE")
        << "\n" << endl;

    Ranger new_Ranger("MARROW", "UNDEAD", 9, 6, 5, true);
    new_Ranger.addArrows("Wood", 30);
    new_Ranger.addArrows("Fire", 5);
    new_Ranger.addArrows("Water", 5);
    new_Ranger.addArrows("Poison", 5);
    new_Ranger.addAffinity("Fire");
    new_Ranger.addAffinity("Poison");
    new_Ranger.setCompanion(true);

    cout << new_Ranger.getName() << " is a Level " << new_Ranger.getLevel() << " " << new_Ranger.getRace() << "."
              << "\nVitality: " << new_Ranger.getVitality()
              << "\nArmor: " << new_Ranger.getArmor()
              << "\nThey are " << (new_Ranger.isEnemy() ? "an enemy" : "not an enemy")
              << "\nVector of arrows: ";

              vector<Arrows> my_rangerArrows = new_Ranger.getArrows();

              for (const Arrows& arrow : my_rangerArrows){
                cout << arrow.type_ << ", " << arrow.quantity_ << ", ";
              }

              cout << "\nAffinities: ";
              
              vector<string> my_rangerAffinities = new_Ranger.getAffinities();
              for (const string& affinity : my_rangerAffinities){
                cout << affinity << ", ";
              }

              cout << "\nAnimal Companion: " << (default_Ranger.getCompanion() ? "TRUE" : "FALSE")
              << "\n" << endl;
    
 /* 2.2.2 Instantiate a Ranger with the parameterized constructor with the following character details: */
        Ranger MARROW("MARROW", "UNDEAD", 9, 6, 5, true);

 
        cout << MARROW.getName() << " is a Level " << MARROW.getLevel() << " " << MARROW.getRace() << ".\n"
                  << "Vitality: " << MARROW.getVitality() << "\n"
                  << "Armor: " << MARROW.getArmor() << "\n"
                  << "They are " << (MARROW.isEnemy() ? "an enemy" : "not an enemy") << "\n"
                  << "Arrows: ";
        
        vector<Arrows> arrows1 = MARROW.getArrows();
        for (const Arrows& arrow : arrows1) {
            cout << arrow.type_ << ": " << arrow.quantity_ << ", ";
        }
        
        cout << "\nAffinities: ";
        vector<string> affinities1 = MARROW.getAffinities();
        for (const string& affinity : affinities1) {
            cout << affinity << ", ";
        }
        





/* 2.4.1 Instantiate a default Barbarian
  - Sets its name, race, vitality, and armor levels using the appropriate setter functions */

    Barbarian default_Barbarian;

    default_Barbarian.setName("defaultScoundrel");
    default_Barbarian.setRace("HUMAN");
    default_Barbarian.setVitality(10);
    default_Barbarian.setArmor(5);
    default_Barbarian.setLevel(5);
    default_Barbarian.setEnemy();

    cout << default_Barbarian.getName() << " is a Level " << default_Barbarian.getLevel() << " " << default_Scoundrel.getRace() << "."
        << "\nVitality: " << default_Barbarian.getVitality()
        << "\nArmor: " << default_Barbarian.getArmor()
        << "\nThey are " << (default_Scoundrel.isEnemy() ? "an enemy" : "not an enemy")
        << "\nDagger: " << default_Scoundrel.getDagger()
        << "\nFaction: " << default_Scoundrel.getFaction()
        << "\nDisguise: " << (default_Scoundrel.hasDisguise() ? "TRUE" : "FALSE")
        << "\n" << endl;

/* 2.4.2 Instantiate a Barbarian with the parameterized constructor with the following character details:
Name: BONK
Race: HUMAN
Vitality: 11
Armor: 5
Level: 5
Enemy: TRUE

2.4.3 Set BONK's unique private member variables to the following:
Main Weapon: MACE
Offhand Weapon: ANOTHERMACE
Enraged: TRUE
*/

    Barbarian new_Barbarian("BONK", "HUMAN", 11, 5, 5, true);

    new_Barbarian.setMainWeapon("MACE");
    new_Barbarian.setSecondaryWeapon("ANOTHERMACE");
    new_Barbarian.setEnrage(true);

    cout << new_Barbarian.getName() << " is a Level " << new_Barbarian.getLevel() << " " << new_Scoundrel.getRace() << "."
        << "\nVitality: " << new_Barbarian.getVitality()
        << "\nArmor: " << new_Barbarian.getArmor()
        << "\nThey are " << (new_Barbarian.isEnemy() ? "an enemy" : "not an enemy")
        << "\nMain Weapon: " << new_Barbarian.getMainWeapon()
        << "\nOffhand Weapon: " << new_Barbarian.getSecondaryWeapon()
        << "\nEnrage: " << (new_Barbarian.getEnrage() ? "TRUE" : "FALSE")
        << "\n" << endl;

}