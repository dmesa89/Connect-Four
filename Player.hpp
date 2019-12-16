/*********************************************************************
* Daniel Mesa
* 10/13/19
* This is a class named Ant with three data members.
** An array of size two that tracks the movement of
** ant at starting location.
**A char orientation that is  starting direction of an ant
** A board class myboard that keeps track of matrix
***********************************************************************/

#ifndef Player_hpp
#define Player_hpp


#include <iostream>
#include "Board.hpp"
#include <string>


class Player {
    private:
        std::string name;
    char chip;
    
public:
    Player();
    void setName(std::string aName);
    void setChip(int aChip);
    
    std::string getName();
    int getChip();
    
    
};


#endif /* Player_hpp */
