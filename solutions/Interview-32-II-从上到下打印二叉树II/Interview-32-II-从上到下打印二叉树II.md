Interview-32-II-从上到下打印二叉树II

#### 问题

​	从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

**示例 1：**

> 例如:
> 给定二叉树: `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
>
> 返回其层次遍历结果：
>
> ```
> [
>   [3],
>   [9,20],
>   [15,7]
> ]
> ```



**思路：**

本题为**二叉树的广度优先搜索**，可以借助**队列**进行解题，可以使用**单队列**也可以使用**双队列**。

使用单队列解题，用一个队列存储每一层的节点，利用队列先进先出的特性，依次遍历每一层节点，将节点存储容器中，如果该节点存在子节点，将子节点压入队列，直到本层节点全部取出，再对下一层节点进行输出。

单队列代码如下：



```c++
/**

   * Definition for a binary tree node.
   * struct TreeNode {
   * int val;
   * TreeNode *left;
   * TreeNode *right;
   * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
     */

**/
  class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()){
            int qlen = que.size();
            vector<int> vtemp;
            while(qlen--){
                TreeNode* treetemp = que.front();
                que.pop();
                vtemp.push_back(treetemp -> val);
                if (treetemp -> left != NULL)
                    que.push(treetemp -> left);
                if (treetemp -> right != NULL)
                    que.push(treetemp -> right);
                

            }
            ans.push_back(vtemp);
        }
        return ans;

    }
  };
```



使用双队列解题，用两个队列存储，一个队列存储当前层的节点，另一个队列存储下一层的节点。

依次遍历当前层节点队列中的元素，将其存入一个容器中，然后将其子节点存入另一个队列中，直至本队列中元素全部遍历，然后遍历另一个队列。

双队列代码如下：

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> temp1;
        queue<TreeNode*> temp2;
        temp1.push(root);
        while (!temp1.empty() || !temp2.empty()){
            vector<int> vtemp;
            if(!temp1.empty()){
                while(!temp1.empty()){
                    TreeNode* treetemp = temp1.front();
                    temp1.pop();
                    vtemp.push_back(treetemp -> val);
                    if (treetemp -> left != NULL)
                        temp2.push(treetemp -> left);
                    if (treetemp -> right != NULL)
                        temp2.push(treetemp -> right);
                }
                
            }
            else if (!temp2.empty()){
                while(!temp2.empty()){
                    TreeNode* treetemp = temp2.front();
                    temp2.pop();
                    vtemp.push_back(treetemp -> val);
                    if (treetemp -> left != NULL)
                        temp1.push(treetemp -> left);
                    if (treetemp -> right != NULL)
                        temp1.push(treetemp -> right);
                }
            }
            ans.push_back(vtemp);
        }
        return ans;
    }
};
```