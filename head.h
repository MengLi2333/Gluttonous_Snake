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
#define MAPBLOCK "��"
#define SNACKBLOCK "��"
#define SNACKHEADBLOCK "��"
#define FOODBLOCK "��"

// Other_class.cpp
string multiString(string s, int num);
int randint(int start, int end_num);

class Point {   // ����BUG
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

class _body{   // ����BUG
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

class Snack {   // ����BUG
public:
    int getLen(void) {return bodys.size();}   // �õ��ߵĳ���
    enum Direction getDire(void) {return direct;}   // �õ���ͷ�ķ���
    Point getHead(void) {return bodys[0].getPos();}   // �õ���ͷ����
    void grow(void) {is_grow = true;}   // ��һ������
    vector<Point> getPos(void);   // �õ��ߵ�һ�������λ�����꣬����ֵ��Point�������������СΪ������
    void changeDire(enum Direction dire);   // �ı���ͷ��λ��
    void snackMove();
    Snack(int bodylen, enum Direction dir);
    Snack(): Snack(3, Up) {}
private:
    vector<_body> bodys;   // ����
    enum Direction direct;   // ��ͷ����
    bool is_grow;
};

// Food.cpp
class Food {   // ����BUG
public:
    Point getPos(void) {return pos;}   // ��ȡ����
    void changePos(int newX, int newY) {pos.changePos(newX, newY);}   // �ı�����
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
class Map {   // ����BUG
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
