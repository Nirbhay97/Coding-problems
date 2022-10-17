class Solution {
public:
    bool checkIfPangram(string se) {
        
        int arr[26] = {1};
        
        for(int i = 0; i < 26; i++) arr[i] = 1;
        
        for(int i = 0; i < se.size(); i++){
            
            arr[se[i] - 'a']--;
            
        }
        
        for(int i = 0; i < 26; i++){
            
            if(arr[i] <= 0) continue;
            
            else return false;
        }
        
        return true;
    }
};