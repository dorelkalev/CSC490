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

    cout << "\nGreetings, " << name << "! You have " << health << " health points." << endl;

    int option;

    for (int i = 0; i < 5; i++) {

        cout << "\nChoose from one of the following options by entering the corresponding option number: \n"
             << "1. take damage\n 2. heal\n 3. life power up" << endl;
        cin >> option;

        if (option == 1) {

            takeDamage(health);
            cout << "You have taken 30 damage! You now have " << health << " health points remaining." << endl << endl;
            score -= 10;

            if (health <= 0) {
                cout << name << " has run out of health and the game is over!" << endl;
                break;
            }
        }

        else if (option == 2) {

            heal(health, items);
            cout << "You have received 30 health. You now have " << health << " health points." << endl << endl;
            score += 20;
        }

        else if (option == 3) {

            lifePowerUp(lives, items);
            cout << "You have received 1 life. You now have " << lives << " lives." << endl << endl;
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
        cout << "\nYou have completed your journey, " << name << "! Your remaining health is " << health
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










// 10.	Design a school program in C++ that contains the following:

// •	Declare variables for the following:
// o	Student name (string)
// o	Current GPA (double)
// o	Total credits earned (int)
// o	Number of absences (int)
// o	Supplies owned (string array)
// •	Ask the user for their name and current GPA.
// •	Display a welcome message with their name and GPA.
// •	Ask the user to choose one of the following actions (with functions defined for them) and use if/else conditions to execute the functions according to the user’s response:
// o	Complete assignment: Increases GPA by 0.1 (max 4.0).
// o	Skip class: Increases absences by 1.
// o	Study session: Only works if the student has "notebook" in supplies. Increases GPA by 0.05.
// o	Take math exam: Takes in grade parameter and only works if "calculator" is in supplies. If grade ≥ 65, print "You passed!", otherwise "You failed!"
// •	Allow the student to perform 5 actions using a loop.
// •	After all actions, display the final GPA, absences, and credits earned.

#include <iostream>
using namespace std;

void completeAssignment(double &gpa);
void skipClass(int &absences);
void studySession(double &gpa, string supplies[]);
void takeMathExam(double &gpa, string supplies[]);

int main() {
  
    string name;
    double gpa;
    int totalCredits = 30; 
    int absences = 0;
    string supplies[] = {"notebook", "calculator", "pen", "textbook"};

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your current GPA: ";
    cin >> gpa;

    cout << "\nWelcome, " << name << "! Your current GPA is " << gpa << "." << endl;

    int option;

    // 5 actions loop
    for (int i = 0; i < 5; i++) {
      
        cout << "\nChoose an action by entering the corresponding number:\n";
        cout << "1. Complete assignment\n";
        cout << "2. Skip class\n";
        cout << "3. Study session\n";
        cout << "4. Take math exam\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
          
            completeAssignment(gpa);
            totalCredits += 1;
          
        }
        else if (option == 2) {
          
            skipClass(absences);
          
        }
          
        else if (option == 3) {
          
            studySession(gpa, supplies);
          
        }
          
        else if (option == 4) {
          
            takeMathExam(gpa, supplies);
          
        }
        else {
          
            cout << "Invalid choice. Please select 1–4." << endl;
          
        }

        cout << "You have " << 4 - i << " actions remaining." << endl;
    }

    cout << "\n--- Final Report ---\n";
    cout << "Student: " << name << endl;
    cout << "Final GPA: " << gpa << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Absences: " << absences << endl;

    cout << "\nGreat job, " << name << "! Keep up the good work!" << endl;

    return 0;
}

void completeAssignment(double &gpa) {
    gpa += 0.1;
    if (gpa > 4.0)
        gpa = 4.0;
    cout << "You completed an assignment! GPA increased by 0.1." << endl;
}

void skipClass(int &absences) {
    absences += 1;
    cout << "You skipped class. Absences increased by 1." << endl;
}

void studySession(double &gpa, string supplies[]) {
    for (int i = 0; i < 4; i++) {
        if (supplies[i] == "notebook") {
            gpa += 0.05;
            if (gpa > 4.0)
                gpa = 4.0;
            cout << "You studied using your notebook! GPA increased by 0.05." << endl;
            return;
        }
    }
    cout << "You don't have a notebook, so studying didn’t help." << endl;
}

void takeMathExam(double &gpa, string supplies[]) {
    for (int i = 0; i < 4; i++) {
        if (supplies[i] == "calculator") {
            int grade;
            cout << "Enter your math exam grade (0–100): ";
            cin >> grade;
            if (grade >= 65)
                cout << "You passed the exam!" << endl;
            else
                cout << "You failed the exam!" << endl;
            return;
        }
    }
    cout << "You don't have a calculator, so you couldn’t take the exam." << endl;
}

