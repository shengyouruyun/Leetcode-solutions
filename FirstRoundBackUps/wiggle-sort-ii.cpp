class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)return;
        vector<int> aid=nums;
        int n=nums.size();
        sort(aid.begin(),aid.end());
        //åå¯¹å¶æ°çä½æ°å¡«åæ«å°¾çåç´ ï¼
        for(int i=1;i<n;i+=2){
            nums[i]=aid.back();
            aid.pop_back();
        }
        for(int i=0;i<n;i+=2){
            nums[i]=aid.back();
            aid.pop_back();
        }
    }
};