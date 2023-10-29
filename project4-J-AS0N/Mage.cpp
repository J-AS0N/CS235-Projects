/*
Jason Weng
JASON.WENG76@MYHUNTER.CUNY.EDU
10/11/23
PROJECT 4
This is the Mage implementation for term project
Mage.cpp defines the constructors and private and public function implementation of the Mage class
*/

#include "Mage.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default school of magic and weapon: "NONE". 
*/
Mage::Mage() : Character(), school_of_magic_{"NONE"}, weapon_{"NONE"}, can_summon_incarnate_{false}
{
}

/**
    Parameterized constructor.
    @param      : The name of the character (a string)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer)
    @param      : The character's max armor level (an integer)
    @param      : The character's level (an integer)
    @param      : A flag indicating whether the character is an enemy
    @param      : The character's school of magic (a string). Valid schools: [ELEMENTAL, NECROMANCY, ILLUSION]. 
                 String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
                 If the school name is invalid, set it to "NONE"
    @param      : The character's choice of weapon (a string). Valid weapons: [WAND, STAFF]
                  String inputs can be in lowercase, but must be converted to 
				  uppercase when setting the variable.
				  If the weapon is invalid, set it to "NONE"
    @param      : A flag indicating whether the character is able to summon an incarnate
    @post       : The private members are set to the values of the corresponding parameters.
                  If the school of magic or weapon is not provided or valid, the variables should be set to "NONE". 
*/
Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& school_of_magic, const std::string& weapon, bool can_summon_incarnate) 
: Character(name, race, vitality, armor, level, enemy), can_summon_incarnate_{can_summon_incarnate}
{
    if (!setSchool(school_of_magic))
    {
        school_of_magic_ = "NONE";
    }
    if(!setCastingWeapon(weapon))
    {
        weapon_ = "NONE";
    }
}

/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. 
              If the provided school of magic is not one of the following: [ELEMENTAL, NECROMANCY, ILLUSION], 
              do nothing and return false.
              String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setSchool(const std::string& school_of_magic)
{
    std::string school_upper = school_of_magic;
    for(int i = 0;i<school_of_magic.size();i++)
    {
        if(isalpha(school_of_magic[i]))
        {
            school_upper[i] = toupper(school_of_magic[i]); 
        }
    }
    if(school_upper == "ELEMENTAL" || school_upper == "NECROMANCY" || school_upper == "ILLUSION")
    {
        school_of_magic_ = school_upper;
        return true;
    }
    else
    {
        return false;
    }
}


/**
    @return  : the string indicating the character's school of magic
**/
std::string Mage::getSchool() const
{
    return school_of_magic_;
}


/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter. 
              String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
              If the provided weapon is not one of the following: [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string& weapon)
{
    std::string weapon_upper = weapon;
    for(int i = 0;i<weapon.size();i++)
    {
        if(isalpha(weapon[i]))
        {
            weapon_upper[i] = toupper(weapon[i]); 
        }
    }
    if(weapon_upper == "WAND" || weapon_upper == "STAFF")
    {
        weapon_ = weapon_upper;
        return true;
    }
    else
    {
        return false;
    }
}


/**
    @return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const
{
    return weapon_;
}

/**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character can summon an incarnate
**/
void Mage::setIncarnateSummon(const bool& can_summon_incarnate)
{
    can_summon_incarnate_ = can_summon_incarnate;
}

/**
    @return  : the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const
{
    return can_summon_incarnate_;
}

/**
    @post     : displays Mage data in the form:
    "[NAME] is a Level [LEVEL] [RACE] MAGE.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nSchool of Magic: [SCHOOL]
    \nWeapon: [WEAPON]
    \nThey [can/cannot] summon an Incarnate.
    \n\n"
    
    Example:
    SPYNACH is a Level 4 ELF MAGE.
    Vitality: 6
    Armor: 4
    They are not an enemy.
    School of Magic: ILLUSION
    Weapon: WAND
    They can summon an Incarnate.
*/
void Mage::display() const {
    std::string mage_enemy = "";  // empty string
    std::string mage_incarnate = "";  // emtpy string
    
    if (isEnemy() == true) {  // if it is an enemy
        mage_enemy = "an enemy.";  // set empty string to "an enemy."
    } else {  // if it's not an enemy
        mage_enemy = "not an enemy.";  // set the empty string to "not an enemy."
    }

    if (hasIncarnateSummon() == true) {  // if the function hasIncarnateSummon() is equal to true
        mage_incarnate = "can";  // set the empty string to "can"
    } else {  // if it's not true
        mage_incarnate = "cannot";  // set the empty string to "cannot"
    }

    std::cout << getName() << " is a Level " << getLevel() << " " << getRace() << " MAGE."  // printing
    << "\nVitality: " << getVitality()
    << "\nArmor: " << getArmor()
    << "\nThey are " << mage_enemy
    << "\nSchool of Magic: " << getSchool()
    << "\nWeapon: " << getCastingWeapon()
    << "\nThey " << mage_incarnate << " summon an Incarnate." << "\n\n";
}

/**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens.
    
    If the character is NOT UNDEAD, Vitality is set to 1. 
    In addition, as a Mage: 
    If the character is equipped with a wand or staff, they cast a healing ritual and recover vitality points – 2 points with a wand, 3 with a staff.
    If they can summon an incarnate, the emotional support allows the character to recover 1 Vitality point.
*/
void Mage::eatTaintedStew() {
    if (getRace() == "UNDEAD") {  // if the character's race is "UNDEAD"
        setVitality(getVitality() + 3);  // set the vitality to whatever they have right now + 3
    } else {  // if its race is not UNDEAD
        setVitality(1);  // set the vitality to 1
        if (getCastingWeapon() == "WAND") {  // if the mage's weapon is a WAND
            setVitality(getVitality() + 2);  // add 2 extra vitality to however many it already has and set it to that value
        } else if (getCastingWeapon() == "STAFF") {  // if the mage has a STAFF
            setVitality(getVitality() + 3);  // add 3 extra vitality to their current vitality level and set it
        } if (hasIncarnateSummon() == true) {  // if the mage can summon an incarnate
            setVitality(getVitality() + 1);  // add 1 extra vitality to their current vitality level and set it
        }
    }
}