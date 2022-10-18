class Solution {
public:
    string countAndSay(int n) {
        
         if(n == 1) return "1";
        if(n == 2) return "11";
        
        string ans = "11";
        
        for(int i = 3; i <= n; i++){
            
            ans = ans.append("#"); // also can use push_back()
            int c = 1;
            string s = "";
            
            for(int j = 1; j < ans.length(); j++){
                 if(ans[j] != ans[j-1]){
                     s = s + to_string(c);
                     s = s + ans[j-1];
                     c = 1;
                 }
                else c++;
            }
            
            ans = s;
        }
        
        return ans;
    }
};