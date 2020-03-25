class Solution {
public:
    
    long distance(vector<int>v)
    {
        int x=v[0];
        int y=v[1];
        return (x*x)+(y*y);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<long,vector<int>>> q;
        int x=0;
        for(int i=0;i<points.size();i++)
        {
            if(x<K)
            {
                long a=distance(points[i]);
                q.push(make_pair(a,points[i]));
            }
            else if(q.top().first>distance(points[i]))
            {
                q.pop();
                long a=distance(points[i]);
                q.push(make_pair(a,points[i]));
            }
            x++;
        }
        vector<vector<int>> ans;
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
