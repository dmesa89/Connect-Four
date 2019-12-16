
#include "GamePlay.hpp"
#include "InputValidation.hpp"


void GamePlay::runGame()
{
    Board myBoard(10,10);
    
    int option;
    std::cout << "Welcome to Connect Four." <<std::endl;
    std::cout << "Would you like to:" << std::endl;
    std::cout << "1: Play" << std::endl;
    std::cout << "2: Quit" << std::endl;
    std::cout << "Please enter a corresponding number option: ";
    option = inputValidation();
    while(option < 1 || option > 2)
    {
        std::cout << "Please enter a valid option [1/2]: ";
        option = inputValidation();
    }
    
    if(option == 1)
    {
        int choice;
        std::cout << "Would you like to enter the names of the players?" << std::endl;
        std::cout << "1: Yes" << std::endl;
        std::cout << "2: No" << std::endl;
        std::cout << "Please enter a corresponding number option: ";
        choice = inputValidation();
        while(choice < 1 || choice > 2)
        {
            std::cout << "Please enter a valid option [1/2]: ";
            choice = inputValidation();
        }
        if(choice == 1)
        {
            changePlayer(player1, 1);
            changePlayer(player2, 2);
        }
        else
        {
            player1.setName("Player1");
            player2.setName("Player2");
        }
        player1.setChip('X');
        player2.setChip('O');
        std::cout <<"\n"<<player1.getName() << ": Your chip will be X"<<std::endl;
        std::cout <<player2.getName() << ": Your chip will be O"<<std::endl;
        std::cout <<"Have fun!\n"<<std::endl;
        
        keepPlaying = true;
        while(keepPlaying)
        {
            bool won = false;
            
            myBoard.displayTheBoard();
            while(!won)
            {
                int choice;
                std::cout <<player1.getName() <<": Enter a column choice [1..10]:  ";
                choice = inputValidation();
                while(choice < 1 || choice > 10)
                {
                    std::cout <<"Please enter a valid choice [1..10]: ";
                    choice = inputValidation();
                }
                won = myBoard.cascadeDown(choice-1, player1.getChip());
                myBoard.displayTheBoard();
                if(won)
                {
                    std::cout <<player1.getName() << " won! Congratulations!" <<std::endl;
                    keepPlaying = false;
                    
                }
                else
                {
                    std::cout <<player2.getName() <<": Enter a column choice [1..10]:  ";
                    choice = inputValidation();
                    while(choice < 1 || choice > 10)
                    {
                        std::cout <<"Please enter a valid choice [1..10]: ";
                        choice = inputValidation();
                    }
                    won = myBoard.cascadeDown(choice-1, player2.getChip());
                    myBoard.displayTheBoard();
                    if(won)
                    {
                        std::cout <<player2.getName() << "won! Congratulations!" <<std::endl;
                        keepPlaying = false;
                        
                    }
                }
            }
            

        }
        
    }
    
    
    
}

void GamePlay::changePlayer(Player& player, int num)
{
    std::string name;
    std::cout << "Please enter the name of player" <<num <<":";
    name = inputValidationString();
    player.setName(name);
}
