/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。
该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
也就是： F(0) = 0，F(1) = 1 F(n) = F(n - 1) + F(n - 2)，
其中 n > 1 给你n ，请计算 F(n) */
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
int fib(int N) {
        if (N <= 1) return N;
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};
class Solution1 {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

//递归写法
class Fibonacci1
{
private:
    /* data */
public:
 int fib(int N){
    if (N<2) return N;
    return fib (N-1) + fib (N-2); 
 }

};

int main(){
    Fibonacci1 a;
    cout<< a.fib(6);
}