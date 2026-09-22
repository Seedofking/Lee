#include <iostream>
#include <vector>
using namespace std;

void Print_Vector (vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it == val)
            {
                nums.erase(it);
                it = nums.begin() - 1;
            }
        }
        return nums.size();
    }
};


int main()
{
    vector<int> nums = {1, 1, 1, 1, 2, 4, 5, 5, 5, 5, 5, 7, 7, 8, 0, 0};
    Solution s;
    s.removeElement(nums, 1);
    Print_Vector(nums);




    system("pause");
    return 0;
}
