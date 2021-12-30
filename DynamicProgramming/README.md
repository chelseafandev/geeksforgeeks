# Dynamic Programming

- [Dynamic Programming](#dynamic-programming)
  - [Longest Common Subsequence](#longest-common-subsequence)
    - [Solution](#solution)

<br>

## Longest Common Subsequence
우리는 Set1과 Set2에서 각각 하위 문제들의 중복과 최적화된 하위 구조의 특징에 대해 논의해보았습니다. 또한 Set3에서는 한가지 예제에 대해 이야기를 나누었습니다. 동적 프로그래밍을 사용하여 풀 수 있는 또 하나의 예제로서 Longest Common Subsequence(LCS)에 대해 알아보도록 하겠습니다.
> We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively. We also discussed one example problem in Set 3. Let us discuss Longest Common Subsequence (LCS) problem as one more example problem that can be solved using Dynamic Programming.

<br>

LCS는 주어진 두 개의 시퀀스에 모두 포함된 가장 긴 서브시퀀스의 길이를 찾는 문제입니다. 여기서 서브시퀀스란 연속적일 필요는 없으나 상대적으로 동일한 순서를 갖고 나타는 시퀀스를 의미합니다. 예를 들어, "abc", "abg", "bdf", "aeg", "acefg", .. 등은 "abcdefg"의 서브시퀀스입니다.
> LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

<br>

무식하게 풀기 접근법의 복잡성을 알아보기 위해 먼저 길이가 n인 문자열의 서브시퀀스가 될 수 있는 경우들의 수를 알아야하고, 1부터 n-1까지의 길이 갖는 서브시퀀스의 개수를 찾아야합니다. 1개의 요소를 갖는 조합의 숫자가 nC1이라고 했던 순열과 조합 이론을 다시한번 떠올려봅시다. 2개의 요소를 갖는 조합의 개수는 nC2이며 이러한 과정을 계속 이어나가게 됩니다. 우리는 nC0 + nC1 + nC2 + ... + nCn = 2n 이라는 것을 알고있습니다. 여기서 우리는 길이가 n인 문자열은 서로 다른 2n-1개의 서브시퀀스를 갖는다(길이가 0인 서브시퀀스는 고려하지 않기때문에)는 것을 알 수 있습니다. 이것은 무식하게 풀기 접근법의 시간복잡도는 O(n * 2^n)이라는 것을 말합니다. 서브시퀀스가 양쪽의 문자열에 모두 포함되는지를 확인하는데 O(n)의 시간이 걸리다는 것을 기억합시다. 동적 프로그래밍을 사용함으로써 이 시간복잡도를 개선할 수 있습니다.
> In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element are nC1. Number of combinations with 2 elements are nC2 and so forth and so on. We know that nC0 + nC1 + nC2 + … nCn = 2^n. So a string of length n has 2^n-1 different possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2^n). Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.

<br>

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.  
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.  

[소스로 이동](https://github.com/chelseafandev/geeksforgeeks/blob/main/DynamicProgramming/LongestCommonSubsequence.cpp)

<br>
  
### Solution

<br>

<details>
<summary>솔루션 보기</summary>
<div markdown="1">

이 문제에 대한 단순한 솔루션은 주어진 두개의 시퀀스의 모든 서브시퀀스를 생성하고 매칭되는 가장 긴 서브시퀀스를 찾는 것입니다. 이 솔루션은 지수 레벨의 시간복잡도를 갖습니다. 이 문제가 어떻게 동적 프로그래밍 문제의 중요한 특성 모두를 가지고 있는지를 살펴보도록 하겠습니다.
> The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem.

1) Optimal Substructure:
입력 시퀀스가 길이가 m인 X[0..m-1], 길이 n인 Y[0..n-1] 라고 해보겠습니다. 그리고 L(X[0..m-1], Y[0..n-1])은 시퀀스 X와 Y의 LCS의 길이를 나타냅니다. 이어지는 내용은 L(X[0..m-1], Y[0..n-1])의 재귀적인 정의에대한 것입니다.
> Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).

만약 두 시퀀스의 마지막 문자가 서로 매칭된다고 한다면 L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])이라고 할 수 있습니다.
> If last characters of both sequences match (or X[m-1] == Y[n-1]) then L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

만약 두 시퀀스의 마지막 문자가 서로 매칭되지 않는다고 하면 L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )이라고 할 수 있습니다.
> If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )

> Examples:
> 1) Consider the input strings “AGGTAB” and “GXTXAYB”. Last characters match for the strings. So length of LCS can be written as: L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”)
> 2) Consider the input strings “ABCDGH” and “AEDFHR. Last characters do not match for the strings. So length of LCS can be written as: L(“ABCDGH”, “AEDFHR”) = MAX ( L(“ABCDG”, “AEDFHR”), L(“ABCDGH”, “AEDFH”) )

그러므로 LCS 문제는 메인 문제가 서브 문제들의 솔루션으로 해결이 가능한 최적화된 하위구조 특성을 갖고 있습니다.
> So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.

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

위 코드의 재귀적인 접근 방식의 worst case의 시간복잡도는 O(2^n) 이며, worst case는 X와 Y가 서로 매칭되는 문자가 하나도 없는 경우에 발생합니다.
> Time complexity of the above naive recursive approach is O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.

위의 구현을 고려하여 입력 문자열이 "AXYT"와 "AYZX"라고 했을때 아래와 같은 부분 재귀 트리 형태를 생각해볼 수 있습니다.
> Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

```
                        lcs("AXYT", "AYZX")
                       /                 
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
```

위의 부분 재귀 트리를 보면, 동일한 lcs("AXY", "AYZ") 연산이 2번 있습니다. 우리가 만약 완전한 형태의 재귀 트리를 그려본다고 하면, 아주 많은 서브문제들이 동일한 연산을 반복하고 있다는 것을 볼 수 있을겁니다. 그래서 이 문제는 하위구조의 중복 특성이 있으며 동일한 서브문제들의 재연산은 Memoization(top down) 또는 Tabulation(bottom up)을 사용하여 피할 수 있습니다. 아래 코드는 Tabulation 방식으로 구현된 LCS 문제입니다.
> In the above partial recursion tree, lcs(“AXY”, “AYZ”) is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation. Following is a tabulated implementation for the LCS problem.

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

Tabulation 방식으로 구현된 위 코드의 시간복잡도느 O(mn)이고 이는 단순 재귀 구현의 worst case보다 훨씬 빠릅니다.
> Time Complexity of the above implementation is O(mn) which is much better than the worst-case time complexity of Naive Recursive implementation.

</div>
</details>

---