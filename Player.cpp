/*********************************************************************
** Daniel Mesa
** 10/13/19
** This is a class named Ant that keeps track of the location
** of ant, the direction, and the boarders of myBoard.
***********************************************************************/
#include <iostream>
#include "Player.hpp"

using std::cout;

/***************************************************************************
** Ant::Ant()
** This is the default constructor that initializes the ant location
** to zero and direction to north.
******************************************************************************/
Player::Player()
{
    name = " ";
    chip = '-';
}

void Player::setName(std::string aName)
{
    name = aName;
}
void Player::setChip(int aChip)
{
    chip = aChip;
}

std::string Player::getName()
{
    return name;
}

int Player::getChip()
{
    return chip;
}
