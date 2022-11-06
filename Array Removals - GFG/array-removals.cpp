//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        
        sort(arr.begin(), arr.end());
        
        // int i = 0;
         int n = arr.size();
        int ans = 0;
        vector<int>temp;
        
        for(int i = 0; i < n; i++){
            
            
            int c = 0;
            for(int j = n - 1; j >= i; j--){
                
                int diff = arr[j] - arr[i];
                if(diff > k) c++ ;
                else {
                    temp.push_back(c + i);
                    break;
                }
            }
        }
        
        return *min_element(temp.begin(), temp.end());
       
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends