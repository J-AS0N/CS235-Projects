/*
Jason Weng
JASON.WENG76@MYHUNTER.CUNY.EDU
10/29/23
Project 5
This is the QuestList implementation for term project
*/

#include "QuestList.hpp"
#include <fstream>
#include <sstream>

/**
        Default Constructor
        @post: Creates a new Quest object with default values (zero-initialized)
*/

/*
    @param: A reference to string reference to a quest title
    @param: A reference to string reference to a quest description
    @param: A reference to boolean representing if the quest is completed
    @param: An reference to int indicating the experience points
    @param: A reference to vector of Quest pointers representing the quest's dependencies
    @param: A reference to vector of Quest pointers representing the quest's subquests
    @post: Creates a new Quest object with the given parameters
*/

/**
    Default Constructor
*/

QuestList::QuestList() : DoublyLinkedList<Quest*>() {}

/**
    @param: a reference to string name of an input file
    @pre: Formatting of the csv file is as follows:
        Title: A string
        Description: A string
        Completion Status: 0 (False) or 1 (True)
        Experience Points: A non negative integer
        Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
    Notes:
        - The first line of the input file is a header and should be ignored.
        - The dependencies and subquests are separated by a semicolon and may be NONE.
        - The dependencies and subquests may be in any order.
        - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
            - Title: The title of the quest
            - Description: "NOT DISCOVERED"
            - Completion Status: False
            - Experience Points: 0
            - Dependencies: An empty vector
            - Subquests: An empty vector
        - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
        Hint: update as needed using addQuest()
        

    @post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.

*/

QuestList::QuestList(const std::string& file_name) : DoublyLinkedList<Quest*> () {

    std::ifstream read(file_name);
    if(!read.is_open()) {
        std::cout << "ERROR: File Open" << "\n";
    }

    std::string str;
    std::getline(read, str);  // skips the first line in the csv file

    std::string title, descript, dependencies, subquests;
    bool completion;
    int exp;
    std::vector<Quest*> temp_dependencies = {};  // empty vector
    std::vector<Quest*> temp_subquests = {};  // empty vector

    std::string line = "";
    while(std::getline(read, line)) {
        std::istringstream inputString(line);  // parse
        
        // Quest Title
        getline(inputString, title, ',');

        // Description
        getline(inputString, descript, ',');

        std::string temp;
        // Completion Status
        getline(inputString, temp, ',');
        completion = stoi(temp);  // convert numbers as a string to a int

        // Experience Points
        getline(inputString, temp, ',');
        exp = stoi(temp);
        
        
        // Dependencies
        getline(inputString, dependencies, ',');
        std::vector<Quest*> temp_dependencies;  // empty vector
        std::string depend = "";  // empty string
        std::istringstream depend_parse(dependencies);

        while(getline(depend_parse, depend, ';')) {
            if (depend != "NONE") {
                if (getPosOf(depend) != -1) {  // if the position is not equal to -1 (meaning there is a match of quest title in the Linked List)
                    Node<Quest*> *depend_node = getPointerTo(getPosOf(depend));  // converts the int from getPosOf to a pointer
                    temp_dependencies.push_back(depend_node -> getItem());  // pushes back the item into the empty vector from the linked list

                } else {  // if the dependencies/subquests is not in the list, create a new quest with the following information: 
                    Quest* defaultQuest = new Quest;
                    defaultQuest -> title_ = depend;
                    defaultQuest -> description_ = "NOT DISCOVERED";  // setting the variable (quest_description_) in the struct Quest to "NOT DISCOVERED"
                    defaultQuest -> completed_ = false;  // setting the variables (quest_complete_) in the struct Quest to false ()
                    defaultQuest -> experience_points_ = 0;
                    defaultQuest -> dependencies_ = {};  // setting the vector of Quest pointers representing the dependencies to a empty vector
                    defaultQuest -> subquests_ = {};  // setting the vector of Quest pointers representing the subquests to a empty vector
                    addQuest(defaultQuest);
                    temp_dependencies.push_back(defaultQuest);  // adding it to the Quest
                }
            }
        }
        
        // Subquests
        getline(inputString, subquests, ',');
        std::vector<Quest*> temp_subquests;  // empty vector
        std::string sub = "";  // empty string
        std::istringstream sub_parse(subquests);

        while(getline(sub_parse, sub, ';')) {
            if (sub != "NONE") {
                if (getPosOf(sub) != -1) {
                    Node<Quest*> *sub_node = getPointerTo(getPosOf(sub));  // if the position is not equal to -1 (meaning, there is a match of quest title in the Linked List)
                    temp_subquests.push_back(sub_node -> getItem());  // converts the int from getPosOf to a pointer

                } else {
                    Quest* defaultQuest = new Quest;
                    defaultQuest -> title_ = sub;
                    defaultQuest -> description_ = "NOT DISCOVERED";  // setting the variable (quest_description_) in the struct Quest to "NOT DISCOVERED"
                    defaultQuest -> completed_ = false;  // setting the variables (quest_complete_) in the struct Quest to false ()
                    defaultQuest -> experience_points_ = 0;
                    defaultQuest -> dependencies_ = {};   // setting the vector of Quest pointers representing the dependencies to a empty vector
                    defaultQuest -> subquests_ = {};  // setting the vector of Quest pointers representing the subquests to a empty vector
                    addQuest(defaultQuest);
                    temp_subquests.push_back(defaultQuest);  // adding it to the Quest
                }
            } 
        }
        addQuest(title, descript, completion, exp, temp_dependencies, temp_subquests);
    }
}

/**
    @param: A string reference to a quest title
    @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/

int QuestList::getPosOf(const std::string& quest_title) const {
    // only way to traverse through a doubly linked list is through a while loop
        
    Node<Quest*> *one = first_;  // creating a copy of a node from DoublyLinkedList.hpp
    int position = 0;
    while(one != nullptr) {
        if (one -> getItem() -> title_ == quest_title) {  // checks if the title is equal to the parameter
            return position;
        } else {
            position++;
            one = one -> getNext();  // setting the current node to the next node
        }
    }
    return -1;  // returns -1 if the given quest is not found in the linked list
}

/**
    @param: A string reference to a quest title
    @return: True if the quest with the given title is already in the QuestList
*/

bool QuestList::contains(const std::string& quest_title) const {
    return getPosOf(quest_title) != -1;
}

/**
    @pre: The given quest is not already in the QuestList
    @param:  A pointer to a Quest object
    @post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
           
    @return: True if the quest was added or updated successfully, False otherwise
*/

bool QuestList::addQuest(Quest* add) {
    if (contains(add -> title_)) {  // if the quest is inside the linked list
        if (getPointerTo(getPosOf(add -> title_)) -> getItem() -> description_ != "NOT DISCOVERED") {
            return false;
        }
        else {
            getPointerTo(getPosOf(add -> title_)) -> getItem() -> description_ = add -> description_;
            getPointerTo(getPosOf(add -> title_)) -> getItem() -> completed_ = add -> completed_;
            getPointerTo(getPosOf(add -> title_)) -> getItem() -> experience_points_ = add -> experience_points_;
            getPointerTo(getPosOf(add -> title_)) -> getItem() -> dependencies_ = add -> dependencies_;
            getPointerTo(getPosOf(add -> title_)) -> getItem() -> subquests_ = add -> subquests_;
            
            return true;
        }
    }
    else {
        if (insert(getLength(), add)) {
            for (auto i: add -> dependencies_) {
                if (!contains(i -> title_)) {
                    addQuest(i);  // adds the depenedencies
                }
            }
            for (auto j: add -> subquests_) {
                if (!contains(j -> title_)) {
                    addQuest(j);  // adds the subquests
                }
            }
            return true;
            } else {
                return false;
        }
    }
}

/**
    @param:  A reference to string representing the quest title
    @param:  A reference to string representing the quest description
    @param:  A reference to boolean representing if the quest is completed
    @param:  An reference to int representing experience points the quest rewards upon completion 
    @param:  A reference to vector of Quest pointers representing the quest's dependencies
    @param:  A reference to vector of Quest pointers representing the quest's subquests
    @post:   Creates a new Quest object and inserts a pointer to it into the QuestList. 
             If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
             Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
             

    @return: True if the quest was added or updated successfully, False otherwise

*/

bool QuestList::addQuest(const std::string& quest_title, const std::string& quest_description, const bool& complete, const int& exp, const std::vector<Quest*>& dependency, const std::vector<Quest*>& subquest) {
    Quest* quest = new Quest(quest_title, quest_description, complete, exp, dependency, subquest);  // creating a new quest individually 
    return addQuest(quest);  // return true / false depending on whatever addQuest outputs

}

/**
    @param:  A Quest pointer
    @return: A boolean indicating if all the given quest's dependencies are completed
*/

bool QuestList::dependenciesComplete(Quest* dependencies_complete) {
    for (int i = 0; i < dependencies_complete -> dependencies_.size(); i++) {  // loops through the quest's dependence vector
        if (!(dependencies_complete -> dependencies_[i] -> completed_)) {  // if the quest's dependence of i is not complete, then return false. Else return true
            return false;
        }
    }
    return true;
}

/**
    @param: A Quest pointer
    @return: A boolean if the given quest is available.
    Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
*/

bool QuestList::questAvailable(Quest* available) {

    if (!dependenciesComplete(available) || available -> completed_) {  // if the dependencies isn't complete OR the actual quest isn't complete (neither are complete) return false;
        return false;
    }
    return true;
}

/**
    @param: A Quest pointer
    @post: Prints the quest title and completion status
    The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/

void QuestList::printQuest(Quest* print_quest) {  // think of print_quest as a already created quest because of the parameterized constructor and you are able to access the title, description, etc
    std::string temp = "";
    if (print_quest -> completed_ == true) {
        temp = "Complete";

    } else {
        temp = "Not Complete";
    }
    std::cout << print_quest -> title_ << ": " << temp  // you're accessing both quest_title_ and quest_complete_ from a quest and printing them out
    << "\n" << print_quest -> description_ << "\n\n";  // prints the quest description

}

// helper function
void QuestList::queryHelp(Quest* query) {

    if (query -> dependencies_.empty() || dependenciesComplete(query)) {  // if the dependencies vector is empty OR if the dependency is complete
        std::cout << "Ready: " << query -> title_ << "\n";
        return;
    }

    for (int i = 0; i < query -> dependencies_.size(); i++) {
        if (!(query -> dependencies_[i] -> completed_)) {
            queryHelp(query -> dependencies_[i]);  // recursive call for all dependencies 
        }
    }
    std::cout << "  " << query -> title_ << "\n";
}

/**
    @param: A string reference to a quest title
    @post:  Prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
            If any of the quest's incomplete dependencies have an incomplete dependency, recursively print the quests that need to be done in order, indenting incomplete quests. 
            The indentation for incomplete quests is 2 spaces: "  "    
            The format of the list should be of the following forms for each different case:

            Query: [Quest Title]
            No such quest.
    
            Query: [Quest Title]
            Quest Complete
    
            Query: [Quest Title]
            Ready: [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
              [Quest Title]
            
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Dependency2]
              [Quest Title]
              
     If the given quest title is not found in the list, print "No such quest."
*/

void QuestList::questQuery(const std::string& quest_title) {

    std::cout << "Query: " << quest_title << "\n";

    if (!(contains(quest_title))) {  // if it doesn't contain the quest title
        std::cout << "No such quest.\n";
        return;

    }
    Quest* new_quest = getPointerTo(getPosOf(quest_title)) -> getItem();

    if (new_quest -> completed_) {  // if the quest is complete
        std::cout << "Quest Complete\n";
        return;

    } else {
        queryHelp(new_quest);
    }
}

/**
    @return: An integer sum of all the experience gained
    Note: This should only include experience from completed quests 
*/

int QuestList::calculateGainedExperience() {
    Node<Quest*> *one = first_;  // since "one" is the first node, it has access to everything Quest has: title, description, completion, etc
    int xp;
    while (one != nullptr) {  // loops through the linked list
        if (one -> getItem() -> completed_) {  // gets the quest_complete_ value based on the node's position. Sees if the quest is complete
            xp += one -> getItem() -> experience_points_;  // increase the experience points
        }
        one = one -> getNext();  // moves the node's position
    }
    return xp;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
    Note: Also consider the potential experience if a subquest itself has subquests.
*/

int QuestList::calculateProjectedExperience(Quest* main_quest) {
    int sum_of_exp = 0;  // int variable
    sum_of_exp += main_quest -> experience_points_;  // add the main quest experience

    for (int i = 0; i < main_quest -> subquests_.size(); i++) {
        sum_of_exp += calculateProjectedExperience(main_quest -> subquests_[i]);  // recursion - adds all the subquests' experience points
    }
    return sum_of_exp;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
    Note: Also consider the experience gained if a completed subquest itself has subquests.  
*/

int QuestList::calculatePathwayExperience(Quest* main_quest) {
    int sum_of_pathway_exp = 0;

    if (main_quest -> completed_) {  // if the quest is complete
        sum_of_pathway_exp += main_quest -> experience_points_;  // add the experience points
    }

    for (int i = 0; i < main_quest -> subquests_.size(); i++) {  // loops through the subquests

        sum_of_pathway_exp += calculatePathwayExperience(main_quest -> subquests_[i]);  // adding all the subquest's experience
    }
    return sum_of_pathway_exp;
}

/**
    @param: A string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every quest in the list.
           With filter "COMPLETE":   Only print out the completed quests in the list.
           With filter "INCOMPLETE": Only print out the incomplete quests in the list.
           With filter "AVAILABLE":  Only print out the available quests in the list.
           If an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
    [Quest title]: [Complete / Not Complete]  
    [Quest description]\n
*/

void QuestList::questHistory(const std::string& filter) {
    if (filter != "NONE" && filter != "COMPLETE" && filter != "INCOMPLETE" && filter != "AVAILABLE") {
        std::cout << "Invalid Filter\n";

    } else {
        Node<Quest*> *one = first_;
        while (one != nullptr) {  // keeps looping through the linked list until the node is equal to NULLPTR
            if (filter == "NONE") {
                printQuest(one -> getItem());

            } else if (filter == "COMPLETE") {
                if (one -> getItem() -> completed_) {
                    printQuest(one -> getItem());
                }

            } else if (filter == "INCOMPLETE") {
                if (!(one -> getItem() -> completed_)) {
                    printQuest(one -> getItem());
                }

            } else if (filter == "AVAILABLE") {
                if (questAvailable(one -> getItem())) {  // checks if the quest is available
                    printQuest(one -> getItem());
                }
            }
            one = one -> getNext();  // points to the next node in the linked list
        }
    }
}


// helper function
void QuestList::quest_detail_helper (Quest* q, int num_of_spaces) {
    std::string comp = "";

    for (int i = 0; i < num_of_spaces; i++) {  // prints out the number of spaces (identation)
        comp +=  " ";
    }

    for (int i = 0; i < q -> subquests_.size(); i++) {  // loops through the subquests (if the for-loop runs, then a subquest exist)

        quest_detail_helper(q -> subquests_[i], num_of_spaces + 2);  // recall the function and pass in the current subquest[i] as a parameter

        if (q -> subquests_[i] -> completed_) {  // checks if the quest is complete or not
            std::cout << comp << q -> subquests_[i] -> title_ << ": Complete" << "\n";
        } else {
            std::cout << comp << q -> subquests_[i] -> title_ << ": Not Complete" << "\n";
        }
    }
}


/**
    @param: A quest pointer to a main quest
    @post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/

void QuestList::printQuestDetails(Quest* main_quest) {
    double pathway = calculatePathwayExperience(main_quest);  // converts pathway experience to doubles
    double projected = calculateProjectedExperience(main_quest);  // converts projected experience to doubles

    std::cout << main_quest -> title_ << " (" <<  int((pathway / projected) * 100) << '%' << " Complete)" << std::endl;  // prints out the quest name and the percentage of it's completion

    if (main_quest -> completed_) {  // if the quest is complete
        return;
    }

    quest_detail_helper(main_quest, 2);  // calling the helper function (recursive function), passing in the main quest and 2 for number of spaces as parameters

}