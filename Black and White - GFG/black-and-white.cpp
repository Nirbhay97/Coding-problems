//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
int mod = 1e9 + 7;

int dy[8] = {2,2,-1,1,-2,2,-1,1};
int dx[8] = {-1,1,-2,-2,-1,-1,2,2};

void solve(int x, int y,int r, int c, long long &ans){
    
   
    int count = 0;
    for(int i = 0; i < 8; i++){
        
        int X = dx[i] + x;
        int Y = dy[i] + y;
        
        if(X >= 0 and X < r and X != x and Y >= 0 and Y  < c and Y != c ){
            count++;
        }
    }
    
    ans += (r*c - 1 - count) % mod;
    
    return;
    
    
}

long long numOfWays(int n, int m)
{
    long long res = 0;
   // vector<vector<int>>mat(n, vector<int>(m,0));
    
    for(int i = 0; i < n; i++){
        
        for(int j= 0; j < m; j++){
            
            long long ans = 0;
            solve(i,j,n, m, ans);
            res += ans % mod;
        }
    }
    
    
    return res % mod;
    
    // write code here
}