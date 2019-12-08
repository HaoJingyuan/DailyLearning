//两数之和
//思路：
	通过建立值与索引的哈希表实现快速查找
#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int,unsigned int> hash_table;
        for(int i = 0;i < nums.size();i++)
        {
            int result = target - nums[i];
            if(hash_table.count(result))
            {
                ret.push_back(hash_table[result]);
                ret.push_back(i);
                return ret;
            }
            hash_table.insert(pair<int,int>(nums[i],i));
        }
        return ret;
    }
};