class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum=0;
        priority_queue<int> q;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            q.push(nums[i]);
        }
        vector<int> ans;
        int cursum=0;
        while(cursum <= sum-cursum)
        {
            ans.push_back(q.top());
            cursum+=q.top();
            q.pop();
        }
        return ans;
    }
};
