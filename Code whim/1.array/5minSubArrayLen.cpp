/*
给定一个含有 n 个正整数的数组和一个正整数 s ，
找出该数组中满足其和 ≥ s 的长度最小的 连续子数组，
并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/
// double pointers
#include <iostream>
#include <vector>
using namespace std;
// 暴力解法 Violent solution
class Solution1
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int result = INT32_MAX; // 最终的结果
        int sum = 0;            // 子序列的数值之和
        int subLength = 0;      // 子序列的长度
        for (int i = 0; i < nums.size(); i++)
        { // 设置子序列起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            { // 设置子序列终止位置为j
                sum += nums[j];
                if (sum >= s)
                {                          // 一旦发现子序列和超过了s，更新result
                    subLength = j - i + 1; // 取子序列的长度
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

// 双指针 滑动窗口思路正确
// 定义需求值

class Solution2
{
public:
    int minSubArrayLen(int s, vector<int> &nums) // 开始的是返回值
    {
        int result = INT32_MAX; // 最大值  存放最大的窗口
        int sum = 0;
        int i = 0; // 慢指针
        int subLength = 0;
        for ( int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= s)
            {
                // subLength
                subLength = j - i + 1;
                // update result
                result = result < subLength ? result : subLength;
                // update sum
                sum -= nums[i++];
            }
        }

        return result == INT32_MAX ? 0 : result; // 判断是否更了result
    }

    
};

//         int result = INT32_MAX;
//         int sum = 0;       // 滑动窗口数值之和
//         int slow = 0;      // 滑动窗口起始位置
//         int subLength = 0; // 滑动窗口的长度
//         int fast = 0;
//         while (fast < nums.size())
//         {
//             sum += nums[fast];
//             // 更新窗口
//             while (sum >= s)
//             {
//                 subLength = (fast - slow + 1); // 取子序列的长度
//                 result = result < subLength ? result : subLength;
//                 sum -= nums[slow++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
//             }
//             fast ++;
//         }

//         return result == INT32_MAX ? 0 : result;
//     }
// };

class Solution3
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;       // 滑动窗口数值之和
        int i = 0;         // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s)
            {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
                // 注意++i 和i++ 的区别
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main()
{
    // 在这里编写你的代码
    vector<int> obj{2, 3, 1, 2, 4, 3};
    // for (int i = -4; i < 10; i += 2)
    // {
    //     obj.push_back(i); // 将 i 添加到 obj 中
    // }
    // cout << obj[5] << endl;
    // for (int num : obj)
    // {
    //     cout << num << " ";

    // }
    // cout << endl;
    Solution2 aa;

    // for (int num : aa.sortedSquares2(obj))
    // {
    //     std::cout << num << " ";
    // }

    cout << aa.minSubArrayLen(5, obj) << "end";

    return 0; // 返回0表示程序成功结束
}
