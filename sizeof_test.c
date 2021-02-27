//
// Created by 覃立中 on 2021/2/26.
//gcc -m32 -g -o sizeof_test sizeof_test.c
//

/*
 *有效对齐值：#pragma pack(n)和结构体中最长数据类型长度中较小的那个，Linux下，#pragma pack(n)为4
 * （1）结构体第一个成员的偏移量（offset）为0，以后每个成员相对于结构体首地址的 offset 都是该成员大小与有效对齐值中较小那个的整数倍，如有需要编译器会在成员之间加上填充字节。
 * （2）结构体的总大小为 有效对齐值 的整数倍，如有需要编译器会在最末一个成员之后加上填充字节。
 */

#include<stdio.h>

//#pragma pack(1)  注意有无这个输出的区别
struct
{
    int i;
    char c1;
    char c2;
}x1;

struct{
    char c1;
    int i;
    char c2;
}x2;

struct{
    char c1;
    char c2;
    int i;
}x3;



void test_0()
{
    printf("sizeof(x1) = %d\n",(int)sizeof(x1));  // 输出8
    printf("sizeof(x2) = %d\n",(int)sizeof(x2));  // 输出12
    printf("sizeof(x3) = %d\n",(int)sizeof(x3));  // 输出8
}

int main(int argc, char **argv) {
    test_0();

    return 0;
}