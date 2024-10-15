# CS2010Lab4 From Chad 
This is code for a game of craps and the game of life. 


###Files
Lab4Craps.cpp was made in Visual Studio Comm 22 holds the craps gane there are 4 functions in it (including the main) 

This is a simple implementation of Conway's Game of Life using the ncurses library in C++. GameOfLife.cpp & GameFunctions.cpp where made in OnlineGDB. GameOfFile.cpp hold the main for this game. 


### How to Compile and Run


For the Craps Game 
g++ -o craps Lab4Craps.cpp
followed by ./craps 


For the Game of Life. 
g++ -0 golf GameOfLife.cpp GameFunctions.cpp -lncurses 
followed by ./golf 


## How to Play Craps

Craps is a dice game where you bet on the outcome of a sequence of dice rolls. Here's a simplified breakdown of the rules:

**1. Come-out Roll:**

* You start by rolling two dice. This is called the "come-out roll."
* **Immediate Wins:**
   * If you roll a 7 or 11, you win!
* **Immediate Losses:**
   * If you roll a 2, 3, or 12, you lose. 
* **Establishing a Point:**
   * If you roll any other number (4, 5, 6, 8, 9, or 10), that number becomes your "point."

**2. Point Rolls (if necessary):**

* If you established a point in the come-out roll, you continue to roll the dice until you either:
   * **Win:** Roll your point number again.
   * **Lose:** Roll a 7 before rolling your point number.

**Betting:**

* Before the come-out roll, you place a bet.
* If you win, you typically win even money on your bet.
* If you lose, you lose your bet.

## How to play the Game of Life 

This is a simulation of Conway's Game of Life. Here's how you can interact with it:

**Setting the Initial State:**

* **Mouse Click:** When the simulation is paused, click on a cell to toggle its state between alive and dead. This allows you to create your own starting patterns.

**Running the Simulation:**

* **Spacebar:**  Press the spacebar to start or pause the simulation.
* **Any other key:** If the simulation is paused, pressing any other key will also start it.

**Controlling the Simulation:**

* **Speed:** The simulation runs at a fixed speed (1 update per second). 
* **Quit:** Press the 'q' key to quit the simulation. 

**Game of Life Rules:**

The simulation follows the standard rules of Conway's Game of Life:

* **Survival:** A living cell with 2 or 3 living neighbours survives to the next generation.
* **Death:** A living cell with fewer than 2 living neighbours dies (underpopulation).
   A living cell with more than 3 living neighbours dies (overpopulation).
* **Birth:** A dead cell with exactly 3 living neighbours becomes a living cell.


