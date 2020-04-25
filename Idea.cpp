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

void UpdateBoard(int x, int y) {
    system("cls");
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
}

void UpdateBoardAfterSeeElon(int x, int y) {
    system("cls");
    for (int xb = 0; xb < 15; xb++) {
        for (int yb = 0; yb < 15; yb++) {
            matrix[xb][yb] = '-';
        }
    }
    matrix[x][y] = 'X';     //print player location
    matrix[ElonX][ElonY] = 'E';     //print Elon location
    matrix[YugoX][YugoY] = 'Y';     //print Yugo location
    matrix[PintoX][PintoY] = 'P';     //print Pinto location
    for (int xb = 0; xb < 15; xb++) {
        for (int yb = 0; yb < 15; yb++) {
            cout << setw(3) << matrix[xb][yb];
        }
        cout << endl;
    }
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
    cout << "You are starting at " << x << " - " << y << " - " ;
}


void Logic() {
    int counter = 0;
    int Elon, var;
    while (!GameOver) {
        cout << "Press w to go up, s to down, a to go left and d to go right. To stop the game press r" << endl;
        cin >> movement;
        system("cls");
        if (movement == 'r')
            GameOver = true;
        if (movement == 'a') {
            y--;
            if (y < 0) {
                cout << "you are getting out of the map" << endl;
                y++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'd') {
            y++;
            if (y > 14) {
                cout << "you are getting out of the map" << endl;
                y--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'w') {
            x--;
            if (x < 0) {
                cout << "you are getting out of the map" << endl;
                x++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 's') {
            x++;
            if (x > 14) {
                cout << "you are getting out of the map" << endl;
                x--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        UpdateBoard(x, y);
        if (abs(x - PrizeX) <= 3)
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) <= 3)
            cout << "You are getting warmer vertically" << endl;
        if (x == PrizeX && y == PrizeY) {
            system("cls");
            cout << "You win" << endl;
            GameOver = true;
        }
        if (x == ElonX && y == ElonY) {
            system("cls");
            cout << "You have encountered Elon. Hope that you do not see Yugo and Python and hime one more time." << endl;
            cout << "They will wait you 5 turns to catch you and Elon give you a headstart." << endl;
            cout << "Determine how much turns that Elon will give you." << endl;
            cin >> Elon;
            while(ElonX == x)
                ElonX = rand() % width;
            while(ElonY == y)
                ElonY = rand() % height;
            UpdateBoardAfterSeeElon(x, y);
            break;
        }
    }

    while (!GameOver) {
        if (counter > Elon-1) {
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
        if (counter > 5) {
            if (var == 1) {
                if (YugoX != x) {
                    YugoX++;
                    if (abs(YugoX - x) > abs(YugoX - 1 - x))
                        YugoX = YugoX - 2;
                }
                else {
                    YugoY++;
                    if (abs(YugoY - y) > abs(YugoY - 1 - y))
                        YugoY = YugoY - 2;
                }
            }
            if (var == 0) {
                if (YugoY != y) {
                    YugoY++;
                    if (abs(YugoY - y) > abs(YugoY - 1 - y))
                        YugoY = YugoY - 2;
                }
                else {
                    YugoX++;
                    if (abs(YugoX - x) > abs(YugoX - 1 - x))
                        YugoX = YugoX - 2;
                }
            }
        }
        if (counter > 5) {
            if (var == 0) {
                if (PintoX != x) {
                    PintoX++;
                    if (abs(PintoX - x) > abs(PintoX - 1 - x))
                        PintoX = PintoX - 2;
                }
                else {
                    PintoY++;
                    if (abs(PintoY - y) > abs(PintoY - 1 - y))
                        PintoY = PintoY - 2;
                }
            }
            if (var == 1) {
                if (PintoY != y) {
                    PintoY++;
                    if (abs(PintoY - y) > abs(PintoY - 1 - y))
                        PintoY = PintoY - 2;
                }
                else {
                    PintoX++;
                    if (abs(PintoX - x) > abs(PintoX - 1 - x))
                        PintoX = PintoX - 2;
                }
            }
        }

        cout << "Press w to go up, s to down, a to go left and d to go right. To stop the game press r." << endl;
        cin >> movement;
        if (movement == 'r')
            GameOver = true;
        if (movement == 'a') {
            y--;
            if (y < 0) {
                cout << "you are getting out of the map." << endl;
                y++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'd') {
            y++;
            if (y > 14) {
                cout << "you are getting out of the map." << endl;
                y--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'w') {
            x--;
            if (x < 0) {
                cout << "you are getting out of the map." << endl;
                x++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 's') {
            x++;
            if (x > 14) {
                cout << "you are getting out of the map." << endl;
                x--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        UpdateBoardAfterSeeElon(x, y);
        if (abs(x - PrizeX) <= 3)
            cout << "You are getting warmer horizontally." << endl;
        if (abs(y - PrizeY) <= 3)
            cout << "You are getting warmer vertically." << endl;
        if (x == PrizeX && y == PrizeY) {
            system("cls");
            cout << "You win";
            GameOver = true;
        }
        if ((x == ElonX && y == ElonY) || (x == YugoX && y == YugoY) || (x == PintoX && y == PintoY)) {
            cout << "You lose" << endl;
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

//Tesla Project of An and Trien

