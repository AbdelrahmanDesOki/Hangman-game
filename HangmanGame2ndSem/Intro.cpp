#include "Functionalities.h"
#include <iostream>
#include<vector>

using namespace std;

//here I narrow the scope of choosing random number
//to let the probability of having same number to decrease
//2500 instead of 3000
void Intro::gen_random(){
    srand((unsigned) time(0));
    random=rand()%2500;
}

//this function used to make sure if user want to play again or end the game
bool Intro::end(){
    cout<<"\t\t\n\nWould you like to play again? \n";
    cout<<"\t\t\n Press 1 if you want and 0 if you want to exit the game: ";
    //check the validity of the input 
    again=user_input(0, 1);
    if(again!= 1){
        cout<<"\n\t\t\t\t Thanks for playing my Game :)\n";
        cnt =0 ;
        score.clear();
        return false;
    }
    
    cout<<"\n\t\t\t\t Thanks For Playing My Game, I hope you enjoyed it:))\n\n"<<endl;
    return true;
}


