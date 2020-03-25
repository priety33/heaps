class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans=0;
        int n=stations.size();
        if(n==0)
        {
            if(startFuel<target) return -1;
            else return ans;
        }
        int f=startFuel;
        priority_queue<int> q;
        if(f<stations[0][0]) return -1;
        int i=0;
        int dist=stations[0][0];
        for(i=0;i<stations.size()-1;i++)
        {
            q.push(stations[i][1]);
            f=f-(dist);
            dist=stations[i+1][0]-stations[i][0];
            if(f>= target-stations[i][0]) return ans;
            if(f<dist) //because i+1 can go out of bound create another loop outside this for last element of array
            {
                while(!q.empty() && f<dist)
                {
                    f=f+q.top();
                    q.pop();
                    ans++;
                }
                if(q.empty() && f<dist) return -1;
            }
        }
        
        //last station
        q.push(stations[i][1]);
        f=f-dist;
        if(f>=target-stations[i][0]) return ans;
        else
            {
                while(!q.empty() && f<target-stations[i][0])
                {
                    f=f+q.top();
                    q.pop();
                    ans++;
                }
                if(q.empty() && f<target-stations[i][0]) return -1;
            }
        return ans;
    }
};
