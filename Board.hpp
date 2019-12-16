/*********************************************************************
** Daniel Mesa
** 10/13/19
** This is a class named Board  with three data members.
** two ints named row and columns that creates a board
** of size row and column.
** A pointer to a pointer that keeps track of the specific
** color of square.
***********************************************************************/
#ifndef board_hpp
#define board_hpp

#include <string>
#include "Player.hpp"

using std::string;

class Board {
    private:
        int rows,
            columns;
        char** ptrToSquare;
        
    
    public:
    Board();
    Board(int ofrows, int ofcolumns);
    bool cascadeDown(int aColumn, char aChip);
    void displayTheBoard();
    bool ifWon(int aRow, int aColumn);
    bool ifWonDiagonal(int aRow, int aColumn);
    int getRows();
    int getColumns();

    
};

#endif /* board_hpp */
