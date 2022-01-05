/*
문제 링크: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

Longest Increasing Subsequence
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:
Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence 0 2 6 9 13 15, which has length 6

Example 2:
Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence 5 7 9, with length 3

Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
0 ≤ A[i] ≤ 10^6
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    int lis(int n, const std::vector<int> &v)
    {
        // lis값을 tabulation(bottom-up)하기위해 사용하는 변수
        int l[n];
        for (int i = 0; i < n; i++)
        {
            l[i] = 1; // 최소 본인의 길이는 lis값이 될 수 있으므로 1로 초기화함
        }

        // tabulation!
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[i] > v[j] && l[i] < l[j] + 1)
                {
                    l[i] = l[j] + 1;
                }
            }
        }

        // lis의 max값을 반환
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            std::cout << "l[" << i << "] = " << l[i] << std::endl;
            if (l[i] > result)
            {
                result = l[i];
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60};
    // std::vector<int> input = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    // std::vector<int> input = {5, 8, 3, 7, 9, 1};

    Solution s;
    int result = s.lis(input.size(), input);
    std::cout << "Length of lis is " << result << std::endl;
    return 0;
}