#include "public.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};


void recur_delete(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->left)
    {
        recur_delete(node->left);
    }

    if (node->right)
    {
        recur_delete(node->right);
    }

    delete node;
    node = nullptr;
}


bool operator==(TreeNode& lhs, TreeNode& rhs)
{
    bool result = false;
    if (lhs.val == rhs.val)
    {
        if ((lhs.left && rhs.left && ((*lhs.left) == *(rhs.left)))
            || (lhs.left == nullptr && rhs.left == nullptr) &&
            (lhs.right && rhs.right && ((*lhs.right) == *(rhs.right)))
                || (lhs.right == nullptr && rhs.right == nullptr))
        {
            result = true;
        }
    }
    return result;
}

class Codec
{
public:

    std::string serialize(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "";
        }

        std::string result;

        std::string tmp;
        std::stringstream ss;

        bool odd = true;
        std::list<TreeNode*> list1{ root };
        std::list<TreeNode*> list2;
        
        while (true)
        {
            std::list<TreeNode*>* cur_list;
            std::list<TreeNode*>* next_list;
            if (odd)
            {
                odd = false;
                cur_list = &list1;
                next_list = &list2;
            }
            else
            {
                odd = true;
                cur_list = &list2;
                next_list = &list1;
            }


            bool all_null = true;

            std::string s;
            bool valid_s = false;

            std::list<TreeNode*>::iterator iter = (*cur_list).begin();
            while (iter != (*cur_list).end())
            {
                if (*iter == nullptr)
                {
                    s += "_ ";
                    
                }
                else
                {
                    valid_s = true;
                    ss.clear();
                    ss << (*iter)->val;
                    ss >> tmp;

                    if (result.empty())
                    {
                        s += tmp;
                    }
                    else
                    {
                        s += "_" + tmp;
                    }

                    if ((*iter)->left)
                    {
                        all_null = false;
                        (*next_list).push_back((*iter)->left);
                    }
                    else
                    {
                        (*next_list).push_back(nullptr);
                    }

                    if ((*iter)->right)
                    {
                        all_null = false;
                        (*next_list).push_back((*iter)->right);
                    }
                    else
                    {
                        (*next_list).push_back(nullptr);
                    }
                }
                iter++;
            }

            if (valid_s)
            {
                result += s;
            }

            (*cur_list).clear();
            if (all_null)
            {
                (*next_list).clear();
            }

            if ((*next_list).empty())
            {
                break;
            }
        }
        return result;
    }

    TreeNode* deserialize(std::string data)
    {
        if (data.empty())
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(atoi(data.c_str()));

        bool odd = true;
        std::list<TreeNode*> list1{ root };
        std::list<TreeNode*> list2;
        size_t last_pos = 0;

        while (true)
        {
            std::list<TreeNode*>* cur_list;
            std::list<TreeNode*>* next_list;
            if (odd)
            {
                odd = false;
                cur_list = &list1;
                next_list = &list2;
            }
            else
            {
                odd = true;
                cur_list = &list2;
                next_list = &list1;
            }

            std::list<TreeNode*>::iterator iter = (*cur_list).begin();
            while (iter != (*cur_list).end())
            {
                last_pos = data.find("_", last_pos + 1);
                if (last_pos != data.npos)
                {
                    if (data[last_pos + 1] != ' ')
                    {
                        (*iter)->left = new TreeNode(atoi(data.c_str() + last_pos + 1));
                        next_list->push_back((*iter)->left);
                    }
                }
                else
                {
                    break;
                }
                
                last_pos = data.find("_", last_pos + 1);
                if (last_pos != data.npos)
                {
                    if (data[last_pos + 1] != ' ')
                    {
                        (*iter)->right = new TreeNode(atoi(data.c_str() + last_pos + 1));
                        next_list->push_back((*iter)->right);
                    }
                }

                iter++;
            }

            cur_list->clear();
            if (next_list->empty())
            {
                break;
            }

        }

        return root;
    }
};

void test0297()
{
    bool result = false;

    Codec codec;

    TreeNode input1(1);
    TreeNode i1_l1_left(2), i1_l1_right(3);
    TreeNode i1_l2_left1(4), i1_l2_right1(5);
    input1.left = &i1_l1_left;
    input1.right = &i1_l1_right;
    i1_l1_right.left = &i1_l2_left1;
    i1_l1_right.right = &i1_l2_right1;

    //std::string ret1 = "1_2_3_ _ _4_5";

    TreeNode input2(1);
    TreeNode i2_l1_right(2);
    input2.right = &i2_l1_right;
    //std::string ret2 = "1_ _2";

    TreeNode* ret1 = codec.deserialize(codec.serialize(&input1));
    TreeNode* ret2 = codec.deserialize(codec.serialize(&input2));

    if (*ret1 == input1 && *ret2 == input2)
    {
        result = true;
    }

    recur_delete(ret1);
    recur_delete(ret2);

    if (result)
    {
        printf("--------0297:pass--------\n");
    }
    else
    {
        printf("--------0297:fail--------\n");
    }
}