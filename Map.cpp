#include "head.h"

void Map::draw(vector<Point> snackPos, Point foodPos) {
    // 对Point数组（蛇坐标）的预处理
    bool pointList[MAPL][MAPW] = {false};
    Point headPos = snackPos[0];
    for (Point ele: snackPos) {
        pointList[ele.getY()][ele.getX()] = true;   // 当这个坐标是蛇时，为true
    }

    int food_x = foodPos.getX();
    int food_y = foodPos.getY();

    cout << multiString(MAPBLOCK, mapSizeW) << endl;   // 第一行
    for (int i = 0; i < mapSizeL - 2; i++) {   // 中间行
        cout << MAPBLOCK;   // 第一列
        for (int j = 0; j < mapSizeW - 2; j++) {
            if (pointList[i][j]) {
                if (i == headPos.getY() && j == headPos.getX())
                    cout << SNACKHEADBLOCK;
                else
                    cout << SNACKBLOCK;
            }
            else if (i == food_y && j == food_x)
                cout << FOODBLOCK;
            else
                cout << MAPBLOCK;
        }
        cout << MAPBLOCK << endl;   // 最后一列
    }
    cout << multiString(MAPBLOCK, mapSizeW) << endl;   // 最后一行
}
