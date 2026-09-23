#include <vector>
#include <iostream>
using namespace std;

#include <string>
#include <sstream>
#include <limits>
void Multi_Input(vector<int>& v)
{
    string line; //line一会用于存储从cin得到的一整行数据
    cout << "请输入若干数字，须使用空格分隔，按回车提交: " << endl;

    getline(cin, line); //getline可以实现从cin中拿到一整行的输入数据，放在line里
    stringstream ss(line); //stringstream ss(line) 可以从line中构造输入流数据给ss， 并且可以从中分割数据

    int tmp;
    while (ss >> tmp)
    {
        v.push_back(tmp);
    }
}

void Print_Vector(vector<int> v)
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
    vector<int> plusOne(vector<int>& digits)
    {
        int len = digits.size();
        int last = len - 1;

        for (int i = last; i >= 0; i--)
        {
            if (digits[i] == 9 && i != 0)
            {
                digits[i] = 0;
            }
            else if (digits[i] == 9 && i ==0)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
                return digits;
            }
            else if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
        }
        return digits;  //C++要求所有分支都要有return，即便for循环必然命中return，但是语法不允许for之后没有return

    }
};

int main()
{
    vector<int> digits;
    Multi_Input(digits);
    Solution s;

    vector<int> v = s.plusOne(digits);
    Print_Vector(v);

    system("pause");
    return 0;
}