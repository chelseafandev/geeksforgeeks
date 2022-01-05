# Dynamic Programming

- [Dynamic Programming](#dynamic-programming)
  - [Longest Common Subsequence](#longest-common-subsequence)
    - [Solution](#solution)
  - [Longest Increasing Subsequence](#longest-increasing-subsequence)
    - [Solution](#solution-1)
  - [Edit Distance](#edit-distance)
    - [Solution](#solution-2)

<br>

## Longest Common Subsequence
원문링크: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

<br>

우리는 [Set1](https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/)과 [Set2](https://www.geeksforgeeks.org/optimal-substructure-property-in-dynamic-programming-dp-2/)에서 각각 하위 문제들의 중복과 최적화된 하위 구조의 특징에 대해 논의해보았습니다. 또한 Set3에서는 한가지 예제에 대해 이야기를 나누었습니다. 동적 프로그래밍을 사용하여 풀 수 있는 또 하나의 예제로서 Longest Common Subsequence(LCS)에 대해 알아보도록 하겠습니다.
> We have discussed `Overlapping Subproblems` and `Optimal Substructure` properties in Set 1 and Set 2 respectively. We also discussed one example problem in Set 3. Let us discuss Longest Common Subsequence (LCS) problem as one more example problem that can be solved using Dynamic Programming.

<br>

LCS는 주어진 두 개의 시퀀스에 모두 포함된 가장 긴 서브시퀀스의 길이를 찾는 문제입니다. 여기서 서브시퀀스란 연속적일 필요는 없으나 상대적으로 동일한 순서를 갖고 나타는 시퀀스를 의미합니다. 예를 들어, "abc", "abg", "bdf", "aeg", "acefg", .. 등은 "abcdefg"의 서브시퀀스입니다.
> LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

<br>

무식하게 풀기 접근법의 복잡성을 알아보기 위해 먼저 길이가 n인 문자열의 서브시퀀스가 될 수 있는 경우들의 수를 알아야하고, 1부터 n-1까지의 길이 갖는 서브시퀀스의 개수를 찾아야합니다. 1개의 요소를 갖는 조합의 숫자가 <sub>n</sub>C<sub>1</sub>이라고 했던 순열과 조합 이론을 다시한번 떠올려봅시다. 2개의 요소를 갖는 조합의 개수는 <sub>n</sub>C<sub>2</sub>이며 이러한 과정을 계속 이어나가게 됩니다. 우리는 <sub>n</sub>C<sub>0</sub> + <sub>n</sub>C<sub>1</sub> + <sub>n</sub>C<sub>2</sub> + ... + <sub>n</sub>C<sub>n</sub> = 2<sup>n</sup> 이라는 것(이항정리)을 알고있습니다. 여기서 우리는 길이가 n인 문자열은 서로 다른 2<sup>n</sup>-1개의 서브시퀀스를 갖는다(길이가 0인 서브시퀀스는 고려하지 않기때문에)는 것을 알 수 있습니다. 이것은 무식하게 풀기 접근법의 시간복잡도는 O(n * 2<sup>n</sup>)이라는 것을 말합니다. 서브시퀀스가 양쪽의 문자열에 모두 포함되는지를 확인하는데 O(n)의 시간이 걸리다는 것을 기억합시다. 동적 프로그래밍을 사용함으로써 이 시간복잡도를 개선할 수 있습니다.
> In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element are <sub>n</sub>C<sub>1</sub>. Number of combinations with 2 elements are <sub>n</sub>C<sub>2</sub> and so forth and so on. We know that <sub>n</sub>C<sub>0</sub> + <sub>n</sub>C<sub>1</sub> + <sub>n</sub>C<sub>2</sub> + ... + <sub>n</sub>C<sub>n</sub> = 2<sup>n</sup>. So a string of length n has 2<sup>n</sup>-1 different possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2<sup>n</sup>). Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.

<br>

💭<B>순열이 아닌 조합인 이유는?</B>  
예를들어 시퀀스가 "ABCD"라고 가정해보겠습니다. 2개의 요소를 갖는 서브시퀀스의 경우의 수를 생각해보면 AB는 서브시퀀스가 가능하지만 BA는 서브시퀀스가 불가능(순서는 지켜야하므로)합니다. 즉, AB와 BA를 서로 다른 경우로 구분하는 순열이 아닌 AB와 BA를 동일하게 처리하는 조합으로 봐야하는 것입니다.

💭<B>서브시퀀스가 양쪽의 문자열에 모두 포함되는지를 확인하는데 O(n)의 시간이 걸리는 이유는?</B>  
주어진 두 문자열 X, Y의 길이가 각각 m, n 이라고 가정해보겠습니다. 서브시퀀스의 길이를 k(m > k, n > k)라고 한다면 문자열 X에 서브시퀀스가 포함되는지를 확인하기 위해서는 X[0 .. k-1], X[1 .. k], ... X[m-k, m-1] 즉, m - k + 1 번 반복해야합니다. 마찬가지로 문자열 Y에 대해서는 n - k + 1번 반복하게 됩니다. 그러므로 서브시퀀스가 양쪽의 문자열 X, Y에 모두 포함되는지를 확인하는데 걸리는 시간은 O(m - k + 1 + n - k + 1) = O(m + n - 2k + 2) = O(n)이 되는 것입니다.

<br>

Examples:
```diff
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.  
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.  
```

[소스로 이동](https://github.com/chelseafandev/geeksforgeeks/blob/main/DynamicProgramming/LongestCommonSubsequence.cpp)

<br>
  
### Solution

<br>

<details>
<summary>솔루션 보기</summary>
<div markdown="1">

<br>

이 문제에 대한 단순한 솔루션은 주어진 두개의 시퀀스의 모든 서브시퀀스를 생성하고 매칭되는 가장 긴 서브시퀀스를 찾는 것입니다. 이 솔루션은 지수 레벨의 시간복잡도를 갖습니다. 이 문제가 어떻게 동적 프로그래밍 문제의 중요한 특성 모두를 가지고 있는지를 살펴보도록 하겠습니다.
> The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem.

<br>

1) Optimal Substructure:  
입력 시퀀스가 길이가 m인 X[0..m-1], 길이 n인 Y[0..n-1] 라고 해보겠습니다. 그리고 L(X[0..m-1], Y[0..n-1])은 시퀀스 X와 Y의 LCS의 길이를 나타냅니다. 이어지는 내용은 L(X[0..m-1], Y[0..n-1])의 재귀적인 정의에대한 것입니다.
> Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).

<br>

만약 두 시퀀스의 마지막 문자가 서로 매칭된다고 한다면 L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])이라고 할 수 있습니다.
> If last characters of both sequences match (or X[m-1] == Y[n-1]) then L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

<br>

만약 두 시퀀스의 마지막 문자가 서로 매칭되지 않는다고 하면 L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )이라고 할 수 있습니다.
> If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )

> Examples:
> 1) Consider the input strings “AGGTAB” and “GXTXAYB”. Last characters match for the strings. So length of LCS can be written as: L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”)
> 2) Consider the input strings “ABCDGH” and “AEDFHR. Last characters do not match for the strings. So length of LCS can be written as: L(“ABCDGH”, “AEDFHR”) = MAX ( L(“ABCDG”, “AEDFHR”), L(“ABCDGH”, “AEDFH”) )

<br>

그러므로 LCS 문제는 메인 문제가 서브 문제들의 솔루션으로 해결이 가능한 최적화된 하위구조 특성을 갖고 있습니다.
> So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.

<br>

2) Overlapping Subproblems:  
아래 코드는 단순한 재귀 호출로 구현된 LCS 문제의 솔루션입니다. 구현 내용은 단순히 위에서 언급했던 재귀적인 구조를 따릅니다.
> Following is simple recursive implementation of the LCS problem. The implementation simply follows the recursive structure mentioned above.

```cpp
#include <iostream>
#include <algorithm>

int lcs (const char* X, const char* Y, int m, int n)
{
	if (m == 0 || n == 0)
    {
        return 0;
    }
		
	if (X[m-1] == Y[n-1])
    {
        return 1 + lcs(X, Y, m-1, n-1);
    }
	else
    {
        return std::max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
    }
}

int main()
{
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";

	int m = X.length();
	int n = Y.length();
	
	std::cout << "Length of LCS is "<< lcs(X.c_str(), Y.c_str(), m, n) << std::endl;
	return 0;
}
```

Output:
```diff
Length of LCS is 4
```

<br>

위 코드의 재귀적인 접근 방식의 worst case의 시간복잡도는 O(2<sup>n</sup>) 이며, worst case는 X와 Y가 서로 매칭되는 문자가 하나도 없는 경우에 발생합니다.
> Time complexity of the above naive recursive approach is O(2<sup>n</sup>) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.

<br>

위의 구현을 고려하여 입력 문자열이 "AXYT"와 "AYZX"라고 했을때 아래와 같은 부분 재귀 트리 형태를 생각해볼 수 있습니다.
> Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

```
                        lcs("AXYT", "AYZX")
                       /                 
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
```

<br>

위 트리를 보면, 동일한 lcs("AXY", "AYZ") 연산이 2번 있습니다. 우리가 만약 완전한 형태의 재귀 트리를 그려본다고 하면, 아주 많은 서브문제들이 동일한 연산을 반복하고 있다는 것을 볼 수 있을겁니다. 그러므로 이 문제는 하위구조의 중복 특성이 존재하며 동일한 서브문제들의 재연산은 Memoization(top down) 또는 Tabulation(bottom up)을 사용하여 피할 수 있습니다. 
> In the above partial recursion tree, lcs(“AXY”, “AYZ”) is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.

<br>

아래 코드는 Tabulation 방식으로 구현된 LCS 문제입니다.
> Following is a tabulated implementation for the LCS problem.
```cpp
#include <iostream>
#include <algorithm>

int lcs(const char *X, const char *Y, int m, int n)
{
    int L[m + 1][n + 1];

    // Following steps build L[m+1][n+1] in bottom up fashion. Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}

int main()
{
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";

    int m = X.length();
    int n = Y.length();

    std::cout << "Length of LCS is " << lcs(X.c_str(), Y.c_str(), m, n) << std::endl;

    return 0;
}
```

Output:
```diff
Length of LCS is 4
```

<br>

Tabulation 방식으로 구현된 위 코드의 시간복잡도느 O(mn)이고 이는 단순 재귀 구현의 worst case보다 훨씬 빠릅니다.
> Time Complexity of the above implementation is O(mn) which is much better than the worst-case time complexity of Naive Recursive implementation.

</div>
</details>

---

<br>
<br>

## Longest Increasing Subsequence
원문링크: https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

<br>

우리는 앞서 하위 문제들의 중복과 최적화된 하위 구조의 특징에대해 논의해보았습니다. 이제 동적 프로그래밍을 사용하여 풀 수 있는 또 하나의 예제로서 Longest Increasing Subsequence (LIS)에 대해 알아보도록 하겠습니다.
> We have already discussed `Overlapping Subproblems` and `Optimal Substructure` properties. Now, let us discuss the Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.

<br>

Longest Increasing Subsequence (LIS) 문제는 주어진 시퀀스에서 오름차순 형태로 정렬되는 모든 서브시퀀스들 중에서 가장 긴 서브시퀀스의 길이를 찾는것입니다. (LCS 문제와 동일하게 시퀀스 요소들의 순서는 그대로 유지해야함)
> The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 

<br>

Examples:
```diff
Input: arr[] = {3, 10, 2, 1, 20}
Output: Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output: Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
```

[소스로 이동](https://github.com/chelseafandev/geeksforgeeks/blob/main/DynamicProgramming/LongestIncreasingSubsequence.cpp)

<br>

### Solution

<br>

<details>
<summary>솔루션 보기</summary>
<div markdown="1">

<br>

Method1: Recursion  
arr[0..n-1]은 입력 배열이고 L(i)는 index i번째 까지의 LIS의 길이(즉, LIS의 마지막 요소가 arr[i]라는 의미)라고 해보겠습니다.
> Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.

<br>

그렇다면 L(i)는 아래와 같이 재귀적으로 작성할 수 있습니다.
> Then, L(i) can be recursively written as:
```diff
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists.
```

<br>

주어진 배열에서 LIS를 찾기 위해서는 max(L(i)) (0 < i < n ) 값을 반환해야합니다. index i번쨰까지의 LIS의 길이는 index i 이전까지의 인덱스들로 끝나는 모든 LIS의 최대값보다는 1이 더 큰 값이 될 것입니다. 단 이때 j < i이며, arr[j] < arr[i] 입니다. 그러므로 LIS 문제는 메인 문제가 서브 문제들의 솔루션으로 해결이 가능한 최적화된 하위구조 특성을 만족한다고 볼 수 있습니다.
> To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n. Formally, the length of the longest increasing subsequence ending at index i, will be 1 greater than the maximum of lengths of all longest increasing subsequences ending at indices before i, where arr[j] < arr[i] (j < i). Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.

<br>

아래있는 재귀 트리는 이 접근방식을 더욱 명확하게 만들어 줄 것입니다:
> The recursive tree given below will make the approach clearer:
```diff
Input  : arr[] = {3, 10, 2, 11}
f(i): Denotes LIS of subarray ending at index 'i'

(LIS(1)=1)

      f(4)  {f(4) = 1 + max(f(1), f(2), f(3))}
  /    |    \
f(1)  f(2)  f(3) {f(3) = 1, f(2) and f(1) are > f(3)}
       |      |  \
      f(1)  f(2)  f(1) {f(2) = 1 + max(f(1)}
              |
            f(1) {f(1) = 1}
```

<br>

아래 소스 코드는 재귀적인 접근 방식의 구현입니다.
> Below is the implementation of the recursive approach:
```cpp
#include <iostream>
#include <vector>

/*
To make use of recursive calls, this function must return two things:
1) Length of LIS ending with element arr[n-1]. We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with an element before arr[n-1] max_ref is used this purpose. The value of LIS of full array of size n is stored in *max_ref which is our final result
*/
int _lis(const std::vector<int>& v, int n, int *max_ref)
{
    // Base case
    if (n == 1)
    {
        return 1;
    }

    // 'max_ending_here' is length of LIS ending with v[n-1]
    int res, max_ending_here = 1;

    // Recursively get all LIS ending with v[0], v[1] ... v[n-2]. If v[i-1] is smaller than v[n-1], and max ending with v[n-1] needs to be updated, then update it
    for (int i = 1; i < n; i++)
    {
        res = _lis(v, i, max_ref);
        if (v[i - 1] < v[n - 1] && res + 1 > max_ending_here)
        {
            max_ending_here = res + 1;
        }   
    }

    // Compare max_ending_here with the overall max. And update the overall max if needed
    if (*max_ref < max_ending_here)
    {
        *max_ref = max_ending_here;
    }

    // Return length of LIS ending with v[n-1]
    return max_ending_here;
}

// The wrapper function for _lis()
int lis(const std::vector<int>& v, int n)
{
    // The max variable holds the result
    int max = 1;

    // The function _lis() stores its result in max
    _lis(v, n, &max);

    // returns max
    return max;
}

int main()
{
    std::vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60};
    std::cout << "Length of lis is " << lis(input, input.size()) << std::endl;
    return 0;
}
```

Output:
```diff
Length of lis is 5
```

<br>

Method2: Dynamic Programming  
위에서 살펴본 재귀적 솔루션은 동일한 해결 과정을 반복하는 수많은 하위문제들이 존재한다는 것을 알게됐습니다. 그러므로 이 문제는 하위구조의 중복 특성이 존재하며 동일한 서브문제들의 재연산은 Memoization(top down) 또는 Tabulation(bottom up)을 사용하여 피할 수 있습니다.
> We can see that there are many subproblems in the above recursive solution which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.

<br>

해당 접근 방식의 시뮬레이션은 이 사실을 명확히 해줍니다:
> The simulation of approach will make things clear:
```diff
Input  : arr[] = {3, 10, 2, 11}
LIS[] = {1, 1, 1, 1} (initially)

Iteration-wise simulation :
  1. arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1)=2}
  2. arr[3] < arr[1] {No change}
  3. arr[3] < arr[2] {No change}
  4. arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
  5. arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
  6. arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}
```

<br>

아래 소스 코드에서 처럼 tabulation을 사용하여 하위문제들의 재연산을 피할 수 있습니다.
> We can avoid recomputation of subproblems by using tabulation as shown in the below code: 
```cpp
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
    Solution s;
    int result = s.lis(input.size(), input);
    std::cout << "Length of lis is " << result << std::endl;
    return 0;
}
```

Output:
```diff
Length of lis is 5
```

</div>
</details>

---

<br>
<br>

## Edit Distance
원문링크: https://www.geeksforgeeks.org/edit-distance-dp-5/

<br>

> Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

> 1. Insert
> 2. Remove
> 3. Replace

>All of the above operations are of equal cost. 

Examples:
```diff
Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a
```

[소스로 이동](https://github.com/chelseafandev/geeksforgeeks/blob/main/DynamicProgramming/EditDistance.cpp)

<br>

### Solution

<br>

<details>
<summary>솔루션 보기</summary>
<div markdown="1">

<br>

<!-- contents -->


</div>
</details>

---
