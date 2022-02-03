#include "pegsolitaire.h"
namespace BoardGames{

//Constructor calls the initialize() to initialize the board
PegSolitaire::PegSolitaire(){
   initialize();
}  


//initialization of the peg board
void PegSolitaire::initialize(){

    board =  { 
                {' ',' ' ,' ', 'P', 'P', 'P',' ', ' ', ' '},
                {' ',' ' ,' ', 'P', 'P', 'P',' ' ,' ', ' '},
                {' ' ,' ',' ', 'P', 'P', 'P',' ' ,' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'P', 'P', 'P', 'P', '.', 'P', 'P', 'P', 'P'},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                {' ' ,' ',' ', 'P', 'P', 'P',' ', ' ',' '},
                {' ' ,' ',' ', 'P', 'P', 'P',' ', ' ',' '},
                {' ' ,' ',' ', 'P', 'P', 'P',' ', ' ',' '},
    };
    
}

//printing of the board in a colorful way bu using ansi escape codes
void PegSolitaire::print(){

    cout << "\x1b[2J"; 
    cout << "\033[0;0H"; 
    cout << endl << endl;
    cout << "\033[1;39m  A B C D E F G H L\033[0m"<<endl;
    for (auto i = 0; i < board.size(); i++)
    {
        cout<<"\033[1;39m"<<i+1<<"\033[0m"<<" ";
        for (auto j = 0; j < board[i].size(); j++)
        {
            cout << "\033[1;33m"<<board[i][j]<<"\033[0m"<<" ";

        }
        cout<<endl;
    }
        cout<<endl;
        cout<<endl;

    
}

//this function takes string as a parameter from user to play 
void PegSolitaire::playUser(const string& str){

    int row, column, direction;
    char dirChar;
    int select;
    int check = 0;

    //converting of char to int
    row = str[0]-49;
    column = str[1] -65 ;

    switch (str[3])
    {
    case 'r':
    case 'R':
        if (column + 2 < board[row].size() && (board[row][column] == 'P' && board[row][column + 1] == 'P' && board[row][column + 2] == '.'))// check the move if it is possible
        {
            //switch the pegs and empty to the right side by rules if it is possible
            board[row][column] = '.';
            board[row][column +1] = '.';
            board[row][column + 2] = 'P';

            check = 1;
        }
        else
            cout << "Error!!--Wrong Move--TRY AGAIN --" << endl << endl;


        break;

    case 'l':
    case 'L':

        if (column - 2 >= 0 && (board[row][column] == 'P' && board[row][column - 1] == 'P' && board[row][column - 2] == '.'))// check the move if it is possible
        {
            //switch the pegs and empty to the left side by rules if it is possible
            board[row][column] = '.';
            board[row][column - 1] = '.';
            board[row][column - 2] = 'P';

            check = 1;

        }
        else
            cout << "Error!!--Wrong Move--TRY AGAIN --" << endl << endl;
        break;

    case 'd':
    case 'D':
        if (row + 2 < board.size() && (board[row][column] == 'P' && board[row + 1][column] == 'P' && board[row + 2][column] == '.'))// check the move if it is possible
        {
            //switch the pegs and empty to the down side by rules if it is possible
            board[row][column] = '.';
            board[row + 1][column] = '.';
            board[row + 2][column] = 'P';

            check = 1;

        }
        else
            cout << "Error!!--Wrong Move--TRY AGAIN --" << endl << endl;
        break;

    case 'u':
    case 'U':
        if (row - 2 >= 0 && (board[row][column] == 'P' && board[row - 1][column] == 'P' && board[row - 2][column] == '.')) // check the move if it is possible
        {

            //switch the pegs and empty to the up side by rules if it is possible
            board[row][column] = '.';
            board[row - 1][column] = '.';
            board[row - 2][column] = 'P';
            check = 1;
        }
        else
            cout << "Error!!--Wrong Move--TRY AGAIN --" << endl << endl;
        break;

    default:
            cout << "Error!!--TRY AGAIN --" << endl << endl;
        break;
    }

    if (check == 1) // print the which position played
    {

        cout << "Column: " << column << " ";
        cout << "Row: " << row + 1 << " ";
        cout << "Direction: " << direction << " " << endl;
    }
}

//this returns the remaining number of peg
int PegSolitaire::boardScore(){

    int score=0;

    //coun the number of peg
    for (auto i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++) 
            if (board[i][j] == 'P')
                ++score;  

    return score;
    
}

//this function checks if the board is finished 
bool PegSolitaire::endGame(){

    int control = 1;
    int counter = 0;

    for (auto i = 0; i < board.size(); i++)
    {
        for (auto j = 0; j < board[i].size(); j++)
        {
        	//check if there is any possible movement

            if (board[i][j] == ' ') {}

            //check the up side
            else if (i + 2 < board.size() && (board[i][j] == 'P' && board[i + 1][j] == 'P'  && board[i + 2][j] == '.' ))
                return false;

            //check the right side
            else if (j + 2 < board[i].size() && (board[i][j] == 'P'  && board[i][j + 1] == 'P'  && board[i][j + 2] == '.' ))
                return false;

            //check the down side
            else if (i - 2 >= 0 && (board[i][j] == 'P' && board[i - 1][j] == 'P' && board[i - 2][j] == '.' ))
                return false;

            //check the left side
            else if (j - 2 >= 0 && (board[i][j] == 'P' && board[i][j - 1] == 'P' && board[i][j - 2]  == '.' ))
                return false;

        }
    }
    print();
    cout<<"Your Score: "<<boardScore()<<endl;
    return true;

}

//this plays the game automaticlly by creating random number
void PegSolitaire::playAuto(){

    int row,column;
    bool check = false;
    string str;

    while(!check){

        //create random row and col
        row = rand()%board.size();
        column = rand()%board[0].size() ;

        // check the move to play to the right
        if (column + 2 < board[row].size() && (board[row][column] == 'P' && board[row][column + 1] == 'P' && board[row][column + 2] == '.'))
        {

            //do the required move
            board[row][column] = '.';
            board[row][column +1] = '.';
            board[row][column + 2] = 'P';
            cout << "Row: " << row+1 << " Column: "<<char(column+65)<<" Direction: Right" << endl;
            check = true;


        }

        // check the move to play to the left
        else if (column - 2 >= 0 && (board[row][column] == 'P' && board[row][column - 1] == 'P' && board[row][column - 2] == '.'))
        {
            board[row][column] = '.';
            board[row][column - 1] = '.';
            board[row][column - 2] = 'P';
            cout << "Row: " << row+1 << " Column: "<<char(column+65)<<" Direction: Left" << endl;
            check = true;


        }

        // check the move to play to the down
        else if (row + 2 < board.size() && (board[row][column] == 'P' && board[row + 1][column] == 'P' && board[row + 2][column] == '.'))
        {
            board[row][column] = '.';
            board[row + 1][column] = '.';
            board[row + 2][column] = 'P';
            cout << "Row: " << row+1 << " Column: "<<char(column+65)<<" Direction: Down" << endl;
            check = true;

        }

        // check the move to play to the up
        else if (row - 2 >= 0 && (board[row][column] == 'P' && board[row - 1][column] == 'P' && board[row - 2][column] == '.')) 
        {
            board[row][column] = '.';
            board[row - 1][column] = '.';
            board[row - 2][column] = 'P';
            cout << "Row: " << row+1 << " Column: "<<char(column+65)<<" Direction: Up" << endl;
            check = true;
        }
      
    }

}
}