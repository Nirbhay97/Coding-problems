//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &ast) {
        // code here
        vector<int>ans;
        stack<int>st;
       
        int i = 0;
        while(i < n){
            
            if(i < n and st.empty()){
                st.push(ast[i]);
                i++;
            }else if(ast[i] < 0 and st.top() > 0){
                
                  int flag = false;
                  while(!st.empty() and (ast[i] < 0 and st.top() > 0)){
                    
                  if(abs(st.top()) < abs(ast[i])){
                      st.pop();
                  }else if(abs(st.top()) > abs(ast[i])){
                      flag = true;
                      break;
                  }else{
                      flag = true;
                      st.pop();
                      break;
                  }
                
            }
             
                if(!flag) st.push(ast[i]);
                i++;
                
            }else{
                st.push(ast[i]);
                i++;
            }
            
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
      // 3 4 -1 -2 -2 -2 3 4 5 3 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends