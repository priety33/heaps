//using heaps

class Solution {
public:
   
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int,queue<pair<int,int>>> m;
        priority_queue<int,vector<int>, greater<int>> q;
        m[matrix[0][0]].push(make_pair(0,0));
        q.push(matrix[0][0]);
        int a=q.top();
        while(!q.empty())
        {
            a=q.top();
            q.pop();
            k--;
            if(k==0) return a;
            pair p=m[a].front();
            m[a].pop();
            int x=p.first, y=p.second;
            if(y==0)
            {
                if(y+1 < matrix[x].size())
                {
                    q.push(matrix[x][y+1]);
                    m[matrix[x][y+1]].push(make_pair(x,y+1));
                }
                
                if(x+1 < matrix.size() )
                {
                    q.push(matrix[x+1][y]);
                    m[matrix[x+1][y]].push(make_pair(x+1,y));
                }
            }
            else 
            {
                if(y+1 < matrix[x].size())
                {
                    q.push(matrix[x][y+1]);
                    m[matrix[x][y+1]].push(make_pair(x,y+1));
                }
            }
        }
        return a;
    }
};

//using a vector
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> t;
    int len=0;
    for(int i=0;i<matrix.size();i++)
    {
       t.insert(t.end(),matrix[i].begin(),matrix[i].end());
    }
    sort(t.begin(),t.end());
    
    return t[k-1];
    }
};
