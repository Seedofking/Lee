#include <iostream>
#include <vector>
using namespace std;

void Print_Vector(vector<int>& v) //如果传入参数改成const vector<int> &v
{
    //下面的迭代器就要改成for(vector<int>::const_iterator it; .... 是只读的
    //for遍历输出
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) //++it在for
    {
        cout << *it << " ";
    }
    cout << endl;
}


class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> Front;
        vector<int> Next;

        //递归基线
        if (rowIndex == 0)
        {
            return {1};
        }

        //得到前一个（通过同一个函数递归得到前一个结果）
        Front = getRow(rowIndex - 1);

        //构建下一个
        Next.push_back(1);
        for (int i = 1; i < rowIndex; ++i)
        {
            Next.push_back(Front[i] + Front[i - 1]);
        }
        Next.push_back(1);

        //return下一个，完成从前一个到下一个的闭环
        return Next;
    }
};

int main()
{
    Solution s;
    int rowIndex;

    cout << "Input rowIndex: " << endl;
    cin >> rowIndex;

    vector<int> v = s.getRow(rowIndex);
    Print_Vector(v);

    system("pause");
    return 0;
}
