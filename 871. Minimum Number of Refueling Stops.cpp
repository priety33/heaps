class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops=0, fuel= 0, pos=startFuel, start=0;
        priority_queue<int> gas; 
        while(pos<target && fuel>=0) {
            if(start<stations.size() && stations[start][0]<=pos) {
                gas.push(stations[start][1]); start++; 
            }
            int p=target;
            if(start<stations.size()) p=min(p, stations[start][0]);
            while(fuel<p-pos && !gas.empty()) {
                fuel+= gas.top(); gas.pop();
                stops++;
            }
            if(fuel<p-pos) return -1;
            fuel= fuel-(p-pos); pos=p;
        }
        return (pos>=target)? stops : -1;
    }
};
