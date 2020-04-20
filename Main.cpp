#include <iostream>
#include <ctime>


using namespace std;
const int maxx = 15;
bool GameOver;
const int width = maxx;
const int height = maxx;
int x, y, YugoX, YugoY, PintoX,PintoY, ElonX, ElonY, PrizeX,PrizeY;
enum eDirection {Stop = 0, left, right, up, down};

void SetUp(){
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
    
}

void Draw(){
    
    
}

void Input(){
    
    
}

void Logic(){
    
    
}
int main (){
    while (!GameOver) {
        SetUp();
        Draw();
        Input();
        Logic();        
    }
    return 0;
}
