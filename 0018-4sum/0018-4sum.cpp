class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>>s;
        vector<vector<int>>ans;
        
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        
        vector<int>v;
        
        for(int i = 0; i < nums.size() - 4  + 1; i++){  
            
            for(int  j = i + 1; j < nums.size() - 3 + 1; j++){
                
                int k = j + 1;
                int l = nums.size() - 1;
                long long req =(long long) target - (long long)(nums[i] + nums[j]);
                
                while(k < l){
                    
                    long long sum = nums[k] + nums[l];
                    
                    if(sum == req){
                        
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[l]);
                        s.insert(v);
                        v.clear();
                        k++;
                        l--;
                        
                    }else if(sum < req) k++;
                     else l--;
                }
            }
        }
    
        
        for(auto it: s) ans.push_back(it);
        return ans;
    }
};