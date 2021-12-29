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

class Solution
{
public:
    int lcs(int x, int y, std::string s1, std::string s2)
    {
        
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