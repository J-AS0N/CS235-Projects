// Jason Weng
// JASON.WENG76@MYHUNTER.CUNY.EDU
// 9/22/23
// Scoundrel Implementation for term project

#include <iostream>
#include "Scoundrel.hpp"
#include <cctype>

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
Scoundrel::Scoundrel() {
    Character();  // default initializes all private members
    dagger_ = WOOD;
    faction_ = "NONE";
    has_disguise_ = false;
}

/**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's dagger type (a const string reference).
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                  Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                  parameters.
                 If the dagger type is not provided or invalid, the variable should 
                  be set to WOOD. 
                 If the Faction is not provided or invalid, the variable should be 
                  set to "NONE". 
*/
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, std::string dagger, std::string faction, bool has_disguise): Character(name, race, vitality, armor, level, enemy),  // parameterized constructor
    has_disguise_{has_disguise}
{
    setDagger(dagger);

    if (!setFaction(faction)) {
        faction_ = "NONE";
    }
}

// SETTERS

/**
   @param     : a reference to a string representing the dagger type
   @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string& dagger) {
    std::string new_dagger = "";  // empty string

    for (int i = 0; i < dagger.length(); i++) {  // loops through the string
        if (isalpha(dagger[i])) {  // checks if each element is in the alphabet
            new_dagger += char(toupper(dagger[i]));  // converts each element into uppercase
        }
    }

    if (new_dagger == "WOOD") {  // checks if the user's input is equal to "WOOD", "BRONZE", "IRON", "STEEL", "MITHRIL", "ADAMANT", "RUNE", if it is, set it equal to it
        dagger_ = WOOD;
    } else if (new_dagger == "BRONZE") {
        dagger_ = BRONZE;
    } else if (new_dagger == "IRON") {
        dagger_ = IRON;
    } else if (new_dagger == "STEEL") {
        dagger_ = STEEL;
    } else if (new_dagger == "MITHRIL") {
        dagger_ = MITHRIL;
    } else if (new_dagger == "ADAMANT") {
        dagger_ = ADAMANT;
    } else if (new_dagger == "RUNE") {
        dagger_ = RUNE;
    } else dagger_ = WOOD;  // if not, set dagger_ to WOOD
}

/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
               [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
               do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string& faction) {
    std::string new_faction = "";  // empty string

    for (int i = 0; i < faction.length(); i++) {  // loops through the string
        if (isalpha(faction[i])) {  // checks if each element is in the alphabet 
            new_faction += char(toupper(faction[i]));  // converts it to uppercase
        }
    }
    if (new_faction == "NONE" || new_faction == "CUTPURSE" || new_faction == "SHADOWBLADE" || new_faction == "SILVERTONGUE") {  // checks if the user's input is equal to either "NONE", "CUTPURSE", "SHADOWBLADE" or "SILVERTONGUE"
        faction_ = new_faction;  // if it is equal to one of these values, set faction_ to it
        return true;  // return true
    } else {
        return false;  // if it isn't equal to any of these values, return false
    }
}


/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool& has_disguise) {  // sets has_disguise_ to the user's input
    has_disguise_ = has_disguise;
}


// GETTERS

/**
  @return     : the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const {

    if (dagger_ == WOOD) {  // if dagger_ is equal to WOOD
        return "WOOD";  // return the string WOOD
    } else if (dagger_ == BRONZE) {  // if dagger_ is equal to BRONZE
        return "BRONZE";  // return the string BRONZE
    } else if (dagger_ == IRON) {  // if dagger_ is equal to IRON
        return "IRON";  // return the string IRON
    } else if (dagger_ == STEEL) {  // if dagger_ is equal to STEEL
        return "STEEL";  // return the string STEEL
    } else if (dagger_ == MITHRIL) {  // if dagger_ is equal to MITHRIL
        return "MITHRIL";  // return the string MITHRIL
    } else if (dagger_ == ADAMANT) {  // if dagger_ is equal to ADAMANT
        return "ADAMANT";  // return the string ADAMANT
    } else if (dagger_ == RUNE) {  // if dagger_ is equal to RUNE
        return "RUNE";  // return the string RUNE
    }

    return "NONE";
}

/**
  @return  : the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const {  // return faction_
    return faction_;
}

/**
  @return  : the disguise flag
**/
bool Scoundrel::hasDisguise() const {  // return has_disguise_
    return has_disguise_;
}