class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return {{}};
        vector<vector<int>> ans;
        ans.push_back({});  //首先将输出结果中插入一个空集
        //遍历nums中每一个元素，将其与ans中集合组合
        for (int i = 0; i < nums.size(); ++i){
            int anssize = ans.size();
            //将nums中位置为i的元素与ans中每一个集合组合
            for (int j = 0; j < anssize; ++j){
                vector<int> veci(ans[j]); 
                veci.push_back(nums[i]);
                ans.push_back(veci);
            }
        }
        return ans;
    }
};