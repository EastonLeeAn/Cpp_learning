/*
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，
且元素按顺时针顺序螺旋排列的正方形矩阵。
*/
/*
大家写二分法经常写乱，主要是因为对区间的定义没有想清楚，
区间的定义就是不变量。要在二分查找的过程中，保持不变量，就是在while
寻找中每一次边界的处理都要坚持根据区间的定义来操作，这就是循环不变量规则。*/

#include <iostream>
#include <vector>
using namespace std;

// ————————c++表示矩阵
/*
1.二维数组

const int ROWS = 3;
const int COLS = 3;
int matrix[ROWS][COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

2.向量的向量
std::vector<std::vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
*/

class generate
{
public:
    vector<vector<int>> Matrix(int n)
    {
        // 初始化initialize matrix
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        // 定义循环圈数
        int loop = n / 2;
        int mid = n / 2 ;
        // 需要一个offset
        int offset = 0;
        int i = 1;
        // 知道循环次数用for 循环，不知道循环次数 用 while
        for (loop; loop > 0; loop--)

        // 多谢了一个  int，相当于每次都定义
        //  for ( ------int-----loop; loop >= 0; loop--)
        {
            // printf (loop);

            while (starty < n - offset - 1)
            {

                matrix[startx][starty] = i;
                starty++;
                i++;
            }
            while (startx < n - offset - 1)
            {
                matrix[startx][starty] = i;
                startx++;
                i++;
            }
            while (starty > offset)
            {
                matrix[startx][starty] = i;
                starty--;
                i++;
            }
            while (startx > offset)
            {
                matrix[startx][starty] = i;
                startx--;
                i++;
            }
            startx++;
            starty++;
            // cout << starty << "1"<< endl;
            offset++;
            // n--;
        }

        // matrix[mid][mid] = i;
        if (n % 2 != 0)
        {
            matrix[mid][mid] = i;
            cout << mid << i << endl;
        }

        return matrix;
    }
};

int main()
{
    generate a;
    vector<vector<int>> aa = a.Matrix(7);

    for (size_t i = 0; i < aa.size(); ++i)
    {
        for (size_t j = 0; j < aa[i].size(); ++j)
        {
            std::cout << aa[i][j] << " ";
        }
        std::cout << std::endl; // 换行
    }
    // for (int loop = 4 / 2; loop > 0; loop--)
    // {
    //     printf("%d\n", loop);
    // }
    // int num = 10;
    // float fnum = 3.14;
    // printf("整数：%d,浮点数:%f\n", num, fnum);
    // return 0;
}
