#include<stdio.h>
#include <stdint.h>
#include<time.h>
#include"SM4.h"

void SM4(uint32_t* plain, uint32_t* MK, uint32_t* M);

int main() {
    int i, j;
    uint32_t MK[4] = { 0x34567654,0XDFEEAADD,0xfeDCBA98,0X76543210 };
    uint32_t plain[4] = { 0x06734543,0x89ABBDEF,0xfeDCBA78,0X765434510 };
    uint32_t M[4];
    clock_t time1, time2;
    time1 = clock();
    SM4(plain, MK, M);
    printf("SM4���ܽ��Ϊ��\n");
    for (i = 0; i < 4; i++)
        printf(" 0x%08x  ", M[i]);
    time2 = clock();
    printf("\n����ʱ��Ϊ��%d ms", (time2 - time1));
    return 0;
}