//Final Project
//Tanner Goodman
//December 13, 2019
//This program plays a choice based adventure game.

#include<iostream>
#include<ctime>
using namespace std;



//introduces the setting
void intro();
//splits the story based on role
int characterRole();
int getRole();
bool runHero();
bool runThief();
bool runHitman();

int main() {
    //seedtime
    srand(time(0));
    bool characterDeath=true;
    int roleChoice;
    while(characterDeath)
    {
        intro();
        roleChoice=characterRole();
        if(roleChoice==1)
            characterDeath = runHero();
        else if (roleChoice==2)
            characterDeath = runThief();
        else if (roleChoice==3)
            characterDeath = runHitman();
        
        if(characterDeath)
        {
            cout << "You died. Enter to try again..." << endl;
            cin.clear();
            cin.get();
            cin.get();
        }
    }
    cout << "You won! Thanks for playing." << endl << endl;
    return 0;
};
//introduces the setting
void intro() {
    cout << endl << "Welcome to the Medieval choice adventure game." << endl;
    cout << "Each choice will effect the story and may change the ending." << endl;
    cout << "There is one secret ending." << endl;
    cout << "Our story starts in a Medieval marketplace. In a town where the King Dragon reins supreme over everyone." << endl;
    cout << "Press enter to continue." << endl;
    //pause program
    cin.get();
    cout << "You come across an old man, who asks you how do you see your future?" << endl;
}

//splits the story based on role
int characterRole() {
    string characterChoice;
    int choice;
    while(characterChoice!="hero" && characterChoice!="Hero" && characterChoice!= "Thief" && characterChoice!= "thief" && characterChoice!="hitman" && characterChoice!="Hitman"){

    cout << "You say, I want to become a (thief, hitman, hero): ";
    cin >> characterChoice;
    if(characterChoice== "hero" || characterChoice== "Hero")
        choice = 1;
    else if(characterChoice=="thief" || characterChoice=="Thief")
        choice = 2;
    else if(characterChoice== "hitman" || characterChoice== "Hitman")
        choice = 3;
    else
        cout << "The old man looks at you with a strange look and waits for your answer." << endl;
    }
    return choice;
}

bool runHero(){
    string heroChoice, secretEnding;
    int userRoll;
    int wizardRoll;
    int MAX_ROLL = 6;
    int MIN_ROLL = 1;

    cout << endl;
    cout << "You embark on your journey to become a hero." << endl;
    cout << "As you continue through the market." << endl;
    do{
    cout << "On your left see a poor, old man who can't afford any food." << endl;
    cout << "On your right you see some kids fighting." << endl;
    cout << "Which do you decide to help (left or right)? " << endl;
    cin  >> heroChoice;}
    while (heroChoice!= "left" && heroChoice!= "Left" && heroChoice!= "Right" && heroChoice!="right");
   
    if (heroChoice == "left" || heroChoice == "Left") {
        cout << "You go over to help the old man when you notice he is the local wizard." << endl;
        cout << "Even though you were going to help him, he takes no pity on you." << endl;
        cout << "He tells you to roll his dice for your wildest dreams to come true." << endl;
        do{ 
            cout << "Do you roll his dice (yes or no)?" << endl;
            cin >> secretEnding;
        }
        while (secretEnding!= "no" && secretEnding!= "No" && secretEnding!= "yes" && secretEnding!= "Yes");

        if (secretEnding == "no" || secretEnding == "No") {
            cout << "The wizard immediately turns you into a frog and you hop away." << endl;
            cout << "Thus bringing our story to its end, not every hero succeeds." << endl;
            return true; // you die, try again
        }

        else if (secretEnding == "yes" || secretEnding == "Yes") { 
            do{
                userRoll = (rand() % (MAX_ROLL - MIN_ROLL + 1)) + MIN_ROLL;
                wizardRoll = (rand() % (MAX_ROLL - MIN_ROLL + 1)) + MIN_ROLL;
            }while(userRoll==wizardRoll);

            cout << "The wizard hands you the die and you roll a " << userRoll << "." << endl;
            cout << "The wizard rolls his die and rolls a " << wizardRoll << "." << endl;
            if (userRoll < wizardRoll) {
                cout << "The wizard sees you rolled lower than him and he immediately disinagrates you without a second for you to react." << endl;
                return true; //you die, try again
            }
            else if (userRoll > wizardRoll) {
                cout << "The wizard makes your dream of being a hero true, with a twist." << endl;
                cout << "He changes you into a mighty dragon, strong enough to take out" << endl;
                cout << "the King Dragon causing choas across the city." << endl;
                return false; //you win
                }
            }
    } 
    
    else if (heroChoice == "right" || heroChoice == "Right") {
        cout << "You go to stop the kids from fighting." << endl;
        cout << "As you break up the four little boys from their fight," << endl;
        cout << "you notice they are not kids." << endl;
        cout << "They seem to be adult dwarfs, but as you come to that realization," << endl;
        cout << "one of them shanks you in the back." << endl;
        cout << "The dwarfs leave you to die." << endl;
        return true; // you die, try again
    } 
    
    else 
        cout << "You ponder about your choice." << endl;
}


bool runThief(){
    string thiefChoice;
    string swordThief;

    cout << "You embark on your journey to become a thief." << endl;
    cout << "As you continue through the market." << endl;
    cout << "You decide that you can't be a thief without stealing from someone who owns powerful items." << endl;
    do{
        cout << "Your decision is to steal from the (wizard or king): ";
        cin >> thiefChoice;
    }
    while (thiefChoice != "King" && thiefChoice != "king" && thiefChoice != "wizard" && thiefChoice != "Wizard");
    if (thiefChoice == "king" || thiefChoice == "King") {
        cout << "You head to the King's castle." << endl;
        cout << "When you reach the castle, you see a few guards protecting the outside." << endl;
        cout << "You manage to sneak past them without drawing any attention to yourself." << endl;
        cout << "You search the castle looking for any valuable items." << endl;
        cout << "In one room of the castle, you see a sword in the middle of the room with a banner over it." << endl; 
        cout << "The banner says Dragon Slayer's sword." << endl;
        cout << "You quickly take the sword and leave the castle through the same way you entered, all without being seen." << endl;
        cout << "Once gone, you look at the sword and decide to either sell it or use it on the King Dragon." << endl;
        do {
            cout << "Your decision is to (sell or use): ";
            cin >> swordThief;
        }
        while (swordThief != "sell" && swordThief != "Sell" && swordThief != "Use" && swordThief != "use");
        if (swordThief == "sell" || swordThief == "Sell") {
            cout << "You take the sword to a shady merchant in the market that offers you 250 gold pieces." << endl;
            cout << "You immediately take the offer and go home to relax and reflect on your new thief lifestyle." << endl;
            return false; // you didn't die
            } 
        else if (swordThief == "use" || swordThief == "Use") {
            cout << "You go to fight off the King Dragon." << endl;
            cout << "When you reach his cave, you take out the sword and it shoots a magical blast that cuts the dragon in half." << endl;
            cout << "Upon returning to the town, everyone thanks you for killing the dragon, but they also push you to the castle." << endl;
            cout << "They threaten the King to leave his position and declare you as their new King." << endl;
            return false; // you didn't die
            } 
        else 
            cout << "You ponder about your choice." << endl;
        } 
    else if (thiefChoice == "wizard" || thiefChoice == "Wizard") {
        cout << "You go to the wizard's hut." << endl;
        cout << "When you get to the hut, the wizard is nowhere's to be seen." << endl;
        cout << "You begin to look for any valuables." << endl;
        cout << "The wizard enters and before you have a chance to run, he shoots a magical beam at you." << endl;
        cout << "The beam vaporizes you where you stand." << endl;
        return true; // you died, try again
        } 
    else 
        cout << "You ponder about your choice." << endl;
}

bool runHitman() {
    string hitmanChoice;
    string swordHitman;

    cout << "You embark on your journey to become a hitman." << endl;
    cout << "As you continue through the market." << endl;
    cout << "You run into an angry looking man who offers you 250 gold pieces if you kill the King's daughter." << endl;
    cout << "You accept his offer and head to the King's castle." << endl;
    cout << "When you reach the castle, you see a few guards protecting the outside." << endl;
    cout << "You manage to sneak passed them without drawing any attention to yourself." << endl;
    cout << "You search the castle looking for the King's daughter." << endl;
    cout << "One door has the daughter's name on it, which you open and sneak into." << endl;
    cout << "She is in the room, you pull out a small dagger." << endl;
    cout << "She says, you can kill me but I will scream or I can give you the King's mighty sword." << endl;
    do {
    cout << "You think on the options and decide to (kill or sword): ";
    cin >> hitmanChoice;
    } while (hitmanChoice != "Sword" && hitmanChoice != "sword" && hitmanChoice != "kill" && hitmanChoice != "Kill");
    
    if (hitmanChoice == "sword" || hitmanChoice == "Sword") {
        cout << "She gives you the sword and you leave without any conflicts." << endl;
        cout << "With such a powerful weapon in your possession you could kill anyone and become the best hitman or use it on the King Dragon." << endl;
        do {
        cout << "Your choice is to (use or kill): ";
        cin >> swordHitman;
        } while (swordHitman != "Kill" && swordHitman != "kill" && swordHitman != "use" && swordHitman != "Use");
       
        if (swordHitman == "Use" || swordHitman == "use") {
            cout << "You return to your home with everyone seeming scared of you for you are now known as the man who can kill anyone." << endl;
            return false; //you didn't die
            }
        else if (swordHitman == "Kill" || swordHitman == "kill") {
            cout << "You go to fight off the King Dragon." << endl;
            cout << "When you reach his cave, you take out the sword and it shoots a magical blast that cuts the dragon in half." << endl;
            cout << "Upon returning to the town, everyone thanks you for killing the dragon, but they also push you to the castle." << endl;
            cout << "They threaten the King to leave his position and declare you as their new King." << endl;
            return false; //you didn't die
            } 
        else 
            cout << "You ponder about your choice." << endl;
        } 
    else if (hitmanChoice == "Kill" || hitmanChoice == "kill") {
        cout << "You go to stike the young lady, but before you kill her, she lets out a loud shriek." << endl;
        cout << "The King and his guards bust down the door and strike you with multiple swords, killing you almost immediately." << endl;    
        return true; //you died, try again
        } 
    else 
        cout << "You ponder about your choice." << endl;
    }
