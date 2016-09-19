void dfs(vector<vector<int>>&final, vector<int>&v, vector<int>&tmp, int cur, int sum,int target,int depth){
    if(sum==target){
        //è¿éåçå¾ç  
        vector<int> ans(tmp.begin(),tmp.begin()+depth);
        std::sort(ans.begin(),ans.end());
        final.push_back(ans);
        return;
    }else if(sum>target){
        return;
    }else{
        if(cur==v.size())return;
        tmp[depth]=v[cur];
        //éæ©è¿ä¸ªèç¹ï¼å¹¶ä¸ä¸ä¸ä¸ªè¿æ¯è¿ä¸ªèç¹
        dfs(final,v,tmp,cur,sum+v[cur],target,depth+1);
        
        //æèéæ©è¿ä¸ªèç¹ï¼ä¸ä¸ä¸ªæ¯ä¸ä¸ä¸ªèç¹
        dfs(final,v,tmp,cur+1,sum+v[cur],target,depth+1);
        
        //æèä¸éæ©è¿ä¸ªèç¹ï¼ä¸ä¸ä¸ªæ¯ä¸ä¸ä¸ªèç¹
        dfs(final,v,tmp,cur+1,sum,target,depth);
        
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> tmp(107);
        dfs(res,candidates,tmp,0,0,target,0);
        std::sort(res.begin(),res.end());
        auto new_end=unique(res.begin(),res.end());
        res.erase(new_end,res.end());
        return res;
    }
};