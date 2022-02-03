#ifndef KLOSTSKI_H
#define KLOSTSKI_H

#include "boardgame2d.h"

namespace BoardGames{

class Klostski : public BoardGame2D
{  
public: 
    Klostski();
    void playUser(const string& str); 
    void print();                     
    void playAuto();
    bool endGame(); 
    int boardScore();
    void initialize();                   
    vector<vector<int>> &getShape(int x);
    void setShape(vector<vector<int>> shape,int x); 
    bool moveControl(int num, int direction);

private:
   vector<vector<char>> board;
   vector<vector<int>> shape0;
   vector<vector<int>> shape1;
   vector<vector<int>> shape2;
   vector<vector<int>> shape3;
   vector<vector<int>> shape4;
   vector<vector<int>> shape5;
   vector<vector<int>> shape6;
   vector<vector<int>> shape7;
   vector<vector<int>> shape8;
   vector<vector<int>> shape9;
};

}

#endif