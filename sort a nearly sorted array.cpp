//time com= O(nlogk)- using heaps

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    
	    for(int i=0;i<n;i++) cin>>a[i];
	    
	    priority_queue< int, vector<int>, greater<int>> q;
	    int i;
	    for(i=0;i<=k && i<n;i++) q.push(a[i]);
	    
	    int index=0;
	    while(!q.empty())
	    {
	        a[index]=q.top();
	        index++;
	        q.pop();
	        
	        if(i<n) q.push(a[i]);
	        i++;
	    }
	    
	    for(int i=0;i<n;i++) cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
