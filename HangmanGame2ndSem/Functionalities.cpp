#include "Functionalities.h"
#include <fstream>
#include <ctime> //for time, srand
#include <iostream>
#include<vector>

using namespace std;


void Game::data(){
    //asking the user about his name to call him/her with it during the game.
    cout<<"please enter your name: ";
    string h;
    cin>>h;
    setvalue(h);
    cout<<"\n\t\t\tWELCOME "<<getting()<<" TO THE\n\n";
    
}



//this function is or printing the logo of the game and instructions
void Game::game_Instruction_storing_data(){
    cout<<"\t\t| *   *    *    *    *   ****    *     *    *    *    * |\n";
    cout<<"\t\t| *   *  *   *  * *  *  *        * * * *  *   *  * *  * |\n";
    cout<<"\t\t| *****  *****  *  * *  * ** *   *  *  *  *****  *  * * |\n";
    cout<<"\t\t| *   *  *   *  *   **  *    *   *     *  *   *  *   ** |\n";
    cout<<"\t\t| *   *  *   *  *    *   ****    *     *  *   *  *    * |\n";
    cout<<"\n\t\t\t\t\t\t\tGAME \n";
    cout<<"made by: DESOKII\n";
    
    cout<<("\n\n\t You have to guess the letters of the given unknown word,"
           "just letter by letter\n\n"
           "\n\t Hint:  The word may be noun-verb-adjective-pronoun. \n\n"
           "\n\t Every correct letter you guess = 1 point\n\n");
    cout <<endl<<"\t\t\t\t LET'S START"<<endl;
    cout<<("\n Please enter the length of the word you want between 1-14 \n");
    
    //here I am calling user_input function to check the validity of the user input
    user_length=user_input(1, 14);
    
    //asking the user to choose the level of dificulty he/she wants
    cout<<"\t Please enter the level of difficulty you want, between 0 and 2 \n"
             "\t 0= Easy=>> you have 9 mistakes only then you will lose.\n"
             "\t 1= Medium=>> you have 6 mistakes only then you will lose.\n"
             "\t 2= Hard=>> you have 4 mistakes only then you will lose.\n";
    //calling it again
    level=user_input(0, 2);
 
    //in this switch case I assign the value of trials depending on user choice
    switch (level)
    {
    case 0:
        trials=9;
        break;
    case 1:
        trials=6;
        break;
    case 2:
        trials=4;
        break;
    }
    
}

//the main rule of this function is to check the validity of the user input
//in it I am applying the exception ahndling technique
int Game:: user_input(int start, int end){
    string length;
    int n=0;
    while(1){
        cin>>length;
        try {
            for(int i=0;i<length.size();i++){
                //checking if the letter is not digit = character
               if( !isdigit(length[i])  )
                  throw "\n \t \t \t \t Invalid Input";
            }
            //stoi is a built in function used to transfer between string to int
            //to complete my check on it as a normal integer
            n=stoi(length);
            if(n>end || n<start)
                throw "\n \t \t \t \t Invalid number \n";
             else{
                 break;
                }
        } catch (const char *s) {
            cout<<s<<endl;
            //letting the user know the borders of input I require from him
            printf("\t >-> Please enter a valid length between (%d-%d)  \n",start,end);
        }
    }
    return n;
}


//this is used to generate a random number
//generating the seed of it depending on the time on laptop
//and it's lmits is 3000 as the size of the file which contains the words is 3001
 void Game::gen_random(){
    srand((unsigned) time(0));
    random=rand()%3000;
}



void Game::handling_file(){
    string line;
    //file handling and open it to start reading the words from it.
     ifstream fin;
     fin.open("words.txt");
    
   //know the size of the file and fill into the string vector
     while(getline(fin,line)){
         size++;
         for(int i=0;i<=line.size();i++) {
               if(line[i]>=65 && line[i]<=92)
                   line[i]=line[i]+32;
            }
         //storing the words in the file in the vector named lines
         lines.push_back(line);
     }
    // Close the file
        fin.close();
}

void Game::printwords(){
    
//looping to find the word randomly depending on the length and random number.
    //to avoid repetitive words.
    for(int i=random;i<=size;i++){
        if(random==size){
            i=0;
        }
        if(lines[i].length()-1==user_length){
            //this line was just for testing
//            cout<<lines[i]<<endl;
            //allocate memory for the size for chosen word
            wordHandling = new char [lines[i].size()+1];
            //then copy it for other usage in the game
            copy(lines[i].begin(), lines[i].end(), wordHandling);
            break;
        }
    }
    //we clear the vector, because if user asked to play again
    //to be able to fill it again
    lines.clear();
    size=0;
}



//in this function the main algorithm for the game is
void Game::hidden_words(){
    int h=0,j=0,p=0,q=0;
    //define an array of dashes to display in the screen for the user
    dash=new char [user_length+1];
    //this array we use it to check if user entered this letter before or not
    check=new char [mistakes+user_length];
    for ( h=0; h<user_length; h++)
    {
        dash[h]='-';
    }
    cout<<"\t\t\t\n";
    for ( int k=0; k<user_length; k++)
    {
        cout<< "{" << dash[k] << "}";
    }
    cout<<endl;
        
    do{
        q=cnt;
        cout<<"\t\t\n please enter a letter between a-z , A-Z \n";
        //in this loop we check if the input is a valid character or not
        while(1){
            cin>>user_letters;
            if(isalpha(user_letters)){
                break;
            }
            else{
                cout<<"\t\t\n please enter a valid character \n";
            }
        
        }
        //we lowercase the user input if user entered an uppercase letter
        //as all words in the file are lowercased
        user_letters=tolower(user_letters);
     
        //loop to check if the user entered this letter before or not
        for(int i=0; i<user_length; i++)
    {
        if(check[i] == user_letters)
        {
            j=1;
        }
    }
        //letting user knew and asking for another input
    if(j==1)
    {
       cout<<"\n You entered this letter before, please eneter another letter\n\n";
        j=0;
        continue;
    }
        //assigning the input to check array to know fi its entered before or not
        check[p]=user_letters;
        p++;
        
         //loop to check if the input existing in the word or not
        for(int u=0; u<user_length; u++)
        {
            if(user_letters == wordHandling[u])
            {
                //if it's existed then assign it instead of the dash
                dash[u]=user_letters;
                cnt++;
            }
        }
     
    cout<<"\t\t\t\n";
    for ( h=0; h<user_length; h++)
    {
        //print the right guessed letters after user entered them
        cout<< "{" << dash[h] << "}";
    }
    cout<<endl;

        
        
        //case of winning, when the counter for correct letters = the length of the word
        if(cnt ==user_length)
        {
            cout<<"\n\t\t\tCongratualations you #WON !! \n";
            cout<<"your score is: "<<cnt<<endl;
            score.push_back(cnt);
            break;
        }
        //this case to know whether we ned to ask the user again or not
        if(cnt>q)
        {
            continue;
        }
        //here handling the mistakes
        else
        {
            mistakes++;
            cout<<"WRONG TRIAL!"<<endl;
            //calling the function to draw the simulation for the real game
            Game::draw_mistakes();
            cout<<"\t Number of your wrong trials is: "<<mistakes<<endl;
            
            //case of losing the game when the mistakes = all the trials
            if(mistakes==trials)
            {
                cout<<endl;
                cout <<"Unfortunately, you lost all of your: "<<mistakes<<" Trials\n\n";
                cout<<" your score is: "<<cnt<<endl;
                score.push_back(cnt);
                //here, I let the user know the right answer
                cout<<" The word was: "<<wordHandling<<endl;
            }
        }

        
    }while(mistakes!=trials );
    
    int max = score[0];

        // Traverse vector elements
    for (int i = 1; i < score.size(); i++){
            if (score[i] > max)
                max = score[i];
         }
        ofstream file;
        file.open ("score.txt");
        file << max;
        file.close();
   
   
    
    
    //we free them up as the user may choose to play the game again..
    delete [] wordHandling;
    delete [] dash;
    delete [] check;
    //assign those to 0 as user may choose to play again
    
    mistakes=0;
    trials=0;
    cnt =0;
}
