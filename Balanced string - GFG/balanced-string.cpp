//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
  
    bool even(int n){
        
        int ans = 0;
        while(n){
            int d = n % 10;
            ans += d;
            n /= 10;
        }
        
        if(ans % 2 == 0) return true;
        return false;
    }
    
    string BalancedString(int n) {
        // code here
        
        string s = "abcdefghijklmnopqrstuvwxyz";
        
        string ans = "";
        
        int rem = n % 26;
        
        int req = n / 26;
        
        for(int i = 0 ; i < req; i++)
            ans += s;
        
        if(rem == 0) return ans;
        
        if(n % 2){
            
            if(even(n)){
                
                string a = s.substr(0, (rem + 1)/2);
                string b = s.substr(26 - (rem - 1)/2);
                
                ans += a;
                ans += b;
            }else{
                
                string a = s.substr(0, (rem - 1)/2 );
                string b = s.substr(26 - (rem + 1)/2);
                
                ans += a;
                ans += b;
                
            }
        }else{
            
                string a = s.substr(0, rem/2);
                string b = s.substr(26 - rem/2);
                
                ans += a;
                ans += b;
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends