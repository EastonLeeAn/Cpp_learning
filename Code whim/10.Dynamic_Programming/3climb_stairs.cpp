/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。*/
/*
我们来分析一下，动规五部曲：

定义一个一维数组来记录不同楼层的状态

确定dp数组以及下标的含义
dp[i]： 爬到第i层楼梯，有dp[i]种方法


首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。

还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。

*/
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

class climb1
{
public:
    int stairs(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};