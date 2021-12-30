/*
문제 링크: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

Longest Common Subsequence
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:
Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

Example 2:
Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.

Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=10^3
*/

#include <iostream>
#include <algorithm>

class Solution
{
public:
    int lcs(int s1_len, int s2_len, const std::string& s1, const std::string& s2)
    {
        // tabulation
        int lcs_result[s1_len + 1][s2_len + 1];

        for (int i = 0; i <= s1_len; i++)
        {
            for(int j = 0; j <= s2_len; j++)
            {
                if (i == 0 || j == 0)
                {
                    // 인덱스는 1부터 시작이므로 인덱스가 0인 경우는 예외 처리
                    lcs_result[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    lcs_result[i][j] = 1 + lcs_result[i - 1][j - 1];
                }
                else if (s1[i - 1] != s2[j - 1])
                {
                    lcs_result[i][j] = std::max(lcs_result[i - 1][j], lcs_result[i][j - 1]);
                }
            }
        }

        return lcs_result[s1_len][s2_len];
    }
};

int main()
{
    std::string s1 = "ABCDGH";
    std::string s2 = "AEDFHR";

    Solution s;
    std::cout << s.lcs(s1.length(), s2.length(), s1, s2) << std::endl;
    return 0;
}