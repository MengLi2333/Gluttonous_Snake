#ifndef HEAD
#define HEAD

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

#define MAPL 20
#define MAPW 20
#define MAPBLOCK "█"
#define SNACKBLOCK "●"
#define SNACKHEADBLOCK "●"
#define FOODBLOCK "★"

// Other_class.cpp
string multiString(string s, int num);
int randint(int start, int end_num);

class Point {   // 暂无BUG
public:
    int getX(void) {return x;}
    int getY(void) {return y;}
    void changePos(int newX, int newY) {x = newX, y = newY;}
    Point(int newX, int newY): x(newX), y(newY) {
        #if DEBUG
        cout << "Constructor in Point called." << endl;
        #endif // DEBUG
    }
    Point(): Point(0, 0) {}
    Point(const Point &obj): x(obj.x), y(obj.y) {
        #if DEBUG
        cout << "Copy Constructor in Point is called." << endl;
        #endif // DEBUG
    }
private:
    int x, y;
};

// Snack.cpp
enum Direction {Up, Down, Left, Right};

class _body{   // 暂无BUG
public:
    Point getPos(void) {return pos;}
    void changePos(int newX, int newY) {pos.changePos(newX, newY);}
    _body(int x, int y) {
        pos.changePos(x, y);

        #if DEBUG
        cout << "Constructor in _body called." << endl;
        #endif // DEBUG
    }
    _body(): _body(0, 0) {}
private:
    Point pos;
};

class Snack {   // 暂无BUG
public:
    int getLen(void) {return bodys.size();}   // 得到蛇的长度
    enum Direction getDire(void) {return direct;}   // 得到蛇头的方向
    Point getHead(void) {return bodys[0].getPos();}   // 得到蛇头坐标
    void grow(void) {is_grow = true;}   // 加一节身体
    vector<Point> getPos(void);   // 得到蛇的一个身体的位置坐标，返回值是Point数组名，数组大小为蛇身长度
    void changeDire(enum Direction dire);   // 改变蛇头的位置
    void snackMove();
    Snack(int bodylen, enum Direction dir);
    Snack(): Snack(3, Up) {}
private:
    vector<_body> bodys;   // 蛇身
    enum Direction direct;   // 蛇头方向
    bool is_grow;
};

// Food.cpp
class Food {   // 暂无BUG
public:
    Point getPos(void) {return pos;}   // 获取坐标
    void changePos(int newX, int newY) {pos.changePos(newX, newY);}   // 改变坐标
    Food(int newX, int newY) {
        pos.changePos(newX, newY);

        #if DEBUG
        cout << "Constructor in Food is called." << endl;
        #endif // DEBUG
    }
    Food(): Food(0, 0) {}
private:
    Point pos;
};

// Map.cpp
class Map {   // 暂无BUG
public:
    void draw(vector<Point> snackPos, Point foodPos);
    void changeMapSize(int newL, int newW) {mapSizeL = newL, mapSizeW = newW;}
    int getMapLen(void) {return mapSizeL;}
    int getMapWid(void) {return mapSizeW;}
    Map(): mapSizeL(MAPL), mapSizeW(MAPW) {
        #if DEBUG
        cout << "Constructor in Map is called." << endl;
        #endif // DEBUG
    }
private:
    int mapSizeL;
    int mapSizeW;
};

// Controller.cpp
class Controller {
public:
    void run(void);
    void changeSleepTime(int newTime) {sleepTime = newTime;}
    Controller(int sleepTime): sleepTime(sleepTime) {
        srand(time(0));
        food.changePos(randint(1, myMap.getMapWid() - 1), randint(1, myMap.getMapLen() - 1));
        #if DEBUG
        cout << "Constructor in Controller is called." << endl;
        #endif // DEBUG
    }
    Controller(): Controller(500) {}
private:
    int sleepTime;
    Snack snack;
    Food food;
    Map myMap;
    bool gameOver(void);
};

#endif // HEAD
