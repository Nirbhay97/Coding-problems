//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool fine(int x, int y,vector<vector<int>> &visited,vector<vector<int>> &grid, int n, int m){
        
        if(x >= n or x < 0 or y < 0 or y >= m or grid[x][y] == 0  or visited[x][y] == 1 ) return false;
        visited[x][y] = 1;
         return true;
    }
    
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> des) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n + 1, vector<int>(m + 1, 0));
        
        queue<pair<int,int>>q;
        
        int sourcex = source.first;
        int sourcey = source.second;
        
        q.push(make_pair(sourcex, sourcey));
        
        int ans = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                
                auto t = q.front();
                int x = t.first;
                int y = t.second;
                
                q.pop();
            
                
                if(x == des.first and y == des.second) return ans;
                
                if(fine(x + 1,y,visited,grid, n, m)) q.push(make_pair(x + 1, y));
                if(fine(x - 1,y,visited,grid, n, m)) q.push(make_pair(x - 1, y));
                if(fine(x,y + 1,visited,grid, n, m)) q.push(make_pair(x , y + 1));
                if(fine(x,y - 1,visited,grid, n, m)) q.push(make_pair(x , y - 1));
                
            }
            
            ans++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends