#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct jingdian {
    int A, B, C, D;
};

int main() {
    struct jingdian jing = {0, 0, 0, 0};
    int* arr[] = {&jing.A, &jing.B, &jing.C, &jing.D};
    int len = sizeof(arr) / sizeof(*arr[0]);
    const char* arrn = NULL; // 指向字符串的指针
    int count = 0, index = 0;
    srand((unsigned int)time(NULL));

    // 随机增加票数
    for (int i = 0; i < 80; i++) {
        int c = rand() % 4 + 1;
        if (c == 1) {
            (*arr[0])++;
        } else if (c == 2) {
            (*arr[1])++;
        } else if (c == 3) {
            (*arr[2])++;
        } else {
            (*arr[3])++;
        }
    }

    // 输出每个选项的票数
    for (int j = 0; j < 4; j++) {
        printf("%d\n", *arr[j]);
    }

    // 找出票数最多的项
    for (int t = 0; t < len; t++) {
        printf("Comparing arr[%d]: %d with count: %d\n", t, *arr[t], count); // 调试输出
        if (*arr[t] > count) {
            count = *arr[t];
            index = t + 1; // 索引从1开始
        }
    }

    // 根据索引值判断对应的成员变量名称
    switch (index) {
        case 1: arrn = "jing.A"; break;
        case 2: arrn = "jing.B"; break;
        case 3: arrn = "jing.C"; break;
        case 4: arrn = "jing.D"; break;
        default: arrn = "Unknown"; break;
    }

    // 输出票数最多的选项
    printf("票数最多为 %s，共 %d 票\n", arrn, count);

    return 0;
}
