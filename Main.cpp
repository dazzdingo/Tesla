#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;
const int maxx = 15;
bool GameOver;
const int width = maxx;
const int height = maxx;
int x, y, YugoX, YugoY, PintoX,PintoY, ElonX, ElonY, PrizeX,PrizeY;
enum eDirection {Stop = 0, Left, Right, Up, Down};
eDirection dir;

void SetUp(){
    GameOver = false;
    dir = Stop;
    x = rand() % width + 1;
    y = rand() % height + 1;
    YugoX = rand() % width +1;
    YugoY = rand() % height +1;
    PintoX = rand() % width +1;
    PintoY = rand() % height +1;
    ElonX = rand() % width +1;
    ElonY = rand() % height +1;
    PrizeX = rand() % width +1;
    PrizeY = rand() % height +1;
}

void Draw(){
    system("cls"); //clearscreen
    for (int i = 0; i < width + 2; i++)
        cout << "x";
    cout << endl;
    for (int i = 0; i < width + 2; i++){
        for (int j = 0; j <= height + 1; j++){
            if (j == 0){
                cout << "x";
            }
            if (j == width ) {
                cout << "x";
            }
            if (i == y && j == x){
                cout << "O";
            }
            else {
                cout << " ";
            }

        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
        cout << "x";
    cout << endl;
}

void Input(){
    if (_kbhit()){
        switch (_getch()) {
        case 'w':
            dir = Up;
            break;
        case 's':
            dir = Down;
            break;
        case 'a':
            dir = Left;
            break;
        case 'd':
            dir = Right;
            break;
        case 'r':
            GameOver = true;
            break;
        }
    }
}

void Logic(){
    switch (dir) {
    case Stop:
        break;
    case Up:
        y--;
        break;
    case Down:
        y++;
        break;
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    default:
        break;

    }

}
int main (){
srand(time(NULL));
SetUp();
while (!GameOver) {
    Draw();
    Input();
    Logic();
    Sleep(10);
}
return 0;
}
