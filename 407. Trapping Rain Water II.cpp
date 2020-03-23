class Solution {
public:
    
    bool valid(int i, int j, int n, int m, int** visited)
    {
        return i>=0 && j>=0 && i<n && j<m && !visited[i][j];
    }
    
    int trapRainWater(vector<vector<int>>& h) {
        
        int n=h.size();
        if(n==0) return 0;
        int m=h[0].size();
        
        int** visited=new int*[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new int[m];
            for(int j=0;j<m;j++) visited[i][j]=0;
        }
        priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> >q; // < h[i][j] ,i ,j>
        
        //push initial boundary into queue, marking pushed elements as visited
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    q.push(make_tuple(h[i][j],i,j));
                    visited[i][j]=1;
                }
            }
        }
        
        int ans=0;
        while(!q.empty())
        {
            int ht=get<0>(q.top());
            int i=get<1>(q.top());
            int j=get<2>(q.top());
            q.pop();
            int r[]={-1,0,1,0};
            int c[]={0,-1,0,1};
            
            for(int k=0;k<4;k++)
            {
                if( valid(i+r[k],j+c[k],n,m,visited) )
                {
                    if( h[i+r[k]][j+c[k]] < ht )
                    {
                        ans+= ht-h[i+r[k]][j+c[k]];
                        
                        q.push(make_tuple(ht,i+r[k],j+c[k]));
                        visited[i+r[k]][j+c[k]]=1;
                    }
                    else
                    {
                        q.push(make_tuple(h[i+r[k]][j+c[k]],i+r[k],j+c[k]));
                        visited[i+r[k]][j+c[k]]=1;
                    }
                }
            }
        }
        return ans;
    }
    };
