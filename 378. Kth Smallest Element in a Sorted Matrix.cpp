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

//using binary search- Time Complexity: O(nlognlog(max-min))
//finding middle element of matrix- then counting in every row, number of elements <= mid
//if that count<k => increment low, else decrement high
class Solution {
public:
   
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int counts=0;
        
        while(low<high){
            int mid=(low+high)/2;
            counts=0;
            for(int i=0;i<n;i++){
                int col=binsearch(matrix[i],mid);
                counts+=(col+1); //count of elements<=mid in current row
            }
            
            if(counts<k)
                low=mid+1;
            else
                high=mid;
            
        }
        return low;
    }
    
    int binsearch(vector<int> &matrix,int target){
        if(matrix[0]>target)
            return -1;
        int low=0;
        int high=matrix.size()-1;
        while(low<high){
            int mid=(low+high+1)/2;
            if(matrix[mid]<=target)
                low=mid;
            else
                high=mid-1;
        }
        return low;
    }
};
