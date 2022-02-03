#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include "boardgame2d.h"

namespace BoardGames{

class EightPuzzle : public BoardGame2D
{
public:
    EightPuzzle();
    void playUser(const string& str);
    void playAuto();
    bool endGame();
    void print();
    int boardScore();
    void initialize();
   



private:
    vector<vector<int>> board;
};

}

#endif