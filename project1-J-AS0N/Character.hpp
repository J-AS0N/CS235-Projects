#ifndef CHARACTER_HPP // guards ~ prevents re-definition of the same functions
#define CHARACTER_HPP // Capitalize the letters (for some reason :/ )
#include <iostream>

enum Race {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};

class Character {
    public:
        Character();     //default constructor
        Character(std::string name, std::string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);     //parameterized constructor

        // SETTERS - always void type

/**
            @param  : the name of the Character
            @post   : sets the Character's title to the value of the parameter, 
                      in UPPERCASE. Only alphabetical characters are allowed. 
                      For example, attempting to create a character named 
                      "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
                    : If the given parameter does not have any valid alphabetical
                      characters, the character's name should be set to "NAMELESS".
*/
        void setName(const std::string& name);


/**
       @param  : the race of the Character (a string)
       @post   : sets the Character's race to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
*/
        void setRace(const std::string& race);

/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/
        void setVitality(const int& vitality);

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/
        void setArmor(const int& armor);

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
*/
        void setLevel(const int& level);

/**
   @post   : sets the enemy flag to true
*/
        void setEnemy();

        // GETTERS

/**
      @return : the name of the Character
*/
        std::string getName() const;

/**
      @return : the race of the Character (a string)
*/
        std::string getRace() const;

/**
      @return : the value stored in vitality_
*/
        int getVitality() const;

/**
      @return : the value stored in armor_
*/
        int getArmor() const;

/**
      @return : the value stored in level_
*/
        int getLevel() const;

/**
    @return true if the character is an enemy, false otherwise

    Note: this is an accessor function and must follow the same convention as all accessor  
          functions even if it is not called getEnemy
*/
        bool isEnemy() const;

    private:     // private member's usually have an underscore at the end
        std::string name_; 
        Race race_;
        int vitality_;
        int armor_;
        int level_;
        bool enemy_;
}; 

#endif


