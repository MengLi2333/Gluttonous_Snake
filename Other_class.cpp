#include "head.h"

string multiString(string s, int num) {
    string temp_s = s;

    for (int i = 0; i < num - 1; i++) {
        temp_s += s;
    }

    return temp_s;
}

int randint(int start, int end_num) {
    double temp = (double)(rand()) / RAND_MAX * (end_num - start) + start;

    if (temp - (int)temp > 0.5)
        return (int)temp + 1;
    else
        return (int)temp;
}
