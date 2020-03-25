/*
Complexity Analysis

    Time complexity : O(n)O(n)O(n).

    Although the time complexity appears to be quadratic due to the while loop nested within the for loop,
    closer inspection reveals it to be linear. Because the while loop is reached only when currentNum marks
    the beginning of a sequence (i.e. currentNum-1 is not present in nums), the while loop can only run for 
    nnn iterations throughout the entire runtime of the algorithm. This means that despite looking like 
    O(n⋅n)O(n \cdot n)O(n⋅n) complexity, the nested loops actually run in O(n+n)=O(n)O(n + n) = O(n)O(n+n)=O(n) time.
    All other computations occur in constant time, so the overall runtime is linear.

    Space complexity : O(n)O(n)O(n).

    In order to set up O(1)O(1)O(1) containment lookups, we allocate linear space for a hash table to store the 
    O(n)O(n)O(n) numbers in nums. Other than that, the space complexity is identical to that of the brute force solution.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        
        map<int,bool> m;
        for(int i=0;i<n;i++) m[nums[i]]=true;
        
        int ans=0;
        for(auto i:m)
        {
            int len=1;
            int a=i.first;
            if(!m[a-1])
            {
                a++;
                while(m[a])
                {
                    len++;
                    a++;
                }
            }
            ans=max(ans,len);
        }
        
        return ans;
    }
};
