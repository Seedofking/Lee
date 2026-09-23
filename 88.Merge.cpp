#include <iostream>
#include <vector>
using namespace std;

#include <string>
#include <sstream>

void Multi_Input1(vector<int>& v)
{
    string line; //line一会用于存储从cin得到的一整行数据
    cout << "请输入若干数字，须使用空格分隔，按回车提交: " << endl;
    // cin.ignore();
    getline(cin, line); //getline可以实现从cin中拿到一整行的输入数据，放在line里
    stringstream ss(line); //stringstream ss(line) 可以从line中构造输入流数据给ss， 并且可以从中分割数据

    int tmp;
    while (ss >> tmp)
    {
        v.push_back(tmp);
    }
}



void Print_Vector(vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " " ;

    }
    cout << endl;
}

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
        {
            vector<int>::iterator kit = nums1.begin();

            for (vector<int>::iterator vit = kit; vit != nums1.end(); ++vit)
            {
                if (*it <= *vit)
                {
                    nums1.insert(vit, *it);
                    auto kit = vit;
                    break;
                }
                else if (vit == nums1.end() - n)
                {
                    nums1.insert(vit, *it);
                    break;
                }
            }

        }
        nums1.resize(m + n);

    }
};



int main()
{
    vector<int> nums2;
    Multi_Input1(nums2);
    int n = nums2.size();

    vector<int> nums1;
    Multi_Input1(nums1);
    int m = nums1.size() - n;

    Solution s;
    s.merge(nums1, m, nums2, n);
    Print_Vector(nums1);


    system("pause");
    return 0;
}