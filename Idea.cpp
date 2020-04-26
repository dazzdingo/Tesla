#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;
const int maxx = 14;
bool GameOver;
const int width = maxx;
const int height = maxx;
int x, y, YugoX, YugoY, PintoX, PintoY, ElonX, ElonY, PrizeX, PrizeY;
char matrix[15][15];
char movement;
int cont;

void UpdateBoard(int x, int y) {
    system("cls");
    system("color f0");
    cout << "THE TESLA GAME" << endl;
    cout << "Main Objective: Find the Roadster, avoid Tesla! "
        "There is also a Yugo and a Pinto in the game, try not to find them!" << endl;
    cout << "Best of luck!" << endl << endl << endl;
    for (int xb = 0; xb < 15; xb++) {
        for (int yb = 0; yb < 15; yb++) {
            matrix[xb][yb] = '-';
        }
    }
    matrix[x][y] = 'X';     //print player location
    matrix[ElonX][ElonY] = 'E';
    for (int xb = 0; xb < 15; xb++) {
        for (int yb = 0; yb < 15; yb++) {
            cout << setw(3) << matrix[xb][yb];
        }
        cout << endl;
    }
    cout << endl << endl;
}

void UpdateBoardAfterSeeElon(int x, int y) {
    system("cls");
    system("color f3");
    for (int xb = 0; xb < 15; xb++) {
        for (int yb = 0; yb < 15; yb++) {
            matrix[xb][yb] = '-';
        }
    }
    matrix[x][y] = 'X';     //print player location
    matrix[ElonX][ElonY] = 'E';     //print Elon location
    for (int xb = 0; xb < 15; xb++) {
        for (int yb = 0; yb < 15; yb++) {
            cout << setw(3) << matrix[xb][yb];
        }
        cout << endl;
    }
    cout << endl << endl;
}

void SetUp() {
    GameOver = false;
    x = rand() % width;
    y = rand() % height;
    YugoX = rand() % width;
    YugoY = rand() % height;
    PintoX = rand() % width;
    PintoY = rand() % height;
    ElonX = rand() % width;
    ElonY = rand() % height;
    PrizeX = rand() % width;
    PrizeY = rand() % height;
    UpdateBoard(x, y);
    cout << "You are starting at " << x << " - " << y << " - ";
}


void Logic() {
    int counter = 0;
    int Elon, var;
    while (!GameOver) {
        cout << "Press W to go up, S to down, A to go left and D to go right. To stop the game press R." << endl;
        cin >> movement;
        system("cls");
        if (movement == 'r')
            GameOver = true;
        if (movement == 'a') {
            y--;
            if (y < 0) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'd') {
            y++;
            if (y > 14) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'w') {
            x--;
            if (x < 0) {
                cout << "You are getting out of the map" << endl;
                x++;
            }
        }
        if (movement == 's') {
            x++;
            if (x > 14) {
                cout << "You are getting out of the map" << endl;
                x--;
            }
        }
        if (movement == 'R')
            GameOver = true;
        if (movement == 'A') {
            y--;
            if (y < 0) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'D') {
            y++;
            if (y > 14) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'W') {
            x--;
            if (x < 0) {
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

        cout << "You are now at " << x << " - " << y << endl;
        UpdateBoard(x, y);

        if (abs(x - PrizeX) <= 3 && abs(y - PrizeY) <= 5)
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) <= 3 && abs(x - PrizeX) <= 5)
            cout << "You are getting warmer vertically" << endl;

        if (x == PrizeX && y == PrizeY) {
            system("cls");
            system("color f4");
            cout << "YOU FOUND THE ROADSTER." << endl;
            cout << "CONGRATULATION!!! YOU HAVE WON!!" << endl;
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
            if (y < 0) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'd') {
            y++;
            if (y > 14) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'w') {
            x--;
            if (x < 0) {
                x++;
            }
        }
        if (movement == 's') {
            x++;
            if (x > 14) {
                cout << "You are getting out of the map" << endl;
                x--;
            }
        }
        if (movement == 'R')
            GameOver = true;
        if (movement == 'A') {
            y--;
            if (y < 0) {
                cout << "You are getting out of the map" << endl;
                y++;
            }
        }
        if (movement == 'D') {
            y++;
            if (y > 14) {
                cout << "You are getting out of the map" << endl;
                y--;
            }
        }
        if (movement == 'W') {
            x--;
            if (x < 0) {
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
        cout << "You are now at " << x << " - " << y << endl;
        UpdateBoard(x, y);
        if (abs(x - PrizeX) <= 3)
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) <= 3)
            cout << "You are getting warmer vertically" << endl;
        if (x == PrizeX && y == PrizeY) {
            system("cls");
            system("color f4");
            cout << "YOU FOUND THE ROADSTER." << endl;
            cout << "CONGRATULATION!!! YOU HAVE WON!!" << endl;
            GameOver = true;
        }
        if (x == ElonX && y == ElonY) {
            system("cls");
            system("color f9");
            cout << "YOU ENCOUNTER ELON AGAIN! :(" << endl;
            cout << "BOOO!!! YOU LOSE!! :P" << endl;
            GameOver = true;
        }

        if (x == YugoX && y == YugoY) {
            system("cls");
            system("color f9");
            cout << "YOU ENCOUNTER YUGO! YOU HAVE BECOME A STAR MAN! :(" << endl;
            cout << "BAD LUCK!!! YOU LOSE!! :P" << endl;
            GameOver = true;
        }

        if (x == PintoX && y == PintoY) {
            system("cls");
            system("color f9");
            cout << "YOU ENCOUNTER PINTO! YOU HAVE BECOME A STAR MAN! :(" << endl;
            cout << "BAD LUCK!!! YOU LOSE!! :P" << endl;
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
