// Jason Weng
// JASON.WENG76@MYHUNTER.CUNY.EDU
// 9/27/23
// PROJECT 3
// This is the Tavern implementation for term project

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "Tavern.hpp"
#include "ArrayBag.hpp"


/**
    Default constructor.
    Default-initializes all private members. 
*/
Tavern::Tavern() {  // default constructor
    ArrayBag();  // default initializes all private members
    sumOfLevels_ = 0;
    enemyCount_ = 0;
}

/** @param:   A const reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to the tavern (i.e. items_),                 false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count 
              if the character is an enemy.
 **/
bool Tavern::enterTavern(const Character& enter) {
    if (add(enter)) {  // adds the character
        sumOfLevels_ += enter.getLevel();  // updates the level
        if (enter.isEnemy()) {  // checks if the character is an enemy or not
            enemyCount_++;  // if it is an enemy. increase the enemy count
        }
        return true;
    }
    return false;
}

/** @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count
              if the character is an enemy.
 **/
bool Tavern::exitTavern(const Character& exit) {
    if (remove(exit)) {  // removes the character from the tavern
        sumOfLevels_ -= exit.getLevel();  // if the character is removed, the level decreases
        if (exit.isEnemy()) {  // if the character is an enemy
            enemyCount_--;  // decrease the enemy count because it'll be out of the tavern
        }
        return true;
    }
    return false;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
 **/
int Tavern::calculateAvgLevel() const {
    double AvgLevel = 0.0;  // initialize a double type variable called AvgLevel and set its value to 0.0 

    AvgLevel = round(double(sumOfLevels_) / getCurrentSize());  // divides the total level (sumOfLevels_) by the total number of characters in the tavern and rounds it to the nearest integer 
    return AvgLevel;  // returns the value
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
 **/
double Tavern::calculateEnemyPercentage() const {
    double EnemyPercentage = 0.0;  // initializes a double variable called EnemyPercentage and set its value to 0.0
    double value = 0.00;  // initializes a double variable called value and set its value to 0.00


    EnemyPercentage = (double(enemyCount_) / getCurrentSize());  // divides the total number of enemies in the tavern with the total number of characters in the tavern

    value = (std::ceil((EnemyPercentage * 10000)) / 100.0);  // multipliy the EnemyPercentage by 10,000 and divides it by 100.0. Then you take the ceiling of that

    // EnemyPercentage *= 100;
    // EnemyPercentage *= 100;
    // std::ceil(EnemyPercentage);
    // EnemyPercentage /= 100;
    
    return value;  // return the value
}

/** 
    @param:   A const reference to a string representing a character Race with value in 
              ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
              If the argument string does not match one of the expected race values, 
              the tally is zero. NOTE: no pre-processing of the input string necessary, only                  uppercase input will match.
 **/
int Tavern::tallyRace(const std::string& race) {  // tallys up all the acceptable races
    int tally = 0;  // counter set to 0

    if (race == "NONE" || race == "HUMAN" || race == "ELF" || race == "DWARF" || race == "LIZARD" || race == "UNDEAD") {  // // if each element in getCurrentSize() is equal to "NONE", "HUMAN", "ELF", "DWARF", "LIZARD", or "UNDEAD"
        for (int i = 0; i < getCurrentSize(); i++) {  // loops through the array size
            if (items_[i].getRace() == race) {  // if the element in getRace() is equal to the user's input
                tally++;  // if it's equal to one of the values, increase the tally by 1
            }
        } return tally;  // returns the tally
    } else {  // if the user's input does not match
        return tally;
    }
}

/**
@post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             percentage should be rounded to 2 decimal places.

            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport() {  // returns a report containing the number of Humans, Elves, Dwarves, Lizards and Undeads. It also displays the average level and what percent of the tavern are enemies
    std::cout << "Humans: " << tallyRace("HUMAN");
    std::cout << "\nElves: " << tallyRace("ELF");
    std::cout << "\nDwarves: " << tallyRace("DWARF");
    std::cout << "\nLizards: " << tallyRace("LIZARD");
    std::cout << "\nUndead: " << tallyRace("UNDEAD");
    std::cout << std::endl;

    std::cout << "The average level is: " << calculateAvgLevel() << std::endl;
    std::cout << calculateEnemyPercentage() << "%" << " are enemies." << std::endl;
}

// GETTERS
/** 
    @return:  The integer level count of all the characters currently in the Tavern
 **/
int Tavern::getLevelSum() const {
    return sumOfLevels_;  // return the private memeber variable sumOfLevels_
}

/** 
    @return:  The integer enemy count of the Tavern
 **/
int Tavern::getEnemyCount() const {
    return enemyCount_;  // return the private member variable enemyCount_
}



