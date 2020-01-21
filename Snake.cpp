#include "head.h"

Snack::Snack(int bodylen, enum Direction dir): direct(dir), is_grow(false) {
    for (int i = 0; i < bodylen; i++) {
        _body tmp_body(MAPL / 2, MAPW / 2 + i);

        bodys.push_back(tmp_body);
    }
}

vector<Point> Snack::getPos(void) {
    vector<Point> pos(bodys.size());
    int i = 0;

    for (_body each_body: bodys) {
        Point tmp_point = each_body.getPos();
        pos[i++].changePos(tmp_point.getX(), tmp_point.getY());
    }

    return pos;
}

void Snack::snackMove() {
    vector<_body>::iterator it = bodys.begin();
    _body head;
    int x = bodys[0].getPos().getX();
    int y = bodys[0].getPos().getY();

    switch (direct) {   // 添加新的头
    case (Up):
        head.changePos(x, y - 1);
        bodys.insert(it, head);
        break;
    case (Down):
        head.changePos(x, y + 1);
        bodys.insert(it, head);
        break;
    case (Left):
        head.changePos(x - 1, y);
        bodys.insert(it, head);
        break;
    case (Right):
        head.changePos(x + 1, y);
        bodys.insert(it, head);
        break;
    }

    if (is_grow) {   // 蛇在成长时，跳过删除尾巴的步骤
        is_grow = false;
        return ;
    }
    it = bodys.end();
    bodys.erase(it);   // 删除老尾巴
}

void Snack::changeDire(enum Direction dire) {
    switch (dire) {
    case Up:
        if (direct == Left ||direct == Right)
            direct = Up;
        break;
    case Down:
        if (direct == Left ||direct == Right)
            direct = Down;
        break;
    case Left:
        if (direct == Up ||direct == Down)
            direct = Left;
        break;
    case Right:
        if (direct == Up ||direct == Down)
            direct = Right;
        break;
    }
}

