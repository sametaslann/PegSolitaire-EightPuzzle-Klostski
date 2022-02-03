//This is the file: main.cpp
//There are test functions here.

//including header files which contain the classes
#include "eightpuzzle.h"
#include "klostski.h"
#include "pegsolitaire.h"

using namespace BoardGames;

int main(){

    int select=0;
    string str;

    BoardGame2D *callPlayVector;
    vector<BoardGame2D *> games(6);  
    BoardGame2D *game;


    games[0] = new PegSolitaire;
    games[1] = new PegSolitaire;
    games[2] = new EightPuzzle;
    games[3] = new EightPuzzle;
    games[4] = new Klostski;
    games[5] = new Klostski;

    //callPlayVector->playVector(games);

    while(select != 4)
    {
        cout<<"1-Peg Solitaire\n"
            <<"2-Eight Puzzle\n"
            <<"3-Klostski\n"
            <<"4-Exit\n" 

            <<"Which game do you want to play: ";
        cin >> select;

        switch (select)
        {
        case 1:
            game = new PegSolitaire;
            game->slowPrint("--Peg Solitaire Part--");
            cout <<endl<<"Press 0 to play auto..: ";
            cout <<endl<<"Press 1 to back menu: ";


            while(!game->endGame()){
                game->print();
                cout <<"Enter a string to move(2B-R)..: ";
                cin >> str;

                if (str[0] == '0')
                    game->playAuto();
                else if(str[0] == '1')
                    break;
                else
                    game->playUser(str);
            }




            break;
        case 2:
            game = new EightPuzzle;
            game->slowPrint("--Eight Puzzle Part--");
            cout <<"Press 0 to play auto..: ";

            while(!game->endGame()){
                game->print();
                cout <<endl<<"Enter a string to move(2B-R)..: ";
                cin >> str;

                if (str[0] == '0')
                    game->playAuto();
                else if(str[0] == '1')
                    break;
                else
                    game->playUser(str);
            }


            
            break;
        case 3:
            game = new Klostski;
            game->slowPrint("--Klostski Puzzle Part--");
            cout <<endl<<"Press 0 to play auto..: "<<endl;

            while(!game->endGame()){
                game->print();
                cout <<"Enter a string to move(D5)..: ";
                cin >> str;

                if (str[0] == '0'){
                    cout<<"A";
                   game->playAuto();
                }
                else if(str[0] == '1')
                    break;
                else
                    game->playUser(str);
            }

            break;

        case 4: 
            game->slowPrint("Exiting....");
            break;
        
        default:
            cout<<"Invalid Value"<<endl;
            break;
        
        }
    }
    
    /*cout<<"--Peg Solitaire Part--"<<endl;
    games[0]->print();

    cout<<Enter a string to move(2B-R)..: ";
    cin >> str;
    games[0]->playUser(str);
    games[0]->playAuto();
    games[0]->playAutoAll();*/
    
    /*cout<<"--Peg Solitaire Part--"<<endl;
    games[0]->print();

    cout<<Enter a string to move(2B-R)..: ";
    cin >> str;
    games[2]->playUser(str);
    games[2]->playAuto();
    games[2]->playAutoAll();*/
    
    
    /*cout<<"--Peg Solitaire Part--"<<endl;
    games[0]->print();

    cout<<Enter a string to move(2B-R)..: ";
    cin >> str;
    games[4]->playUser(str);
    games[4]->playAuto();
    games[4]->playAutoAll();*/
    
    

    return 0;
}

//srand ekle ve 2ye sayıları ekle