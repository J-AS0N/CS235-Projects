/*
Jason Weng
JASON.WENG76@MYHUNTER.CUNY.EDU
10/29/23
PROJECT 5
Test file

*/

#include <iostream>
#include "QuestList.hpp"

int main() {
    QuestList questList("debug.csv");


    std::cout << "Testing questQuery:" << std::endl<< std::endl;
    questList.questQuery("Quest 1");
    std::cout<<std::endl;
    questList.questQuery("Quest 2");
    std::cout<<std::endl;
    questList.questQuery("Quest 3");
    std::cout<<std::endl;
    questList.questQuery("Quest 4");
    std::cout<<std::endl;
    questList.questQuery("Quest 5");
    std::cout<<std::endl;
    questList.questQuery("Quest 6");
    std::cout<<std::endl;
    questList.questQuery("Quest 7");
    std::cout<<std::endl;
    questList.questQuery("Quest 8");
    std::cout<<std::endl;
    questList.questQuery("Quest 9");
    std::cout<<std::endl;
    questList.questQuery("Quest 12");
    std::cout<<std::endl;
    std::cout << "Testing printQuestDetails:" << std::endl<< std::endl;
    Quest* current = questList.getPointerTo(questList.getPosOf("Quest 1")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 2")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;
    
    current = questList.getPointerTo(questList.getPosOf("Quest 3")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 4")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 5")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 6")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 7")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 8")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;

    current = questList.getPointerTo(questList.getPosOf("Quest 9")) -> getItem();
    questList.printQuestDetails(current);
    std::cout<<std::endl;
    std::cout << questList.calculateGainedExperience() << std::endl;
    return 0;
    
}


