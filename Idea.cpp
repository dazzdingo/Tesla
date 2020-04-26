#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

const int maxx = 15;
bool GameOver;
const int width = maxx;
const int height = maxx;
int x, y, YugoX, YugoY, PintoX, PintoY, ElonX, ElonY, PrizeX, PrizeY;
char matrix[15][15];

void UpdateBoard(int x, int y) {
    system("cls");
    system("color f0");
    cout << "THE TESLA GAME" << endl;
    cout << "Main Objective: Find the Roadster, avoid Tesla! "
        "There is also a Yugo and a Pinto in the game, try not to find them!" << endl;
    cout << "Best of luck!" << endl << endl << endl;
    for (int xb = 1; xb <= 15; xb++) {
        for (int yb = 1; yb <= 15; yb++) {
            matrix[xb][yb] = '-';
        }
    }
    matrix[x][y] = 'X';     //print player location
    for (int xb = 1; xb < 16; xb++) {
        for (int yb = 1; yb < 16; yb++) {
            cout << setw(3) << matrix[xb][yb];
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "You are now at " << x << " - " << y << endl;
}

void UpdateBoardAfterSeeElon(int x, int y) {
    system("cls");
    system("color f3");
    for (int xb = 1; xb < 16; xb++) {
        for (int yb = 1; yb < 16; yb++) {
            matrix[xb][yb] = '-';
        }
    }
    matrix[x][y] = 'X';     //print player location
    matrix[ElonX][ElonY] = 'E';     //print Elon location
    for (int xb = 1; xb < 16; xb++) {
        for (int yb = 1; yb < 16; yb++) {
            cout << setw(3) << matrix[xb][yb];
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "You are now at " << x << " - " << y << endl;
}

void SetUp() {
    GameOver = false;
    x = rand() % width +1;
    y = rand() % height +1;
    YugoX = rand() % width +1;
    YugoY = rand() % height +1;
    PintoX = rand() % width +1;
    PintoY = rand() % height +1;
    ElonX = rand() % width +1;
    ElonY = rand() % height +1;
    PrizeX = rand() % width +1;
    PrizeY = rand() % height +1;
    UpdateBoard(x, y);
}


void Logic() {
    int countPinto = 0;
    int countYugo = 0;
    int counter = 0;
    int Elon, var,cont;
    int close = 0;
    char movement;
    while (!GameOver) {
        cout << "Press W to go up, S to down, A to go left and D to go right. To stop the game press R." << endl;
        cin >> movement;
        system("cls");
        if (movement == 'r')
            GameOver = true;
        if (movement == 'a') {
            y--;
            if (y < 1) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'd') {
            y++;
            if (y > 15) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'w') {
            x--;
            if (x < 1) {
                cout << "You are getting out of the map" << endl;
                x++;
            }
        }
        if (movement == 's') {
            x++;
            if (x > 15) {
                cout << "You are getting out of the map" << endl;
                x--;
            }
        }
        if (movement == 'R')
            GameOver = true;
        if (movement == 'A') {
            y--;
            if (y < 1) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'D') {
            y++;
            if (y > 15) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'W') {
            x--;
            if (x < 1) {
                x++;
            }
        }
        if (movement == 'S') {
            x++;
            if (x > 14) {
                cout << "You are getting out of the map" << endl;
                x--;
            }
        }

        UpdateBoard(x, y);

        if (x == YugoX && y == YugoY)
            countYugo++;
        if (x == PintoX && y == PintoY)
            countPinto++;

        if (abs(x - PrizeX) <= 3 && abs(y - PrizeY) <= 5)
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) <= 3 && abs(x - PrizeX) <= 5)
            cout << "You are getting warmer vertically" << endl;

        if (x == PrizeX && y == PrizeY) {
            system("cls");
            system("color f4");
            cout << endl << endl << endl << endl << endl;
            cout << "YOU FOUND THE ROADSTER." << endl;
            cout << "CONGRATULATION!!! YOU HAVE WON!!" << endl;
            cout << endl << endl;
            cout << "You encounter Yugo " << countYugo << " times.";
            cout << "You encounter Pinto " << countPinto << " times.";
            cout << endl << endl << endl << endl << endl;
            GameOver = true;
        }

        if (x == ElonX && y == ElonY) {
            system("cls");
            system("color f9");
            cout << "You have encountered Elon. Your only way out is to find the Roadster." << endl;
            cout << "Hope you do not encounter Yugo or Pinto." << endl;
            cout << "Find the Roadster! Press any NUMBER to continue:" << endl;
            cin >> cont;
            Elon = 5;
            while (ElonX == x)
                ElonX = rand() % width;
            while (ElonY == y)
                ElonY = rand() % height;
            UpdateBoardAfterSeeElon(x, y);
            break;
        }
    }

    while (!GameOver) {
        if (abs(ElonX - x) == 1 || abs(ElonY - y) == 1)
            close++;
        if (counter > Elon - 1) {
            var = rand() % 2;
            if (var == 0) {
                if (ElonX != x) {
                    ElonX++;
                    if (abs(ElonX - x) > abs(ElonX - 1 - x))
                        ElonX = ElonX - 2;
                }
                else {
                    ElonY++;
                    if (abs(ElonY - y) > abs(ElonY - 1 - y))
                        ElonY = ElonY - 2;
                }
            }
            if (var == 1) {
                if (ElonY != y) {
                    ElonY++;
                    if (abs(ElonY - y) > abs(ElonY - 1 - y))
                        ElonY = ElonY - 2;
                }
                else {
                    ElonX++;
                    if (abs(ElonX - x) > abs(ElonX - 1 - x))
                        ElonX = ElonX - 2;
                }
            }
        }

        cout << "Press W to go up, S to down, A to go left and D to go right. To stop the game press R." << endl;
        cin >> movement;
        system("cls");
        if (movement == 'r')
            GameOver = true;
        if (movement == 'a') {
            y--;
            if (y < 1) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'd') {
            y++;
            if (y > 15) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'w') {
            x--;
            if (x < 1) {
                x++;
            }
        }
        if (movement == 's') {
            x++;
            if (x > 15) {
                cout << "You are getting out of the map" << endl;
                x--;
            }
        }
        if (movement == 'R')
            GameOver = true;
        if (movement == 'A') {
            y--;
            if (y < 1) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'D') {
            y++;
            if (y > 15) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'W') {
            x--;
            if (x < 1) {
                x++;
            }
        }
        if (movement == 'S') {
            x++;
            if (x > 15) {
                cout << "You are getting out of the map" << endl;
                x--;
            }
        }
        if (close > 10) {
            ElonX = x;
            ElonY = y;
        }

        UpdateBoardAfterSeeElon(x, y);

        if (x == YugoX && y == YugoY)
            countYugo++;
        if (x == PintoX && y == PintoY)
            countPinto++;

        if (abs(x - PrizeX) <= 3)
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) <= 3)
            cout << "You are getting warmer vertically" << endl;
        if (x == PrizeX && y == PrizeY) {
            system("cls");
            system("color f4");
            cout << endl << endl;
            cout << "YOU FOUND THE ROADSTER." << endl;
            cout << "CONGRATULATION!!! YOU HAVE WON!!" << endl;
            cout << endl << endl;
            GameOver = true;
        }
        if (x == PrizeX && y == PrizeY) {
            system("cls");
            system("color f4");
            cout << endl << endl<< endl << endl << endl;
            cout << "YOU FOUND THE ROADSTER." << endl;
            cout << "CONGRATULATION!!! YOU HAVE WON!!" << endl;
            cout << endl << endl;
            cout << "You encounter Yugo " << countYugo << " times.";
            cout << "You encounter Pinto " << countPinto << " times.";
            cout << endl << endl << endl << endl << endl;
            GameOver = true;
        }

        if (x == YugoX && y == YugoY) {
            system("cls");
            system("color f9");
            cout << "YOU ENCOUNTER YUGO! YOU HAVE BECOME A STAR MAN! :(" << endl;
            cout << "BAD LUCK!!! YOU LOSE!! :P" << endl;
            cout << endl << endl;
            cout << "You encounter Yugo " << countYugo << " times.";
            cout << "You encounter Pinto " << countPinto << " times.";
            cout << endl << endl << endl << endl << endl;
            GameOver = true;
        }

        if (x == PintoX && y == PintoY) {
            system("cls");
            system("color f9");
            cout << "YOU ENCOUNTER PINTO! YOU HAVE BECOME A STAR MAN! :(" << endl;
            cout << "BAD LUCK!!! YOU LOSE!! :P" << endl;
            cout << endl << endl;
            cout << "You encounter Yugo " << countYugo << " times.";
            cout << "You encounter Pinto " << countPinto << " times.";
            cout << endl << endl << endl << endl << endl;
            GameOver = true;
        }
        counter++;
    }
}

int main() {
    srand(time(NULL));
    SetUp();
    Logic();
    return 0;
}

//Tesla Project of An Nguyen (M13399866) and Trien Dau (M13292604).
