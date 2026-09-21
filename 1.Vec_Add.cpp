#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (vector<int>::iterator it = nums.begin(); it != nums.end() - 1; ++it)
        {
            auto vit = it + 1;  //可以用vit = it来存住外一层for指针的位置，用vit开始内层循环
            if(*it <= target)
            {
                for(vit; vit != nums.end(); ++vit)
                {
                    if (*vit + *it == target)
                    {
                        int First_Pos = it - nums.begin();
                        int Second_Pos = vit - nums.begin();
                        vector<int> ansv = {First_Pos, Second_Pos};
                        //cout << "First_num: " << *it << ", Second_num: " << *vit << endl;
                        //cout << "First_Pos: " << it - nums.begin() << ", Second_Pos: " << vit - nums.begin() << endl;
                        //cout << "[" << it - nums.begin() << ", " << vit - nums.begin() << "]" << endl;
                        return ansv;   //c++中两个同类型指针相减不会得到地址值的差，而是两个指针之间包含的元素数量
                        //如果是想反映it指向了第几个元素，那么应该加一，如果想知道其对应的数组下标，就正好不用加了
                    }
                }
            }
        }
        cout << "No such numbers" << endl;
        return vector<int>{};
    }
};

void Print_Vector(vector<int> &v)
{
    cout << "["<< v.front() << "," << v.back() << "]" << endl;
}

int main()
{
    vector<int> Nu = {0, 4, 3, 0};
    Solution s;

    vector<int> pv = s.twoSum(Nu, 0);
    Print_Vector(pv);
    return 0;
}