
//单队列代码如下：

/**

   * Definition for a binary tree node.
   * struct TreeNode {
   * int val;
   * TreeNode *left;
   * TreeNode *right;
   * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
   */

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


//双队列代码如下：

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