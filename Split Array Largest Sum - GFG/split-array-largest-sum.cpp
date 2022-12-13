//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) {
        // code here
        
       
       int ans = 0;
       int l = *max_element(arr, arr + n);
       int h = accumulate(arr, arr + n, 0);
       
       while(l <= h){
           
           int mid = (l + h)/2;
           
           int count = 1;
           int s = 0;
           
           for(int i = 0; i <n; i++)
           {
               s += arr[i];
               
               if(s > mid) count++, s = arr[i];
           }
           
           
           if(count > k){
               
               l = mid + 1;
           }else{
                ans = mid;
                h = mid - 1;
           }
       }
       return ans;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends