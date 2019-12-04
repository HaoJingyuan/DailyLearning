class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int src = 1;
        int des = 0;
        for(;src < nums.size();src++)
        {
            if(nums[src] != nums[des])
            {
                des++;
                nums[des] = nums[src];
            }
        }
        return ++des;
    }
};