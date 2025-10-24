// 9.	Design a game program in C++ that contains the following:

// •	Declare variables for the following: 
// o	player name (string)
// o	player’s health (double)
// o	player’s score (int)
// o	the number of lives the player has (int)
// o	the player’s items (string array).
// •	Ask for the player’s name and health.
// •	Display a welcome message with the player’s name and health.
// •	Ask the player to choose one of the following actions: take damage, heal, or life power up. Clearly indicate how many actions they have left.
// •	Functions for each of the actions and use if/else conditions to execute the functions according to the user’s response.
// o	Take damage: Decreases player health by 30.
// o	Heal: Increases player health by 30 if the player’s items contain a potion (string).
// o	Life power up: Increases life by one if the player’s items contain a power up (string).
// •	While or for loop to allow the user to execute 5 actions.
// •	After all actions, display a goodbye message with the player’s health, score, and number of lives left.


#include <iostream>
using namespace std;

void takeDamage(health)

int main() {

string name;
double health;
int score;
int lives;
string items[];

cout << "What is your player's name: ";
cin >> name;
cout << "What is your player's total health: ";
cin >> health;

cout << "Greetings, " << name << "! You have " << health << " health points." << endl << endl;

string option;

for (int i = 0; i < 5; i++) {

cout << "Choose from one of the following options by entering the option name: take damage, heal, life power up.";
cin >> option;

if (option == "take damage") 
  
}


return 0;
}
