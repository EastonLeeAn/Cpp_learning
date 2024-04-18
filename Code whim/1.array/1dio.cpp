// 版本二
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right)
        { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target)
            {
                right = middle; // target 在左区间，在[left, middle)中
            }
            else if (nums[middle] < target)
            {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            }
            else
            {                  // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};

int main()
{
    // 在这里编写你的代码
    vector<int> obj;
    for (int i = 0; i < 10; ++i)
    {
        obj.push_back(i); // 将 i 添加到 obj 中
    }
    cout << obj[5] << endl;

    // return 0;

    Solution mm;
    
    cout << mm.search(obj,3) << endl ;

    cout << "1";
    return 0; // 返回0表示程序成功结束
}
