
/*********************************************************************
** Daniel Mesa
** 10/13/19
** This is a class named Board that creates a board of
** size row and column. It relays the color of the square
** and prints the board with ant location.
***********************************************************************/
#include "Board.hpp"
#include <iostream>

/***************************************************************************
** Board::Board()
** This is the default constructor that initializes the array/board
** with the starting positions of x and o. It also initializes the
** gameState to unfinished and the current position of x.
******************************************************************************/
Board::Board()
{
    rows = 0;
    columns = 0;
}

/***************************************************************************
** Board::Board(int ofrows, int ofcolumns)
** This method initializes the row and columns to create board
** size and populates the board with white spaces.
******************************************************************************/
Board::Board(int ofrows, int ofcolumns){
    
    //setting variables
    rows = ofrows;
    columns = ofcolumns;
    
    //create array of pointers for board rows
    ptrToSquare = new char*[rows];
    
    //allocate array of column sized memory for each row
    for (int i = 0; i < rows; i++)
    {
        ptrToSquare[i] = new char[columns];
    }
    
    //initialize the list with white spaces
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            ptrToSquare[i][j] = ' ';
        }
    }
    
};

/***************************************************************************
** Board::Board()
** This method returns the row size.
******************************************************************************/

int Board::getRows()
{
    return rows;
};

/***************************************************************************
** Board::Board()
** This method returns the column size.
******************************************************************************/
int Board::getColumns()
{
    return columns;
};


/***************************************************************************
** Board::Board()
** This method takes in the location of the ant and the color
** to change the square. It then changes the color of the current
** square at that location.
******************************************************************************/
bool Board::cascadeDown(int aColumn, char aChip)
{
    bool won = false;
    
    for(int i = 0; i < rows; i++)
    {
        if(ptrToSquare[i][aColumn] == 'X'|| ptrToSquare[i][aColumn] == 'O')
        {
            if(i == 0)
            {
                std::cout << "That column is full." << std::endl;
            }
            else
            {
                ptrToSquare[(i-1)][aColumn] = aChip;
                won = ifWon(i-1,aColumn);
                break;
            }
        }
        else if(i == (rows - 1))
        {
            ptrToSquare[i][aColumn] = aChip;
            won = ifWon(i,aColumn);
            break;
        }
            
    }
    
    return won;
}

bool Board::ifWon(int aRow, int aColumn)
{
    char chip = ptrToSquare[aRow][aColumn];
    bool win = false;
    int winCount = 0;
    
    for(int i = 0; i < columns; i++)
    {
        if(ptrToSquare[aRow][i] == chip)
        {
            winCount++;
        }
        else
        {
            winCount = 0;
        }
        
        if(winCount == 4)
        {
            win = true;
        }
    }
    
    if(win == false)
    {
        winCount = 0;
        
        for(int i = 0; i < rows; i++)
        {
            if(ptrToSquare[i][aColumn] == chip)
            {
                winCount++;
            }
            else
            {
                winCount = 0;
            }
            
            if(winCount == 4)
            {
                win = true;
            }
        }
    }
    
    if(win == false)
    {
        win = ifWonDiagonal(aRow, aColumn);
    }
    
    return win;
}

/***************************************************************************
** Board::Board()
** This method takes in the location of the ant and the orientation
** of the ant and displays the board
******************************************************************************/

void Board::displayTheBoard()
{

    //print board
    for(int i = 0; i < rows; i++)
    {
        //print row starter
        std::cout << "|";
        
        for(int j = 0; j < columns; j++){
            
            //print char
            std::cout << ptrToSquare[i][j];
            
            //print column separator
            std::cout << "|";
        }
        
        //print row ender
        std::cout << "\n";
    }
    
    //number the columns
    std::cout<<" 1 2 3 4 5 6 7 8 9 10\n" <<std::endl;
    
}


bool Board::ifWonDiagonal(int aRow, int aColumn)
{
    int initialRow = aRow;
    int initialColumn = aColumn;
    char chip = ptrToSquare[aRow][aColumn];
    bool win = false;
    int winCount = 0;
    
    if(win == false)
    {
        winCount = 0;
        
        while(aRow != 0 && aColumn != (columns - 1))
        {
            aRow--;
            aColumn++;
        }
        
        while(aRow < rows && aColumn >= 0)
        {

            if(ptrToSquare[aRow][aColumn] == chip)
            {
                winCount++;
            }
            else
            {
                winCount = 0;
            }
            if(winCount == 4)
            {
                win = true;
            }
            
            aRow++;
            aColumn--;
        }
    }
    
    if(win == false)
    {
        winCount = 0;
        
        while(initialRow != 0 && initialColumn != 0)
        {
            initialRow--;
            initialColumn--;
        }
        
        while(initialRow < rows && initialColumn < columns)
        {
            if(ptrToSquare[initialRow][initialColumn] == chip)
            {
                winCount++;
            }
            else
            {
                winCount = 0;
            }
            if(winCount == 4)
            {
                win = true;
            }
            
            initialRow++;
            initialColumn++;
        }
    }
    
    return win;
}
