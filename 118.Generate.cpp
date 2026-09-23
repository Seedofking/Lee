#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

//遍历输出vector嵌套vector
void Print_Vector_Vector(vector<vector<int>>& v)
{
    cout << "{ ";
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //此时*it指向vector<int> 所以(*it)就是vector，作为传入下一个循环的处理的vector
        cout << "{";
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            if (vit != (*it).end() - 1)
            {
                cout << *vit << ", ";
            }
            else if (vit == (*it).end() - 1)
            {
                cout << *vit;
            }
        }
        if (it != v.end() - 1)
        {
            cout << "}, ";
        }
        else if (it == v.end() - 1)
        {
            cout << "}";
        }
    }
    cout << " }" << endl;
}

class Solution
{
public:
    vector<int> Front;
    vector<int> Next;
    vector<vector<int>> Result;


    vector<vector<int>> generate(int numRows)
    {

        if (numRows == 1)
        {
            Result.push_back({1});
        }
        else if (numRows == 2)
        {
            Result.push_back({1});
            Result.push_back({1, 1});
        }
        else if (numRows >= 3)
        {
            Result.push_back({1});
            Result.push_back({1, 1});
            Front = {1, 1};
            for (int row = 3; row <= numRows; row++)    //层
            {
                Next.push_back(1);
                for (int midNums = 1; midNums < row - 1; midNums++) //层内数
                {
                    int midVal = Front[midNums] + Front[midNums-1];
                    // cout << "F[midNums] = " << Front[midNums] << endl;
                    // cout << "F[midNums - 1] = " << Front[midNums-1] << endl;
                    Next.push_back(midVal);
                }
                Next.push_back(1);
                Result.push_back(Next);
                Front = Next;
                Next.clear();
            }

        }
        else
        {
            cout << "Error" << endl;
        }
        return Result;
    }
};

int main()
{
    int n;
    cout << "Input numRows: " << endl;
    cin >> n;
    vector<vector<int>> v;

    Solution s;
    v = s.generate(n);
    Print_Vector_Vector(v);

    system("pause");
    return 0;
}