#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
            // int temp = s[i];
            // s[i] = s[j];
            // s[j] = tmp;

            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
            //它不需要额外的变量
        }
    }
};