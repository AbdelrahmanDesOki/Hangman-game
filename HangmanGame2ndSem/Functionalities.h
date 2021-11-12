#ifndef Functionalities_h
#define Functionalities_h
#include <iostream>
#include "stdio.h"
#include<vector>
using namespace std;

//here I am using the base and derived class for my game

class Game {
    //all of this attributes are protected because I inherit the methods
    // which use them in the derived class
protected:
    vector <string> lines;
    vector<int> score;
    int trials=0, mistakes=0, user_length, level, random, cnt=0, size=0;
    char* wordHandling,* dash,* check;
    char user_letters;
    string name ;
    
public:
    void setvalue(string x) {name= x;}
    string getting (){return name;}
    //here I require two parameters from the user always
    //as it is the main rule of the function
    int  user_input(int start, int end);
    void data();
    void game_Instruction_storing_data();
    void draw_mistakes();
    void printwords();
    void handling_file();
    void hidden_words();
    //here I apply the polymorphism technique
    virtual void gen_random();
};

//Derived class
class Intro :public Game{
//I kept it private as it isn't inherited anymore
private:
    int again;

public:
    void gen_random();
    bool end();

};

#endif /* Functionalities_h */
