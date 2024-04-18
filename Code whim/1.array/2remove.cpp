#include <iostream>
#include <vector>
using namespace std;

class vemove
{
private:
    /* data */
public:
    int removeElement1(vector<int> &nums, int val /* args */)
    {
        int size = nums.size();        // 数组的大小 Size of array
        for (int i = 0; i < size; i++) // 遍历数组 Go through the groups
        {
            if (nums[i] == val) // 找到要的元素 Find the desired element
            {
                for (int j = i + 1; j < size; j++) // 更新数组 Update array
                {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }

            // ~2remove();
            // cout <<
        }
        return size;
    }

    int removeElement2(vector<int> &nums, int val)
    {
        int size = nums.size();
        // fast and low pointers
        int fast = 0;
        int slow = 0;
        while (fast < size)
        {
            if (nums[fast] != val)//注意 考虑是 等 还是 不等
            //等的情况 和  不等的情况
            {
                nums[slow] = nums[fast];

                // fast++; 
                slow++; //slow 有条件的加
            }

            fast ++;//错误，fast 怎么可能在以一个循环里面多加几次
            //fast 肯定是一直加

        }

        return slow;
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
    for (int num : obj)
    {
        cout << num << " ";
    }

    // return 0;
    cout << endl;
    // Solution mm;
    vemove aa;
    cout << aa.removeElement2(obj, 2) << endl;

    // cout << mm.search(obj,3) << endl ;

    cout << "1";
    return 0; // 返回0表示程序成功结束
}
