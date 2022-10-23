#include"klostski.h"

namespace BoardGames{

//Constructor calls the initialize() to initialize the board
Klostski::Klostski(){
   initialize();
}
  
//this function checks if the board is finished 
bool Klostski::endGame(){

   if (shape1[1][0]== 9 && shape1[1][0] == 8 ){
      cout<<"Your Score: "<<boardScore()<<endl;
      return true;
   }
   else
      return false;   

}

int Klostski::boardScore(){
   return 0;
}

//initialization of the Klostski board
void Klostski::initialize(){
   board = { 
                {char(218),char(196),char(191),   char(218),char(196),char(196),char(196),char(196),char(191) ,   char(218),char(196) ,char(191)},
                {char(179),   '0',   char(179),   char(179)  ,   ' ','1',' ', ' ',                  char(179) ,   char(179),   '2',    char(179)},
                {char(179),   ' ',   char(179),   char(179)  ,   ' ',' ',' ', ' ',                  char(179) ,   char(179),   ' ',    char(179)},        
                {char(192),char(196),char(217),   char(192),char(196),char(196),char(196),char(196),char(217) ,   char(192),char(196) ,char(217)},


                {char(218),char(196),char(191),   char(218),char(196),char(196),  '4',    char(196),char(191) ,   char(218),char(196) ,char(191)},
                {char(179),   '3',   char(179),   char(192),char(196),char(196),char(196),char(196),char(217) ,   char(179),   '5',    char(179)},

                {char(179),   ' ',   char(179),   char(218),'6',char(191),       char(218),'7',char(191)       ,   char(179),   ' ',    char(179)},        
                {char(192),char(196),char(217),   char(192),char(196),char(217), char(192),char(196),char(217) ,   char(192),char(196) ,char(217)},


                {char(218),'8',char(191),         ' ',' ',' ',        ' ',' ',' ',                                 char(218),'9',char(191)},        
                {char(192),char(196),char(217),   ' ',' ',' ',        ' ',' ',' ',                                 char(192),char(196),char(217)},            
    };

   //each vector<int> holds the coordinate of the top-left corner and the bottom-right corner
   shape0 ={{0,0},{3,2}};
   shape1 ={{0,3},{3,8}};
   shape2 ={{0,9},{3,11}};
   shape3 ={{4,0},{7,2}};
   shape4 ={{4,3},{5,8}};
   shape5 ={{4,9},{7,11}};
   shape6 ={{6,3},{7,5}};
   shape7 ={{6,6},{7,8}};
   shape8 ={{8,0},{9,2}};
   shape9 ={{8,9},{9,11}};



}
//this is checking if the move is possible
bool Klostski::moveControl(int num, int direction){

   vector<vector<int>> shape = getShape(num);


   if (direction == 1){ // right side
      if(board[0].size()>(shape[1][1]+1) && board [shape[1][0]] [shape[1][1]+1] == ' ' && board [shape[0][0]] [shape[1][1]+1] == ' '){
         
         return true;
         
      }
   }
   else if (direction == 2) { //left side
 
   
      if(0<(shape[0][1]-1) && board [shape[0][0]] [shape[0][1]-1] == ' ' && board [shape[1][0]] [shape[0][1]-1] == ' '){
         
         return true;
      }
}
   
   else if (direction == 3){ // down side
      if(board.size()>(shape[1][0]+1) &&  board [shape[1][0]+1] [shape[1][1]] == ' ' && board [shape[1][0]+1] [shape[0][1]] == ' ')
      {
         return true;
      }
   }
      
   
   else if (direction == 4){ // up side
      if(0<(shape[0][0]-1) && board [shape[0][0]-1] [shape[0][1]] == ' ' && board [shape[0][0]-1] [shape[1][1]] == ' ')
         {
         return true;
      }
   }

   return false;
   //if move is not possible , return false


}

//this plays the game automaticlly by creating random number
void Klostski::playAuto(){

   string str;
   int number,direction;
   srand(time(NULL));
 
   
   do
   {
      //create random number and direction
      number = rand()%10;
      direction = rand()%4 + 1;

   } while (!moveControl(number,direction));//control that
   

   
   if (direction == 1)
      str.push_back('R');
   else if (direction == 2)
      str.push_back('L');
   else if (direction == 3)
      str.push_back('D');
   else
      str.push_back('U');
   
   str.push_back(char(number+48));//convert int to char
   cout<<str<<endl;
   playUser(str); // invoke the playUser to do the move

}

//printing of the board in a colorful way bu using ansi escape codes
void Klostski::print(){

   cout << "\x1b[2J"; 
   cout << "\033[0;0H"; // move cursor to 0,0
   cout << endl << endl;

   for (int i = 0; i < board.size(); i++)
   {
       for (int j= 0; j < board[i].size(); j++)
       {   
          cout << "\033[1;36m"<<board[i][j]<<"\033[0m";
       }
      cout<<endl;
   }
}

//this function is for changing the old coordinates with new coordinate
void Klostski::setShape(vector<vector<int>> shape,int x){
   
   switch (x)
   {
   case 0:
      shape0[0][0] = shape[0][0];   shape0[0][1] = shape[0][1];
      shape0[1][0] = shape[1][0];   shape0[1][1] = shape[1][1];
      break;
     
   case 1:
      shape1[0][0] = shape[0][0];   shape1[0][1] = shape[0][1];
      shape1[1][0] = shape[1][0];   shape1[1][1] = shape[1][1];
      break;
   case 2:
      shape2[0][0] = shape[0][0];   shape2[0][1] = shape[0][1];
      shape2[1][0] = shape[1][0];   shape2[1][1] = shape[1][1];
      break;
   case 3:
      shape3[0][0] = shape[0][0];   shape3[0][1] = shape[0][1];
      shape3[1][0] = shape[1][0];   shape3[1][1] = shape[1][1];
      break;
   case 4:
      shape4[0][0] = shape[0][0];   shape4[0][1] = shape[0][1];
      shape4[1][0] = shape[1][0];   shape4[1][1] = shape[1][1];
      break;
   case 5: 
      shape5[0][0] = shape[0][0];   shape5[0][1] = shape[0][1];
      shape5[1][0] = shape[1][0];   shape5[1][1] = shape[1][1];
      break;
   case 6: 
      shape6[0][0] = shape[0][0];   shape6[0][1] = shape[0][1];
      shape6[1][0] = shape[1][0];   shape6[1][1] = shape[1][1];
      break;
   case 7: 
      shape7[0][0] = shape[0][0];   shape7[0][1] = shape[0][1];
      shape7[1][0] = shape[1][0];   shape7[1][1] = shape[1][1];
      break;
      
   case 8: 
      shape8[0][0] = shape[0][0];   shape8[0][1] = shape[0][1];
      shape8[1][0] = shape[1][0];   shape8[1][1] = shape[1][1];
      break;
     
   case 9:
      shape9[0][0] = shape[0][0];   shape9[0][1] = shape[0][1];
      shape9[1][0] = shape[1][0];   shape9[1][1] = shape[1][1];
      break;
   default:
      exit(-1);
      break;
   }
   

}

//this function return the coordinate of required shape
vector<vector<int>>& Klostski::getShape(int x){


   switch (x)
   {
   case 0:
      return shape0;
   case 1:
      return shape1;
   case 2:
      return shape2;  
   case 3:
      return shape3; 
   case 4:
      return shape4; 
   case 5: 
      return shape5; 
   case 6: 
      return shape6;
   case 7: 
      return shape7;
   case 8: 
      return shape8;
   case 9: 
      return shape9;
   default:
      exit(-1);
      break;
   }
}

//this function takes string as a parameter from user to play 
void Klostski::playUser(const string& str){

   vector<vector<int>> shape = getShape(int(str[1])-48);

   switch (str[0])
   {
   case 'R'://right
      for (int i = shape[1][0]; i >=  shape[0][0]; i--)
      {
         for (int j = shape[1][1] ; j >= shape[0][1]; j--)
         {
            board[i][j+3] = board[i][j];
            board[i][j] = ' ';
         
         }
      }
      shape[0][0]= shape[0][0];
      shape[0][1]= shape[0][1] + 3;
      shape[1][0]= shape[1][0];
      shape[1][1]= shape[1][1] + 3;
      setShape(shape,int(str[1])-48);
      
      break;

      break;
   case 'L'://left

      for (int i = shape[0][0]; i <= shape[1][0]; i++)
      {
         for (int j = shape[0][1]; j <= shape[1][1]; j++)
         {
            board[i][j-3] = board[i][j];
            board[i][j] = ' ';
         }
      }
      shape[0][0]= shape[0][0] ;
      shape[0][1]= shape[0][1] - 3;
      shape[1][0]= shape[1][0];
      shape[1][1]= shape[1][1] - 3;

      setShape(shape,int(str[1])-48);

      break;

   case 'D'://down
      for (int i = shape[1][0]; i >=  shape[0][0]; i--)
      {
         for (int j = shape[1][1] ; j >= shape[0][1]; j--)
         {
            board[i+2][j] = board[i][j];
            board[i][j] = ' ';
         
         }
      }
      shape[0][0]= shape[0][0] + 2;
      shape[0][1]= shape[0][1];
      shape[1][0]= shape[1][0] + 2;
      shape[1][1]= shape[1][1] ;
      setShape(shape,int(str[1])-48);
      break;

   case 'U'://up

      for (int i = shape[0][0]; i <= shape[1][0]; i++)
      {
         for (int j = shape[0][1]; j <= shape[1][1]; j++)
         {
            board[i-2][j] = board[i][j];
            board[i][j] = ' ';
         }
      }
      shape[0][0]= shape[0][0] - 2;
      shape[0][1]= shape[0][1];
      shape[1][0]= shape[1][0] - 2;
      shape[1][1]= shape[1][1] ;

      setShape(shape,int(str[1])-48);
      
      break;

   default:
      break;
   }

}
}