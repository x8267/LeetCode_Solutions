## Interview-17.16-The Masseuse LCCI

#### Problem

​		A popular masseuse receives a sequence of back-to-back appointment requests and is debating which ones to accept. She needs a break between appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appointment requests, find the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.

**Example 1:**

> Input:  [1,2,3,1]
> Output:  4
> Explanation:  Accept request 1 and 3, total minutes = 1 + 3 = 4

**Example 2:**

> Input:  [2,7,9,3,1]
> Output:  12
> Explanation:  Accept request 1, 3 and 5, total minutes = 2 + 9 + 1 = 12

**Example 3:**

> Input:  [2,1,4,5,3,1,1,3]
> Output:  12
> Explanation:  Accept request 1, 3, 5 and 8, total minutes = 2 + 4 + 3 + 3 = 12

#### 问题

​		一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

**示例 1：**

> 输入： [1,2,3,1]
> 输出： 4
> 解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。

**示例 2：**

> 输入： [2,7,9,3,1]
> 输出： 12
> 解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。

**示例 3：**

> 输入： [2,1,4,5,3,1,1,3]
> 输出： 12
> 解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。



本题可以利用动态规划的思路进行解题。

首先，我们用 1 和 0 表示是否接下本次预约，1 表示接下当前预约，0 表示不接当前预约；用dp[i][0] 表示不接第 i 次预约，dp[i][1] 表示接第 i 次预约。

题目要求我们找到最优的预约集合，假设当前是第 i 个预约，当前最大的预约时长可以从两个方面考虑，接下第 i 个预约或者不接第  i 个预约，当接下第 i 个预约时，因为题目要求不能接受相邻的预约，所以第 i-1 个预约一定是不能接的，那么，接下第 i 个预约的总预约时长为 dp[i][1] = dp[i-1][0] + num[i] ，而不接第 i 个预约时最大的总预约值为 dp[i][1] = max(dp[i-1][0], dp[i-1][1])。

我们可以发现，每次其实就是用 i-1 的总预约时长来计算第 i 次的预约时长，所以，我们可以用两个变量 dp1 和 dp0 来记录每次预约总和，然后计算下一次的预约时长。代码如下：

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int dp0 = 0, dp1 = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            int tdp0 = max(dp0, dp1);
            int tdp1 = dp0 + nums[i];
            dp0 = tdp0;
            dp1 = tdp1;
        }
        return max(dp0, dp1);
    }
};
```