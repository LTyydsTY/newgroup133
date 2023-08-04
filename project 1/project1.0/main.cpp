#include <iostream>
#include <string>
#include "transform.h"
#include "sm3.h"
using namespace std;

#define MAX_NUM 65536

struct Collision {
    string input1;
    string hash1;
    string input2;
    string hash2;
};

void birthday_attack() {
    Collision collision;
    Collision* collisions = new Collision[MAX_NUM];

    for (int i = 0; i < MAX_NUM; i++) {
        string input = to_string(i);
        string paddingValue = padding(input);
        string hashValue = iteration(paddingValue);

        for (int j = 0; j < i; j++) {
            if (collisions[j].hash1.substr(0, 4) == hashValue.substr(0, 4)) {
                collision.input1 = input;
                collision.hash1 = hashValue;
                collision.input2 = collisions[j].input1;
                collision.hash2 = collisions[j].hash1;
                delete[] collisions;

                cout << "找到碰撞！" << endl;
                cout << "输入1: " << collision.input1 << endl;
                cout << "哈希1: " << collision.hash1 << endl;
                cout << "输入2: " << collision.input2 << endl;
                cout << "哈希2: " << collision.hash2 << endl;
                cout << "尝试次数: " << i + 1 << endl;
                return;
            }
        }

        collisions[i].input1 = input;
        collisions[i].hash1 = hashValue;
    }

    delete[] collisions;
    cout << "未找到碰撞！" << endl;
}

int main() {
    birthday_attack();
    return 0;
}