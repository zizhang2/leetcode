#include "public.h"

class Solution0064
{
public:
    int sumNums(int n) 
    {
        n && (n += sumNums(n - 1));
        return n;
    }
};


void test0064()
{
    bool result = false;

    Solution0064 so;

    int input1 = 3;
    int ret1 = 6;

    int input2 = 9;
    int ret2 = 45;

    if (so.sumNums(input1) == ret1 &&
        so.sumNums(input2) == ret2)
    {
        result = true;
    }

    if (result)
    {
        printf("--------0064:pass--------\n");
    }
    else
    {
        printf("--------0064:fail--------\n");
    }
}