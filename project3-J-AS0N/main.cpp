// Jason Weng
// JASON.WENG76@MYHUNTER.CUNY.EDU
// 9/27/23
// PROJECT 3
// This is the tezt file

#include <iostream>
#include "Character.hpp"
#include "ArrayBag.hpp"
#include "Tavern.hpp"

int main() {
    Character random("bro123", "ELF", 10, 2, 3, false);
    Character random2("kkk", "LIZARD", 4, 1, 6, true);
    Character random3("jj", "DWARF", 12, 2, 1, true);
    Character random4("justin", "DWARF", 2, 6, 8, true);
    Tavern myTavern;


    /* std::cout << "Name: " << random.getName() << std::endl;
    std::cout << "Race: " << random.getRace() << std::endl;
    std::cout << "Vitality: " << random.getVitality() << std::endl;
    std::cout << "Armor: " << random.getArmor() << std::endl;
    std::cout << "Level: " << random.getLevel() << std::endl;
    std::cout << "Enemey: " << random.isEnemy() << std::endl; */


    std::cout << "Enter Tavern: " << myTavern.enterTavern(random) << std::endl;
    std::cout << "Enter Tavern: " << myTavern.enterTavern(random2) << std::endl;
    std::cout << "Enter Tavern: " << myTavern.enterTavern(random3) << std::endl;
    std::cout << "Enter Tavern: " << myTavern.enterTavern(random4) << std::endl;
    

    myTavern.tavernReport();
    

    std::cout << "Exit Tavern: " << myTavern.exitTavern(random3) << std::endl;

    myTavern.tavernReport();

    //std::cout << myTavern.calculateEnemyPercentage();
    std::cout << myTavern.calculateAvgLevel();

    



    
    
}