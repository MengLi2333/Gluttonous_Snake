#include "head.h"

bool Controller::gameOver(void) {
    system("cls");
    for (int i = 0; i < myMap.getMapLen() / 2 - 1; i++)
        cout << multiString(MAPBLOCK, myMap.getMapWid()) << endl;
    cout << "游戏结束！" << endl;
    cout << "是否继续？(y/n)" << endl;
    for (int i = 0; i < myMap.getMapLen() - myMap.getMapLen() / 2 - 1; i++)
        cout << multiString(MAPBLOCK, myMap.getMapWid()) << endl;
    fflush(stdin);
    char is_continue = getchar();
    if (is_continue == 'y')
        return true;
    else
        return false;
}

void Controller::run(void) {
    int is_continue = 1;

    while (is_continue) {
        enum Direction dire;
        bool is_changeDire = false;
        Point foodPos = food.getPos();

        system("cls");
        myMap.draw(snack.getPos(), foodPos);

        for (int i = 0; i < 10; i++) {
            Sleep(sleepTime / 10);
            if (GetKeyState('A') < 0)
                dire = Left, is_changeDire = true;
            else if (GetKeyState('S') < 0)
                dire = Down, is_changeDire = true;
            else if (GetKeyState('D') < 0)
                dire = Right, is_changeDire = true;
            else if (GetKeyState('W') < 0)
                dire = Up, is_changeDire = true;
        }

        if (is_changeDire)
            snack.changeDire(dire);

        snack.snackMove();
        Point headPos = snack.getHead();
        if (headPos.getX() == foodPos.getX() && headPos.getY() == foodPos.getY()) {   // 蛇头和食物重叠
            snack.grow();
            food.changePos(randint(1, myMap.getMapWid() - 1), randint(1, myMap.getMapLen() - 1));
        }
        if (headPos.getX() >= myMap.getMapWid() - 2 || headPos.getY() >= myMap.getMapLen() - 2
            || headPos.getX() <= 0 || headPos.getY() <= 0) {   // 蛇头超出范围
            is_continue = gameOver();
        }
    }
}
