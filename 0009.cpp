#include "public.h"

class Solution0009
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else if (x < 10)
        {
            return true;
        }

        int result = true;
        std::vector<uint8_t> vec;
        while (x)
        {
            vec.push_back(x % 10);
            x /= 10;
        }

        int i = 0;
        int j = vec.size() - 1;
        while (i <= j)
        {
            if (vec[i] == vec[j])
            {
                i++;
                j--;
            }
            else
            {
                result = false;
                break;
            }
        }
        return result;
    }
};

void test0009()
{
    bool result = false;

    Solution0009 so;

    int input1 = 121;
    int ret1 = true;
    int input2 = -121;
    int ret2 = false;
    int input3 = 10;
    int ret3 = false;

    if (so.isPalindrome(input1) == ret1 &&
        so.isPalindrome(input2) == ret2 &&
        so.isPalindrome(input3) == ret3)
    {
        result = true;
    }

    if (result)
    {
        printf("--------0009:pass--------\n");
    }
    else
    {
        printf("--------0009:fail--------\n");
    }
}