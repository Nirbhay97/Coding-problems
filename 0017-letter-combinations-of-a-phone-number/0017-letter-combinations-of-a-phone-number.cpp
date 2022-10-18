class Solution {
public:
    
    void solve(vector<string>&ans, string temp, string alpha[], int ind, string digits){
        
        if(ind >= digits.length()){
            
            ans.push_back(temp);
            return;
        }
        
        int n = digits[ind] - '0';
        string s = alpha[n];
        
        for(int i = 0; i < s.size(); i++){
            
            temp.push_back(s[i]);
            solve(ans, temp, alpha, ind + 1, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        
        if(digits.size() == 0) return ans;
        string temp = "";
        
        string alpha[10] = {"", "", "abc","def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(ans, temp, alpha, 0, digits);
        
        return ans;
        
    }
};