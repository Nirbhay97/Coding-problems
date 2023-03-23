//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    int flag = false;
    int ans = INT_MIN;
    
    void dfs(Node* root, int target, int &first, int second){
        
        if(!root) return;
        if(!root->left and !root->right){
            if(root->data == target){
                flag = true;
                ans = max(ans, first);
                return;
            }
            second += root->data;
           // cout << second << endl;
            ans = max(ans, first - second);
            return;
        }
        
        if(root->data == target) flag = true;
        
        if(!flag){
            
            first += root->data;
            if(target > root->data)
                dfs(root->right, target, first, second);
            else 
                dfs(root->left, target, first, second);
            
        } 
        else{
            
            if(root->data != target) second += root->data;
            dfs(root->left, target, first, second);
            dfs(root->right, target, first, second);
            
        }
        
        return;
    }
    
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int first = 0, second = 0;
        dfs(root, target, first, second);
       //cout << first << " " << second << endl;
        if(!flag) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends