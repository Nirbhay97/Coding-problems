//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isfine(int i, int j, int n, int m){
        if(i < 0 or i >= n or j >= m or j < 0)
            return false;
        return true;
    }
    
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        int ans = INT_MAX;
        queue<pair<int,int>>q;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 'X'){
                    q.push({i, j});
                    //dp[i][j] = 1;
                }
            }
        }
        
        int dx[4] = {-1, 0, 1, 0 };
        int dy[4] = {0, 1,  0,  -1};
    
    
        while( !q.empty() ){
            
            auto it = q.front();
            int ii = it.first;
            int jj = it.second;
            q.pop();
            
            for(int k = 0; k < 4; k++){
                int x = dx[k] + ii;
                int y = dy[k] + jj;
                if( isfine( x, y, n , m ) and dp[x][y] == 0 and grid[x][y] != 'X' ){
                    dp[x][y] = dp[ii][jj] + abs(ii - x) + abs(jj - y);
                    q.push({x, y});
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               // cout << dp[i][j] << " ";
               if(grid[i][j] == 'Y'){
                   ans = min(ans, dp[i][j]);
               }
            }
           // cout << endl;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends