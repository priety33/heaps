/*
"1. Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group."
So for any two workers in the paid group,
we have wage[i] : wage[j] = quality[i] : quality[j]
So we have wage[i] : quality[i] = wage[j] : quality[j]
We pay wage to every worker in the group with the same ratio compared to his own quality.

"2. Every worker in the paid group must be paid at least their minimum wage expectation."
For every worker, he has an expected ratio of wage compared to his quality.

So to minimize the total wage, we want a small ratio.
So we sort all workers with their expected ratio, and pick up K first worker.
Now we have a minimum possible ratio for K worker and we their total quality.

As we pick up next worker with bigger ratio, we increase the ratio for whole group.
Meanwhile we remove a worker with highest quality so that we keep K workers in the group.
We calculate the current ratio * total quality = total wage for this group.

We redo the process and we can find the minimum total wage.
Because workers are sorted by ratio of wage/quality.
For every ratio, we find the minimum possible total quality of K workers.
*/

class Solution {
public:
    
    static bool compare(pair<int,int> a, pair<int,int> b) {
        return a.first/(double)a.second < b.first/(double)b.second;
    }
    
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
        int n=q.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) v.push_back({w[i], q[i]});
        sort(v.begin(), v.end(), compare);
        priority_queue<int> pq;
        double ans=INT_MAX;
        int sum=0;
        for(int i=0; i<n; i++) {
            sum+= v[i].second;
            pq.push(v[i].second);
            
            if(pq.size()>K) {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==K) ans=min(ans, sum*(v[i].first/(double)v[i].second));
        }
        return ans;
    }
};
