//
// Created by 覃立中 on 2021/2/26.
//gcc -m32 -o array_addr array_addr.c
//

#include<stdio.h>

void test_0()
{
    printf("-----------------------test_0(一维数组)-----------------------\n");
    int arr[5] = {1, 2, 3, 4, 5};

    printf("&arr[0] = %p, &arr[0] + 1 = %p\n", &arr[0], &arr[0] + 1); //相差4字节
    printf("&arr = %p, &arr + 1 = %p\n", &arr, &arr + 1); //相差20字节(sizeof(int) * 5)
    printf("arr = %p, arr + 1 = %p\n\n", arr, arr + 1); //相差4字节
}

void test_1()
{
    printf("-----------------------test_1(二维数组)-----------------------\n");
    int arr[3][5];

    printf("&arr[0][0] = %p, &arr[0][0] + 1 = %p\n", &arr[0][0], &arr[0][0] + 1); //相差4字节
    printf("&arr[0] = %p, &arr[0] + 1 = %p\n", &arr[0], &arr[0] + 1); //相差20字节(sizeof(int) * 5)
    printf("&arr = %p, &arr + 1 = %p\n", &arr, &arr + 1); //相差60字节(sizeof(int) * 5)
    printf("arr = %p, arr + 1 = %p\n", arr, arr + 1); //相差20字节(sizeof(int) * 5)
}

int main(int argc, char **argv)
{
    test_0();
    test_1();

    return 0;
}