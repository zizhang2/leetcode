#include "public.h"

#include <vector>
using std::vector;


class Solution1431
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> ret;

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


bool test1431()
{
    bool ret = false;

    Solution1431 so;

    vector<int> candies1 = { 2, 3, 5, 1, 3 };
    int extraCandies1 = 3;
    vector<bool> ret1 = { true, true, true, false, true };

    vector<int> candies2 = { 4, 2, 1, 1, 2 };
    int extraCandies2 = 1;
    vector<bool> ret2 = { true, false, false, false, false };

    vector<int> candies3 = { 12, 1, 12 };
    int extraCandies3 = 10;
    vector<bool> ret3 = { true, false, true };

    if (so.kidsWithCandies(candies1, extraCandies1) == ret1 &&
        so.kidsWithCandies(candies2, extraCandies2) == ret2 &&
        so.kidsWithCandies(candies3, extraCandies3) == ret3)
    {
        ret = true;
    }

    return ret;
}