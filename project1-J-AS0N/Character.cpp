#include "Character.hpp"
#include <iostream>
#include <cctype>

// default constructor 
Character::Character() {
    name_ = "NAMELESS";
    enemy_ = false;
    race_ = NONE;
    vitality_ = 0;
    armor_ = 0;
    level_ = 0;
}

// parameterized constructor
Character::Character(std::string name, std::string race, int vitality, int armor, int level, bool enemy):
    name_{name}, vitality_{vitality}, armor_{armor}, level_{level}, enemy_{enemy}     // member initializer list - private members will take in values passed into the paramterized constructor
 {
    setName(name);
    setRace(race);
    
    if (armor >= 0) {
        armor_ = armor;
    } else {
        armor_ = 0;
    }

    if (vitality >= 0) {
        vitality_ = vitality;
    } else {
        vitality_ = 0;
    }

    if (level >= 0) {
        level_ = level;
    } else {
        level_ = 0;
    }

    enemy_ = enemy;
}


// Mutators (set)

/**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
*/

void Character::setName(const std::string& name) {
    std::string test = "";

    for (int i = 0; i < name.length(); i++) {     // loop through the entire string 
        if (isalpha(name[i])) {     // if it is a alphabet
            test = test + char(toupper(name[i]));     // toupper() converts into a ASCII value and the char() converts into a character and then it adds it to the empty string called test
        }
    }
    if (test == "") {     // if the string is empty; there is no alphabet
        name_ = "NAMELESS";     // set private member variable to "NAMELESS";
    } else {
        name_ = test;
    }
}


/**
       @param  : the race of the Character (a string)
       @post   : sets the Character's race to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
*/
void Character::setRace(const std::string& race) {
    //Race

    if (race == "HUMAN") {   // checks if it's one of the character's in the enum as a string
        race_ = HUMAN;
    } else if (race == "ELF") {
        race_ = ELF;
    } else if (race == "DWARF") {
        race_ = DWARF;
    } else if (race == "LIZARD") {
        race_ = LIZARD;
    } else if (race == "UNDEAD") {
        race_ = UNDEAD;
    } else {
        race_ = NONE;
    }
}

/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/

void Character::setVitality(const int& vitality) {
    if (vitality >= 0) {
        vitality_ = vitality;
    } 
}

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/

void Character::setArmor(const int& armor) {
    if (armor >= 0) {
        armor_ = armor;
    }
}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
*/

void Character::setLevel(const int& level) {
    if (level >= 0) {
        level_ = level;
    } 
}

/**
   @post   : sets the enemy flag to true
*/

void Character::setEnemy() {
    enemy_ = true;
}

// Accessors (get)

/**
      @return : the name of the Character
*/

std::string Character::getName() const {     // getter's should have const after the parenthesis 
    return name_;
}

/**
      @return : the race of the Character (a string)
*/

std::string Character::getRace() const {

    if (race_ == HUMAN) {   // / if statements to compare
        return "HUMAN";   // returns a string
     } else if (race_ == ELF) {
        return "ELF";
     } else if (race_ == DWARF) {
        return "DWARF";
     } else if (race_ == LIZARD) {
        return "LIZARD";
     } else if (race_ == UNDEAD) {
        return "UNDEAD"; 
     }

    return "NONE";
}

/**
      @return : the value stored in vitality_
*/

int Character::getVitality() const {
    return vitality_;
}

/**
      @return : the value stored in armor_
*/

int Character::getArmor() const {
    return armor_;
}

/**
      @return : the value stored in level_
*/

int Character::getLevel() const {
    return level_;
}

/**
    @return true if the character is an enemy, false otherwise

    Note: this is an accessor function and must follow the same convention as all accessor  
          functions even if it is not called getEnemy
*/

bool Character::isEnemy() const {
    return enemy_;
}

