#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
const int maxx = 15;
bool GameOver;
const int width = maxx;
const int height = maxx;
int x, y, YugoX, YugoY, PintoX, PintoY, ElonX, ElonY, PrizeX, PrizeY;

char movement;

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
    cout << x << " " << y<< " " << PrizeX << " " << PrizeY;
}


void Logic() {

    while (!GameOver) {
        cout << "Press w to go up, s to down, a to go left and d to go right. To stop the game press r";
        cin >> movement;
        if (movement == 'r')
            GameOver = true;
        if (movement == 'w')
            y--;
        if (movement == 's')
            y++;
        if (movement == 'a')
            x--;
        if (movement == 'd')
            x++;
        if (x == PrizeX && y == PrizeY) {
            cout << "you win";
            GameOver = true;
        }
        if (ElonX == x && ElonY == y)
            break;
    }
    while (!GameOver) {
        cout << "Press w to go up, s to down, a to go left and d to go right. To stop the game press r";
        cin >> movement;
        if (movement == 'r')
            GameOver = true;
        if (movement == 'w')
            y--;
        if (movement == 's')
            y++;
        if (movement == 'a')
            x--;
        if (movement == 'd')
            x++;
        ElonX = rand() % width;
        ElonY = rand() % height;
        if (x == PrizeX && y == PrizeY) {
            cout << "you win";
            GameOver = true;
        }
        if (x == ElonX && y == ElonY || x == YugoX && y == YugoY || x == PintoX && y == PintoY) {
            cout << "You lose";
            GameOver = true;
        }
    }
}


int main() {
    srand(time(NULL));
    SetUp();
    Logic();
	return 0;
}
