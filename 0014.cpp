#include "public.h"
class Solution0014
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty())
        {
            return "";
        }
        std::string result = strs[0];
        for (size_t i = 1; i < strs.size(); i++)
        {
            std::string& str = strs[i];
            int j = 0;
            while (j < result.length() && j < str.length())
            {
                if (result[j] == str[j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            result = result.substr(0, j);
        }
        return result;
    }
};


void test0014()
{
    bool result = false;

    Solution0014 so;

    std::vector<std::string> input1 = { "flower", "flow", "flight" };
    std::string ret1 = "fl";

    std::vector<std::string> input2 = { "dog", "racecar", "car" };
    std::string ret2 = "";

    if (so.longestCommonPrefix(input1) == ret1 &&
        so.longestCommonPrefix(input2) == ret2)
    {
        result = true;
    }

    if (result)
    {
        printf("--------0014:pass--------\n");
    }
    else
    {
        printf("--------0014:fail--------\n");
    }
}