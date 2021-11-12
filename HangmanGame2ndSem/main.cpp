#include "Functionalities.h"
#include <iostream>
using namespace std;

int main() {
    //define object for Game, which I will use for accessing all methods
    Game trial;
    
    trial.data();
    trial.gen_random();
    trial.game_Instruction_storing_data();
    trial.handling_file();
    trial.printwords();
    trial.hidden_words();
    
    //here  I made another one in case user want to play again
    //first I check then complete with this one
    Intro user;
    
    while (user.end()){
        user.gen_random();
        user.game_Instruction_storing_data();
        user.handling_file();
        user.printwords();
        user.hidden_words();
    
    }
    return 0;
}
