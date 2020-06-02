#include "public.h"
#include <stdio.h>

void test()
{
    if (test0007())
    {
        printf("--------0007:pass--------\n");
    }
    else
    {
        printf("--------0007:fail--------\n");
    }
    if (test0064())
    {
        printf("--------0064:pass--------\n");
    }
    else
    {
        printf("--------0064:fail--------\n");
    }
    if (test1431())
    {
        printf("--------1431:pass--------\n");
    }
    else
    {
        printf("--------1431:fail--------\n");
    }
}


int main()
{
    test();
    return 0;
}