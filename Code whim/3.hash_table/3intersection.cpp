#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (nums_set.find(num) != nums_set.end()) //
                                                      /*//nums_set.find(num) 函数会在集合中查找值为 num 的元素，
                                                      并返回一个迭代器。如果找到了该元素，
                                                      则返回指向该元素的迭代器；如果找不到，则返回 nums_set.end()，表示未找到。
                                                      */
            {
                result_set.insert(num);
            }
            return vector<int>(result_set.begin(), result_set.end());
        }
    } // 这种用法对于从一个容器中去重并创建一个不包含重复元素的集合非常有用。
};

/*
那有同学可能问了，遇到哈希问题我直接都用set不就得了，用什么数组啊。

直接使用set 不仅占用空间比数组大，而且速度要比数组慢，

set把数值映射到key上都要做hash计算的。

不要小瞧 这个耗时，在数据量大的情况，差距是很明显的。*/

class Solution1
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        int hash[1005] = {0};          // 默认数值为0
        for (int num : nums1)
        { // nums1中出现的字母在hash数组中做记录
            hash[num] = 1;
        }
        for (int num : nums2)
        { // nums2中出现话，result记录
            if (hash[num] == 1)
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main()
{
    // 声明一个 unordered_set<int> 类型的集合
    std::unordered_set<int> result_set;

    // 插入一些元素
    result_set.insert(5);
    result_set.insert(10);
    result_set.insert(20);

    // 查找元素并输出结果
    std::cout << "Checking if 10 is in the set: ";
    if (result_set.find(10) != result_set.end())
    {
        std::cout << "Found" << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }

    // 遍历集合并输出元素
    std::cout << "Elements in the set: ";
    for (int num : result_set)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 删除一个元素并重新输出集合
    result_set.erase(10);
    std::cout << "Elements in the set after erasing 10: ";
    for (int num : result_set)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
