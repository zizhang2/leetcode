#include "public.h"

class Solution1431
{
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
    {
        std::vector<bool> ret;

        int max = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] >= max)
            {
                max = candies[i];
            }
        }

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                ret.push_back(true);
            }
            else
            {
                ret.push_back(false);
            }
        }

        return ret;
    }
};


void test1431()
{
    bool result = false;

    Solution1431 so;

    std::vector<int> candies1 = { 2, 3, 5, 1, 3 };
    int extraCandies1 = 3;
    std::vector<bool> ret1 = { true, true, true, false, true };

    std::vector<int> candies2 = { 4, 2, 1, 1, 2 };
    int extraCandies2 = 1;
    std::vector<bool> ret2 = { true, false, false, false, false };

    std::vector<int> candies3 = { 12, 1, 12 };
    int extraCandies3 = 10;
    std::vector<bool> ret3 = { true, false, true };

    if (so.kidsWithCandies(candies1, extraCandies1) == ret1 &&
        so.kidsWithCandies(candies2, extraCandies2) == ret2 &&
        so.kidsWithCandies(candies3, extraCandies3) == ret3)
    {
        result = true;
    }

    if (result)
    {
        printf("--------1431:pass--------\n");
    }
    else
    {
        printf("--------1431:fail--------\n");
    }
}