#include <iostream>
#include <vector>
using namespace std;

void Print_Vector(vector<int>& nums)
{
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
}


class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();

        for (int i = 0; i < len - 1; ++i) //for循环结束之后会执行++i，所以i = 0之后，i都会从0开始，i = -1的话就可以抵消这个+1
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
                len = nums.size();
                i = -1;
            }

        }
        // Print_Vector(nums);
        return nums.size();
    }
};


int main()
{
    vector<int> nums = {0, 0, 0, 0 ,0 ,1, 1, 2, 2, 2, 2, 2, 2, 4, 5, 5, 6};
    Solution s;
    int k = s.removeDuplicates(nums);
    cout << "k = " << k << endl;

    system("pause");
    return 0;
}