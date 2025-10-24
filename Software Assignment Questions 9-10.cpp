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

void takeDamage(double &health);
void heal(double &health, string items[]);
void lifePowerUp(int &lives, string items[]);

int main() {

string name;
double health;
int score = 0;
int lives = 3;
string items[] = {"arrows", "sword", "potion", "power up"};

cout << "What is your player's name: ";
cin >> name;
cout << "What is your player's total health: ";
cin >> health;

cout << "Greetings, " << name << "! You have " << health << " health points." << endl << endl;

int option;

for (int i = 0; i < 5; i++) {

  cout << "\nChoose from one of the following options by entering the corresponding option number: take damage (1), heal (2), life power up (3).";
  cin >> option;

  if (option == 1) {

    takeDamage(health);
    cout << "You have taken 30 damage! You now have " << health << " health points remaining." << endl;
    score -= 10;
    if (health <= 0) {
        cout << name << " has run out of health and the game is over!" << endl;
        break;
      }
    
    }

  else if (option == 2) {
    
    heal(health, items);
    cout << "You have received 30 health. You now have " << health << " health points." << endl;
    score += 20;
    
    } 

  else if (option == 3) {

    lifePowerUp(lives, items);
    cout << "You have received 1 life. You now have " << lives << " lives." << endl;
    score += 40;
    
    }

  else {
    
    cout << "Invalid choice. Please select 1, 2, or 3." << endl;
    
    }

  cout << "You have " << 4 - i << " actions remaining." << endl;
  
  }

  if (health <= 0) {
    cout << "Unfortunately, " << name << " did not survive. Your final score was: " << score << endl;
  } 
  else {
    cout << "You have completed your journey, " << name << "! Your remaining health is " << health 
         << ", your final score is " << score << ", and you have " << lives << " lives left." << endl;
  } 

return 0;
}

void takeDamage(double &health) {
health -= 30;  
}

void heal(double &health, string items[]) {
for (int j = 0; j < 4; j++)
  if (items[j] == "potion") {
    health += 30;
    items[j] = "";
    return;
  }
}

void lifePowerUp(int &lives, string items[]) {
for (int k = 0; k < 4; k++)
  if (items[k] == "power up") {
    lives += 1;
    items[k] = "";
    return;
  }
}


