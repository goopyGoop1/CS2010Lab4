#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <format>

using namespace std;

int credits = 100; // Global variable to store the player's credits
int wager;		  // Global variable to store the player's wager


int die() { // Function to simulate rolling a single die
	
	return (rand() % 6 + 1); // Generate a random number between 1 and 6 (inclusive)
}

string pointsRoll(int points) { // Function to handle the "points" roll scenario in craps

	int roll1 = die();
	int roll2 = die();
	int total = roll1 + roll2;

	cout << format("Player rolled {} + {} = {} \n", roll1, roll2, total); // Display the roll result

	if (total == points) { // Check if the player wins by matching the "points"
		credits += wager;
		return "Player Wins!!";
	}
	else if (total == 7) {  // Check if the player loses by rolling a 7
		credits -= wager;
		return "Player Loses.";
	}
	else { 
	return	pointsRoll(points);  // If neither win nor lose, roll again (recursion)
	}


}

void playGame() {  // Function to handle a single round of the craps game
	bool bet = false; 
	cout << "You have " << credits << " credits. ";
	
	do {   // Loop to get a valid wager from the player have to run at least once
		cout << "What would you like to wager? ";
		cin >> wager;
		cout << "\n\n";
		if (wager > credits) {
			cout << "Your wager exceeds credits. Try again\n";
			bet = false;
		}
		else bet = true; 
		
	} while (!bet);
	
		
	
	int roll1 = die();  // Roll the two dice for the "come-out" roll
	int roll2 = die();
	int total = roll1 + roll2; 

	cout << format("Player rolled {} + {} + = {} \n", roll1, roll2, total);  // Display the initial roll result

	string result;
	switch (total) {  // Determine the outcome of the "come-out" roll using a switch statement
		case 2:
		case 3:
		case 12:  // Immediate loss if 2, 3, or 12 is rolled
			cout << "Player Loses";
			cout << "You lost " << wager << " credits!!";
			credits -= wager;
			cout << "Your new balance is " << credits << " credits.\n\n";
			break;
		case 7:
		case 11:  // Immediate win if 7 or 11 is rolled
			cout << "Player Wins!!!\n\n";
			cout << "You won " << wager << " credits!!";
			credits += wager; 
			cout << "Your new balance is " << credits << " credits.\n\n"; 
			break; 
		case 4:
		case 5:
		case 6:
		case 8:
		case 9:
		case 10: // "Points" are established if 4, 5, 6, 8, 9, or 10 is rolled
			cout << "Points is " << total << "\n";
			result = pointsRoll(total);  // Call the pointsRoll function to continue rolling
			cout << format("{}  Your new blance is {} credits\n\n",result, credits);
			break;
		default:
			break;
	}

}

int main() {
	srand(time(NULL));   // initialize random seed:
	char ans;
	bool done = false;
	while (!done) {
		playGame();
		if (credits == 0) {   // Check if the player has run out of credits
			cout << "You are out of credits - GAME OVER!!!\n";
			exit(0); 
		}

		cout << "Play again (y/n) ? ";
		cin >> ans;
		while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {  // Input validation loop to ensure the player enters 'y', 'Y', 'n', or 'N'
			cout << "Invalid input. Please enter 'y' or 'n': ";
			cin >> ans;
		}
		if (ans == 'n' || ans == 'N') {
			done = true;
			cout << "\n";
		}
		else done = false;

		// Clear the input buffer to prevent issues with future input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return 0;
}

