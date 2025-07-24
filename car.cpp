#include <iostream>
#include <conio.h>      // For _kbhit() and _getch()
#include <windows.h>    // For Sleep() and system("cls")
#include <ctime>        // For random seed

using namespace std;

const int WIDTH = 12; // Decreased width
const int HEIGHT = 20;
const int MAX_LIFE = 3;
int carPos = WIDTH / 2;
int score = 0;
int carLife = MAX_LIFE;
bool gameOver = false;
char road[HEIGHT][WIDTH];

// Utility to set console color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Set console window size (Windows only)
void setWindowSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = {0, 0, (short)(width - 1), (short)(height - 1)};
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    COORD coord = {(short)width, (short)height};
    SetConsoleScreenBufferSize(hConsole, coord);
}

// Function to draw the road
void draw() {
    system("cls");
    // Display instructions at the top
    setColor(11);
    cout << "Controls: [A]/[Left Arrow] = Left, [D]/[Right Arrow] = Right, [P] = Pause, [Q] = Quit\n";
    setColor(7);
    // Print top border
    setColor(8); // Gray
    cout << "  "; // Thicker left border
    for (int j = 0; j < WIDTH * 3; j++) cout << "-";
    cout << "  \n"; // Thicker right border
    for (int i = 0; i < HEIGHT; i++) {
        setColor(8); cout << "||"; // Thicker left wall
        for (int j = 0; j < WIDTH; j++) {
            if (gameOver) {
                setColor(7); cout << road[i][j];
            } else if (i == HEIGHT - 1 && j == carPos) {
                setColor(10); cout << "^-^";
                j += 2;
            } else {
                if (road[i][j] == '|') {
                    setColor(12); cout << "[X]";
                } else {
                    setColor(7); cout << "   ";
                }
            }
        }
        setColor(8); cout << "||"; // Thicker right wall
        // Display car life on the right side
        if (i == 2) {
            setColor(7); cout << "   Car Life: ";
            setColor(14); for (int l = 0; l < carLife; l++) cout << "\x03 (-^-) "; // Yellow heart (ASCII 3)
            setColor(7);
        }
        cout << "\n";
    }
    // Print bottom border
    setColor(8); cout << "  ";
    for (int j = 0; j < WIDTH * 3; j++) cout << "-";
    cout << "  \n";
    setColor(7);
    int pad = (WIDTH * 3 + 4 - 18) / 2;
    for (int i = 0; i < pad; i++) cout << " ";
    cout << "Score: " << score << endl;
}

// Function to update the game logic
void logic() {
    // Move obstacles down
    for (int i = HEIGHT - 2; i >= 0; i--) {
        for (int j = 0; j < WIDTH; j++) {
            road[i + 1][j] = road[i][j];
        }
    }

    // Clear top row
    for (int j = 0; j < WIDTH; j++) {
        road[0][j] = ' ';
    }

    // Add new obstacle at random
    if (rand() % 5 == 0) {
        int obs = rand() % WIDTH;
        // Prevent obstacle from spawning on car position in top row
        if (obs != carPos) {
            road[0][obs] = '|';
        }
    }

    // Check collision
    if (road[HEIGHT - 1][carPos] == '|') {
        carLife--;
        if (carLife <= 0) {
            gameOver = true;
        }
        // Remove obstacle after collision
        road[HEIGHT - 1][carPos] = ' ';
        return;
    }
    // Only increment score if game is not over
    score++;
}

// Add pause and restart feature
void pauseGame() {
    setColor(11);
    cout << "\nGame Paused. Press 'R' to resume or 'Q' to quit...\n";
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'r' || ch == 'R') break;
            if (ch == 'q' || ch == 'Q') { gameOver = true; break; }
        }
        Sleep(100);
    }
    setColor(7);
}

// Function to stop the game
void stopGame() {
    gameOver = true;
}

// Function to get user input
void input() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
            case 'a':
            case 'A':
                if (carPos > 0) carPos--;
                break;
            case 'd':
            case 'D':
                if (carPos < WIDTH - 1) carPos++;
                break;
            case 'q':
            case 'Q':
                stopGame();
                break;
            case 'p':
            case 'P':
                pauseGame();
                break;
            case 75: // Left arrow key
                if (carPos > 0) carPos--;
                break;
            case 77: // Right arrow key
                if (carPos < WIDTH - 1) carPos++;
                break;
        }
    }
}

int main() {
    setWindowSize(WIDTH * 3 + 14, HEIGHT + 10); // Adjust window size for thicker walls
    srand(time(0));
    // Initialize road
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            road[i][j] = ' ';

    cout << "=== Console Car Race Game ===\n";
    cout << "Use 'A' and 'D' to move left/right. Press 'Q' to quit.\n";
    cout << "Press any key to start...\n";
    _getch();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(200);  // Increased value to make the car/game slower
    }

    cout << "\n💥 Game Over! Final Score: " << score << "\n";
    return 0;
}
