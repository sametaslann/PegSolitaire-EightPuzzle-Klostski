
#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H

#include<iostream>
#include<vector>
#include<windows.h>
#include<string.h>
#include<time.h>
#include <chrono>
#include <thread>


using namespace std;

namespace BoardGames{

class BoardGame2D
{
private:
    
public:
    //constructors
    BoardGame2D(){};
    //functions
    virtual void playUser(const string& str) = 0;
    virtual void playUser() final;
    virtual void print() = 0;
    virtual void playAuto() = 0 ; // for one move 
    virtual bool endGame() = 0;
    virtual void playAutoAll() final;
    virtual int boardScore() = 0;
    static void playVector(vector<BoardGame2D*> games);
    void slowPrint(const char *s);
    virtual void initialize() = 0; 


  //friend ostream& operator<<(const iostream& out, const BoardGame2D& board);
};

}


#endif