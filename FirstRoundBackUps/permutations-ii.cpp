class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //å·ä¸ªæç¨stl
        vector<vector<int> > res;
        std::sort(nums.begin(),nums.end());
        do
        {
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};