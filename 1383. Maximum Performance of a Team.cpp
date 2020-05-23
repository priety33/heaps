/*
Intuition

For a given efficiency, we pick all workers with the same or better efficiency. 
If the number of workers is greater than k, we pick k fastest workers.

Algorigthm

Sort workers based on their efficiency. 
Starting from the most efficient worker, compute and track the maximum performance. 
We can use a running sum to track all workers' speed.

When the amount of available workers exceeds k, remove the 'slowest' worker from sum. To do that, we can use a min heap.
*/

class Solution {
public:
    
    static bool compare(pair<int,int> a, pair<int,int> b) {
        return a.first>b.first;
    }
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({e[i],s[i]});
        sort(v.begin(), v.end(), compare);
        
        priority_queue<int, vector<int>, greater<int> > q;
        long sum=0, ans=0;
        for(int i=0; i<n; i++) {
            sum+= v[i].second;
            q.push(v[i].second);
            
            if(q.size()> k) {
                sum-=q.top();
                q.pop();
            }
            ans= max(ans, sum*v[i].first);
        }
        return ans % 1000000007;
    }
};
