#include "eightpuzzle.h"

namespace BoardGames{

//initialization of the eightpuzzle board
void EightPuzzle::initialize(){

    int num;
    auto x=0,count=0;
    bool check ;
    srand(time(NULL));

    board.resize(3);//resize the vector by 3

    while (!(x ==2 && count == 2))
    {
        //generate random numbers that are between 1-8
        num = rand()%8 + 1;
        check = true;
        for (auto i = 0; i < board.size(); i++)
        {
            for (auto j = 0; j < board[i].size(); j++)
            {
               
                if (board[i][j] == num){
                    check = false;
                    
                }
            } 

        }
        cout<<endl;
        //make sure it's not the same number
        if (check){
            board[x].push_back(num);
            ++count;

            if (x == 2 && count == 2)
               board[x].push_back(0);
           
            if (count == 3){
                ++x;
                count = 0;
            }      
        }  
    }
}


//this returns the remaining number of peg
int EightPuzzle::boardScore(){

    auto count = 1,score=0;

    for (auto i = 0; i < board.size(); ++i) /*check whether numbers are sorted*/
	{
		for (auto j = 0; j < board[i].size(); ++j)
		{
            if (count == 9);

			else if (board[i][j] == count){
                ++score;
            }
            
            else;  
               
            ++count;    
		}
	}
    return score;
}

//this function checks if the board is finished 
bool EightPuzzle::endGame(){

   
	auto count=1;
	

	for (auto i = 0; i < board.size(); ++i) //check whether numbers are sorted
	{
		for (auto j = 0; j < board[i].size(); ++j)
		{
            if (count == 9);

			else if (board[i][j] == count);
            
            else    
                return false;
            ++count;

            
		}
	}
    cout<<"Your Score: "<<boardScore()<<endl;

    return true;
}

//this plays the game automaticlly by creating random number
void EightPuzzle::playAuto(){

    
    int row,column;
    bool check = false;

    string str;

    while (!check)
    {
        row = rand()%3;
        column = rand()%3 ;
        
        if (!check)
        {
             //check if the left side is empty
            for (auto i = column; i >= 0; --i)
            {
                if (board[row][i]==0)
                {
                    str.push_back(char(row+49));
                    str.push_back(char(column+65)); 
                    str.push_back(' ');
                    str.push_back('L'); 
                    check = true;
                    playUser(str);//send the str to move the board
                    break;
                }
            
            }
            
        }
        

		if (!check)
        {
             //check if the right side is empty
            for (auto i = column; i < 3 ; ++i) 
            {
                if (board[row][i]==0)
                {
                    str.push_back(char(row+49));
                    str.push_back(char(column+65)); 
                    str.push_back(' ');
                    str.push_back( 'R');
                    
                    check = true;

                    playUser(str);
                    break;

                }
            
            }
           
        }
        if (!check)
        {
            //check if the up side is empty
            for (auto i = row; i>=0; --i) 
            {
                if (board[i][column]==0)
                {
                    str.push_back(char(row+49));
                    str.push_back(char(column+65)); 
                    str.push_back(' ');
                    str.push_back( 'U');
                    check = true;
                    playUser(str);
                    break;    
                }
            }
           
        }
          
        if (!check)
        {
             //check if the down side is empty
            for (auto i = row; i < 3 ; ++i)
            {
                if (board[i][column]==0)
                {    
                    str.push_back(char(row+49));
                    str.push_back(char(column+65)); 
                    str.push_back(' ');
                    str.push_back( 'D');
                    check = true;
                    playUser(str);
                    break;
                }
            } 
           
        }
      
        
    }



}
//this function takes string as a parameter from user to play 
void EightPuzzle::playUser(const string& str){

    bool check = false;

    int temp;
    int row = str[0]-49;
    int column = str[1] -65 ;


    cout<<"str:"<<str<<endl;

    switch(str[3]){
	case 'L':
        //find out whether there is any empty block to the 'left' side of this row
		for (auto i = column; i >= 0; --i)
		{
			if (board[row][i]==0)
			{
				for (auto j = i+1; j <= column ; ++j)
				{
					temp = board[row][i];
					board[row][i] = board[row][j];
					board[row][j] = temp;
					++i; 
				}
				check = true;
				break;
			}
		}
		if (!check)
			printf("\n!!This move cannot be played !!\n");
		break;

	
	//if the selection is 'right', program will do as follow
	case 'R':
        //find out whether there is any empty block to the 'right' side of this row
		for (auto i = column; i < 3 ; ++i) 
		{
			if (board[row][i]==0)
			{
				for (auto j = i-1; j >= column ; --j)
				{
					temp = board[row][i];
					board[row][i] = board[row][j];
					board[row][j] = temp;
					--i; 
				}
				check = true;
				break;
			}
		}
		if (!check)
			printf("\n!!This move cannot be played !!\n");
		break;

	
	//if the selection is 'up', program will do as follow
	case 'U':
        //find out whether there is any empty block to the 'up' side of this column
		for (auto i = row; i>=0; --i) 
		{
			if (board[i][column]==0)
			{
				for (auto j = i+1; j <= row ; ++j)
				{
					temp = board[i][column];
					board[i][column] = board[j][column];
					board[j][column] = temp;
					++i; 
				}
				check = true;
				break;
			}
		}
		if (!check)
			printf("\n!!This move cannot be played !!\n");
		break;

	//if the selection is 'down', program will do as follow
	case 'D':
        //find out whether there is any empty block to the 'down' side of this column
		for (auto i = row; i < 3 ; ++i) 
		{
			if (board[i][column]==0)
			{
				
				for (auto j = i-1; j >= row ; --j)
				{
					temp = board[i][column];
					board[i][column] = board[j][column];
					board[j][column] = temp;
					--i; 
				}
				check = true;//controling of whether there is any empty block
				break;

			}
		}
		if (!check)
			printf("\n!!This move cannot be played !!\n");
		break;
	
	default:
		printf("\n>>>You have to enter a number between [0-3]<<<\n");
		break;
	}
}

EightPuzzle::EightPuzzle(){
    initialize();
}

//printing of the board in a colorful way bu using ansi escape codes
void EightPuzzle::print(){

    cout << "\x1b[2J"; 
    cout << "\033[0;0H"; // move cursor to 0,0
    cout << endl << endl;
    
    cout << "\033[1;31m   A B C \033[0m"<<endl;

    for (auto i = 0; i < 3; i++)
    {
        cout << "\033[1;31m ---------\033[0m"<<endl;

        cout << "\033[1;31m"<<i+1<<"\033[0m";

        cout << "\033[1;31m| \033[0m";

        for (auto j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
                cout << " " << " ";
            else
                cout << "\033[1;31m"<<board[i][j]<<"\033[0m"<<" ";

                
            
        }
        cout << "\033[1;31m| \033[0m"<<endl;

    }
        cout << "\033[1;31m ---------\033[0m"<<endl;

}
}