#include <ncurses.h>
#include <vector>

const int GRID_ROWS = 24;
const int GRID_COLS = 80;

using namespace std; 



// Function to initialize ncurses
void initializeNcurses() {
    initscr();  // Initialize the ncurses library
    noecho();  // Disable echoing of typed characters
    cbreak();	// Disable line buffering
    curs_set(0);  // Hide the cursor
    keypad(stdscr, TRUE); // Enable special keys
    mousemask(ALL_MOUSE_EVENTS, NULL); // Enable special keys 
    nodelay(stdscr, TRUE);  // Make getch() non-blocking
}

// Function to initialize the grid with dead cells
vector<vector<int>> initializeGrid() {
    return vector<vector<int>>(GRID_ROWS, std::vector<int>(GRID_COLS, 0));
}

// Function to display the grid
void displayGrid(const vector<vector<int>>& grid) {
    //clear();

    for (int i = 0; i < GRID_ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            // Display '*' for live cells, ' ' for dead cells
            mvaddch(i, j, grid[i][j] ? '*' : ' '); 
        }
    }

    refresh();  // Refresh the screen to display the updated grid
}

// Function to count live neighbors (optimized with boundary checks)
int countLiveNeighbors(const vector<vector<int>>& grid, int row, int col) {
    int liveNeighbors = 0;
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            if (i >= 0 && i < GRID_ROWS && j >= 0 && j < GRID_COLS &&
                !(i == row && j == col) && grid[i][j] == 1) {
                liveNeighbors++; // Count live neighbors, excluding the cell itself
            }
        }
    }
    return liveNeighbors;
}

// Function to update the grid to the next generation
void updateGrid(vector<vector<int>>& grid) {
    vector<vector<int>> newGrid = grid; // Create a copy of the current grid

    for (int i = 0; i < GRID_ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);

            // Apply Game of Life rules (concisely)
            if (grid[i][j] == 1) {
                // Live cell stays alive if it has 2 or 3 neighbors
                newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3); 
            } else {
                // Dead cell becomes alive if it has exactly 3 neighbors
                newGrid[i][j] = (liveNeighbors == 3);
            }
        }
    }

    grid = newGrid;  // Update the grid to the next generation
}

// Function to toggle the state of a cell
void toggleCellState(vector<vector<int>>& grid, int row, int col) {
    if (row >= 0 && row < GRID_ROWS && col >= 0 && col < GRID_COLS) {
       // Toggle the state of the cell (alive <-> dead)
        grid[row][col] = !grid[row][col];
    }
}
