#include <ncurses.h>
#include <vector>


using namespace std;


// Prototype Declaration for functions in GameFunctions.cpp 

void initializeNcurses();
vector<vector<int>> initializeGrid();
void displayGrid(const vector<vector<int>>& grid);
int countLiveNeighbors(const vector<vector<int>>& grid, int row, int col);
void updateGrid(vector<vector<int>>& grid);
void toggleCellState(vector<vector<int>>& grid, int row, int col);



int main() {
    initializeNcurses();// Initialize the ncurses library for terminal manipulation
    
    
    vector<vector<int>> grid = initializeGrid(); // Initialize the ncurses library for terminal manipulation

    int ch;
    bool running = false;

    while (true) { // Main loop to handle user input and grid updates
        displayGrid(grid);  // Display the current state of the grid on the terminal
        ch = getch();  // Wait for user input

        
        // Handle mouse events
        if (ch == KEY_MOUSE) {
            MEVENT event;
            
            // Check if a mouse event occurred and if it was a left-click
            if (getmouse(&event) == OK && (event.bstate & BUTTON1_CLICKED)) { 
                // Toggle the state of the cell at the clicked position
                toggleCellState(grid, event.y, event.x);  
            }
            
         // Handle 'q' key to quit the program    
        } else if (ch == 'q') {
            break;
        
        // Handle spacebar to start/stop the simulation
        } else if (ch == ' ') {
            running = !running;
        
        // If any other key is pressed and the simulation is not running, start it
        } else if (!running && ch != ERR) {
            running = true;
        }

	// If the simulation is running, update the grid and introduce a delay
        if (running) {
            updateGrid(grid);
            napms(1000); // Introduce a delay of 100 milliseconds
        }
    }

     // Clean up and close the ncurses window
    endwin();
    return 0;
}
