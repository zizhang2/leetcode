#include "public.h"

class Solution0007 
{
public:
    int reverse(int x) 
    {
        unsigned long long tmp = 0;

        bool neg = x < 0 ? true : false;
        bool min = x == INT32_MIN ? true : false;
        if (min)
        {
            tmp = (x % 10) + 1;
            x /= 10;
        }
        else
        {
            x = x < 0 ? -1 * x : x;
        }

        while (x)
        {
            tmp = tmp * 10 + (x % 10);
            if (tmp > INT32_MAX)
            {
                tmp = 0;
                break;
            }
            x /= 10;
        }

        int ret = neg ? -1 * tmp : tmp;

        return ret;
    }
};


void test0007()
{
    bool result = false;

    Solution0007 so;

    int input1 = 123;
    int ret1 = 321;

    int input2 = -123;
    int ret2 = -321;

    int input3 = 120;
    int ret3 = 21;

    if (so.reverse(input1) == ret1 &&
        so.reverse(input2) == ret2 &&
        so.reverse(input3) == ret3)
    {
        result = true;
    }

    if (result)
    {
        printf("--------0007:pass--------\n");
    }
    else
    {
        printf("--------0007:fail--------\n");
    }
}