

#ifndef GamePlay_hpp
#define GamePlay_hpp

#include <iostream>
#include "Player.hpp"
#include "Board.hpp"

class GamePlay
{
    private:
        bool keepPlaying;
        Player player1;
        Player player2;
    
    public:
        void runGame();
        void changePlayer(Player&, int num);
        
    
    
    
    
    
};

#endif /* GamePlay_hpp */
