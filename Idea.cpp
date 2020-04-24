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
    cout << "You are starting at " << x << " - " << y << " - " << ElonX << " - " << ElonY;
}


void Logic() {

    while (!GameOver) {
        cout << "Press w to go up, s to down, a to go left and d to go right. To stop the game press r" << endl;
        cin >> movement;
        if (movement == 'r')
            GameOver = true;
        if (movement == 'w'){
            y--;
            if (y < 1) {
                cout << "you are getting out of the map" << endl;
                y++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 's') {
            y++;
            if (y > 15) {
                cout << "you are getting out of the map" << endl;
                y--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'a') {
            x--;
            if (x < 1) {
                cout << "you are getting out of the map" << endl;
                x++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'd') {
            x++;
            if (x > 15) {
                cout << "you are getting out of the map" << endl;
                x--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (abs(x - PrizeX) < 3 ) 
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) < 3) 
            cout << "You are getting warmer vertically" << endl;
        if (x == PrizeX && y == PrizeY) {
            cout << "you win" << endl;
            GameOver = true;
        }
        if (x == ElonX && y == ElonY) {
            cout << "You have encountered Elon" << endl;
            break;
        }
    }
    while (!GameOver) {
        cout << "Press w to go up, s to down, a to go left and d to go right. To stop the game press r" << endl;
        cin >> movement;
        if (movement == 'r')
            GameOver = true;
        if (movement == 'w') {
            y--;
            if (y < 1) {
                cout << "you are getting out of the map" << endl;
                y++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 's') {
            y++;
            if (y > 15) {
                cout << "you are getting out of the map" << endl;
                y--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'a') {
            x--;
            if (x < 1) {
                cout << "you are getting out of the map" << endl;
                x++;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        if (movement == 'd') {
            x++;
            if (x > 15) {
                cout << "you are getting out of the map" << endl;
                x--;
            }
            cout << "You are now at " << x << " - " << y << endl;
        }
        ElonX = rand() % width;
        ElonY = rand() % height;
        if (abs(x - PrizeX) < 3)
            cout << "You are getting warmer horizontally" << endl;
        if (abs(y - PrizeY) < 3)
            cout << "You are getting warmer vertically" << endl;
        if (x == PrizeX && y == PrizeY) {
            cout << "you win";
            GameOver = true;
        }
        if (x == ElonX && y == ElonY || x == YugoX && y == YugoY || x == PintoX && y == PintoY) {
            cout << "You lose" << endl;
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
