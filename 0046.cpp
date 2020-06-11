#include "public.h"

class Solution0046 
{
public:
    int translateNum(int num)
    {
        if (num <= 9)
        {
            return 1;
        }
        else if (num <= 25)
        {
            return 2;
        }

        int base = 1;
        int tmp = num;
        while (tmp >= 10)
        {
            base *= 10;
            tmp /= 10;
        }

        int a = num / base;
        int b = num / (base / 10);

        if (b <= 25)
        {
            return translateNum(num - a * base) + translateNum(num - b * (base / 10));
        }
        else
        {
            return translateNum(num - a * base);
        }
    }
};


bool test0046()
{
    bool result = false;

    Solution0046 so;

    int input1 = 12258;
    int ret1 = 5;
    int input2 = 1068385902;
    int ret2 = 2;

    if (so.translateNum(input1) == ret1 &&
        so.translateNum(input2) == ret2)
    {
        result = true;
    }

    return result;
}