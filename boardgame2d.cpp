//This is the file: boardgame2d.cpp

//This is the implementation for the class BoardGame2D.

//the header file boardgame.h.





#include"boardgame2d.h"

namespace BoardGames{



//this writes the text slowly

void BoardGame2D::slowPrint( const char *s) 

{

   int i = 0;

   while(s[i]!=0)

   {

      cout << s[i++];

      cout.flush();

      this_thread::sleep_for (chrono::milliseconds(10));



   }

}



//This takes vector of boardgame2d * as a parameter and plays the board respectively

void BoardGame2D::playVector(vector<BoardGame2D*> games){



    int a;

    for (int i = 0; i < games.size(); i++)

    {

        //plays the games in order

        a=0;

        while (!games[i]->endGame() && a<100)

        {

            games[i]->print();

            games[i]->playAuto();

            this_thread::sleep_for (chrono::milliseconds(100));



            ++a;

        }

        if(a ==100){

            cout<<"This pc can't solve this game ..."; cout<<endl;

            this_thread::sleep_for (chrono::milliseconds(1000));



            

        }

        cout<<"Your Score: "<<games[i]->boardScore()<<endl;

    } 

}





//this play the board until the end

void BoardGame2D::playAutoAll(){



    int i=0;

    

    while (!endGame() && i<50)

    { 

        print();

        playAuto();

        this_thread::sleep_for (chrono::milliseconds(100));



       i++;

    }

    if (i==50)

        slowPrint("Unsolvable Board ..."); cout<<endl;

     

     cout<<"Your Score: "<<boardScore()<<endl;;

    

    

    

    

}



//this plays the board by asking to user until the end

void BoardGame2D::playUser(){



    string str;



    while (!endGame())

    {

        print();

        cout << "Enter a Coordinate and Direction: ";

        cin >> str;

        playUser(str);

    }

    cout << "This game has been solved! "<<endl;

    cout<<"Your Score: "<<boardScore();

}

}
