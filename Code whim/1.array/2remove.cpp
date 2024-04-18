#include <iostream>
#include <vector>
using namespace std;

class remove
{
private:
    /* data */
public:
    int removeElement1(vector<int> &nums, int val /* args */)
    {
        int size = nums.size();//数组的大小 Size of array
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
            }
            i--;    
            size--;
            // ~2remove();
        }
        return 0;
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

    // Solution mm;

    // cout << mm.search(obj,3) << endl ;

    cout << "1";
    return 0; // 返回0表示程序成功结束
}
