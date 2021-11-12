#include "Functionalities.h"
#include <iostream>
using namespace std;


//this function used to draw the simulation of the game
//depending on the user choice of level of difficulty
void Game::draw_mistakes(){
    
    //based on easy choice
    if (trials==9){
    switch(mistakes)
    {
    case 1:
        cout << "\n\n";
        cout<<"  |\n";
        cout<<"__|____\n\n";
        break;
    case 2:
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"__|____\n\n";
        break;
    case 3:
        cout<<"_______\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"__|____\n\n";
        break;
    case 4:
        cout<<" _______\n";
        cout<<"  |/   | \n";
        cout<<"  |    O \n";
        cout<<"  |     \n";
        cout<<"  |\n";
        cout<<"__|____\n\n";
        break;
    case 5:
        cout<<" _______\n";
        cout<<"  |/   | \n";
        cout<<"  |    O \n";
        cout<<"  |    |\n";
        cout<<"  |\n";
        cout<<"__|____\n\n";
        break;
    case 6 :
        cout<<" _______\n";
        cout<<"  |/   | \n";
        cout<<"  |    O \n";
        cout<<"  |   \\| \n";
        cout<<"  |\n";
        cout<<"__|____\n\n";
        break;
    case 7:
        cout<<" _______\n";
        cout<<"  |/   | \n";
        cout<<"  |    O \n";
        cout<<"  |   \\|/\n";
        cout<<"  |    | \n";
        cout<<"__|____\n\n";
        break;
    case 8:
        cout<<" _______\n";
        cout<<"  |/   | \n";
        cout<<"  |    O \n";
        cout<<"  |   \\|/\n";
        cout<<"  |    |\n";
        cout<<"  |    |\n";
        cout<<"  |   / \n";
        cout<<"__|____\n\n";
        break;
    case 9:
        cout<<" _______\n";
        cout<<"  |/   | \n";
        cout<<"  |    O \n";
        cout<<"  |   \\|/\n";
        cout<<"  |    |\n";
        cout<<"  |    |\n";
        cout<<"  |   / \\\n";
        cout<<"__|____\n\n";
        break;
    }
    
    }
    //based on medium choice
    else if (trials == 6){
        switch(mistakes)
        {
            case 1:
                cout << "\n\n";
                cout<<"  |\n";
                cout<<"__|____\n\n";
                break;
            case 2:
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"__|____\n\n";
                break;
            case 3:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |     \n";
                cout<<"  |\n";
                cout<<"__|____\n\n";
                break;
            case 4:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    | \n";
                cout<<"__|____\n\n";
                break;
            case 5:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    |\n";
                cout<<"  |    |\n";
                cout<<"  |   / \n";
                cout<<"__|____\n\n";
                break;
            case 6:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    |\n";
                cout<<"  |    |\n";
                cout<<"  |   / \\\n";
                cout<<"__|____\n\n";
                break;
                
    }
    }
    
    //based on hard choice
    else{
        switch(mistakes)
        {
            case 1:
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"__|____\n\n";
                break;
            case 2:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |     \n";
                cout<<"  |\n";
                cout<<"__|____\n\n";
                break;
            case 3:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    | \n";
                cout<<"__|____\n\n";
                break;
            case 4:
                cout<<" _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    |\n";
                cout<<"  |    |\n";
                cout<<"  |   / \\\n";
                cout<<"__|____\n\n";
                break;
                
        }
    }
}
