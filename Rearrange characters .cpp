//find the string containing no same adj chars.
//this can be done using heaps.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    unordered_map<char,int> freq;
	    priority_queue<pair<int,char>> q;
	    int maxfreq=0;
	    for(int i=0;i<s.length();i++) freq[s[i]]++;
	    for(auto i:freq) 
	    {
	        q.push({i.second, i.first});
	        maxfreq=max(maxfreq,i.second);
	    }
	    
	    string ans="";
	    pair<int,char> prev;
	    ans+=q.top().second;
	    prev={q.top().first-1, q.top().second};
	    q.pop();
	    while(!q.empty())
	    {
	        pair<char,int> p=q.top();
	        q.pop();
	        ans+=p.second;
	        if(prev.first>0) q.push(prev);
	        prev={p.first-1, p.second};
	    }
	    cout<<ans;
	}
	return 0;
}
