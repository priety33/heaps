class Solution {
public:
    
   vector<vector<int>> merge(vector<vector<int>>& v) {
       vector<vector<int>> ans;
       if(v.size()==0) return ans;
       priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
       for(int i=0;i<v.size();i++) q.push({v[i][0], v[i][1]});
       while(!q.empty())
       {
           pair<int,int> p= q.top();
           q.pop();
           int s=p.first, e=p.second;
           while(!q.empty() && q.top().first<=e)
           {
               e=max(e,q.top().second);
               q.pop();
           }
           ans.push_back({s,e});
       }
       return ans;
    }
};
