#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include "boardgame2d.h"


namespace BoardGames{

class PegSolitaire : public BoardGame2D
{
public:
    PegSolitaire();
    void playUser(const string& str) ;
    void print() override;
    void playAuto();
    bool endGame();
    int boardScore();
    void initialize();

   

private:
    vector<vector<char>> board;   
};

}

#endif