/*
给你一个按 非递减顺序 排序的整数数组 nums，
返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
*/
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

class Solution
{
public:
    // 暴力解法 Violent solution
    vector<int> sortedSquares(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }
    // 双指针 Double pointer

    vector<int> sortedSquares2(vector<int> &A)
    {
        int left = 0;
        int right = A.size() - 1;
        int i = A.size();
        vector<int> B(i);
        // int index = 0;
        //while循环注意 边界

        while (left <= right)
        {
            if (A[left] * A[left] < A[right] * A[right])
            {
                // B.push_back(A[left] * A[left]);
                // B.push_back(A[right] * A[right]);
                B[i-1]=A[right] * A[right];
                right --;
               
            }
            else
            {
                // B.push_back(A[right] * A[right]);
                // B.push_back(A[left] * A[left]);
                B[i-1]=A[left] * A[left];
                 left ++;
            }
            i--;
        }
        return B;
    }
};
//answer

class Solutionaa {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

int main()
{
    // 在这里编写你的代码
    vector<int> obj;
    for (int i = -4; i < 10; ++i)
    {
        obj.push_back(i); // 将 i 添加到 obj 中
    }
    cout << obj[5] << endl;
    for (int num : obj)
    {
        cout << num << " ";
    }

    // return 0;
    cout << endl;

    Solution aa;
    cout << endl;
    // cout << aa.sortedSquares2(obj) << endl;
    // inta a = ;
    for (int num : aa.sortedSquares2(obj))
    {
        std::cout << num << " ";
    }
    // cout <<obj.begin() obj.end();
    //     for (auto it = obj.begin(); it != obj.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // Solution mm;
    // cout << mm.search(obj,3) << endl ;

    cout << "end";
    return 0; // 返回0表示程序成功结束
}
