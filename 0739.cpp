#include "public.h"

class Solution0739
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& T)
    {
        std::vector<int> result(T.size(), 0);

        for (int i = T.size() - 2; i >= 0; i--)
        {
            if (T[i] < T[i + 1])
            {
                result[i] = 1;
            }
            else if (T[i] == T[i + 1])
            {
                result[i] = (result[i + 1] > 0) ? (result[i + 1] + 1) : 0;
            }
            else
            {
                for (size_t j = i + 1; j < T.size(); j++)
                {
                    if (T[j] > T[i])
                    {
                        result[i] = j - i;
                        break;
                    }
                    else if (T[j] == T[i])
                    {
                        result[i] = result[j] > 0 ? result[j] + j - i : 0;
                        break;
                    }
                }
            }
        }

        return result;
    }
};

bool test0739()
{
    bool result = false;

    Solution0739 so;

    std::vector<int> input1{ 73,74,75,71,69,72,76,73 };
    std::vector<int> ret1{ 1, 1, 4, 2, 1, 1, 0, 0 };

    if (so.dailyTemperatures(input1) == ret1)
    {
        result = true;
    }

    return result;
}