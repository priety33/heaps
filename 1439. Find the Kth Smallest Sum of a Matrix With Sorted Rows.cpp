/* without heaps also it will pass
  because k is small, we can come up with an easy solution, we calculate all the possible results row by row, 
  sort the result array, trim the result array to k size, the answer is the k-1 element */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> ans= mat[0];
        int m=mat.size();
        for(int i=1;i<m;i++)
        {
            vector<int> v;
            for(int j=0;j<mat[i].size();j++)
            {
                for(auto k: ans) v.push_back(mat[i][j]+k);
            }
            sort(v.begin(), v.end());
            ans.resize(min(k, (int)v.size())); // if k< v.size, there is no point considering sums greater than this
            for(int x=0; x<min(k, (int)v.size()); x++)
            {
                ans[x]=v[x];
            }
        }
        return ans[k-1];
    }
};

//heaps

