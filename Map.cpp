#include "head.h"

void Map::draw(vector<Point> snackPos, Point foodPos) {
    // ��Point���飨�����꣩��Ԥ����
    bool pointList[MAPL][MAPW] = {false};
    Point headPos = snackPos[0];
    for (Point ele: snackPos) {
        pointList[ele.getY()][ele.getX()] = true;   // �������������ʱ��Ϊtrue
    }

    int food_x = foodPos.getX();
    int food_y = foodPos.getY();

    cout << multiString(MAPBLOCK, mapSizeW) << endl;   // ��һ��
    for (int i = 0; i < mapSizeL - 2; i++) {   // �м���
        cout << MAPBLOCK;   // ��һ��
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
        cout << MAPBLOCK << endl;   // ���һ��
    }
    cout << multiString(MAPBLOCK, mapSizeW) << endl;   // ���һ��
}
