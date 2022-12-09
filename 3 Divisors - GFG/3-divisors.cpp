//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        
        vector<int>ans;
        
        
        for(int i = 0; i < query.size(); i++){
            
            long long n = query[i];
            long long temp = n;
            bool prime[n + 1];
            memset(prime, true, sizeof(prime));
         
            for (long long p = 2; p * p <= n; p++) {
                
                if (prime[p] == true) {
                    
                    for (long long i = p * p; i <= n; i += p)
                        prime[i] = false;
                }
            }
            
          
         int count = 0;
         for(long long i = 2; i <= n; i++)
         {
             if(prime[i]){
                 long long val = i*i;
                 if(val <= n)
                   
                        count++;
                        
             }
            
         }
         
         ans.push_back(count );
       
       }
    
     return ans;
  }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends