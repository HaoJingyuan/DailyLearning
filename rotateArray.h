旋转数组
三种思路：
1.依次旋转
注意事项：数组复制要从后往前复制，只需要保留最后面的元素，接下来向前一个一个复制即可
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
        {
            k -= nums.size();
        }
        for(int times = 0;times < k;times++)
        {
            int last = nums[nums.size() -1];
            for(int i = nums.size() - 2;i >= 0;i--)
            {
                nums[i + 1] = nums[i];
            }
            nums[0] = last;
        }    
    }
};

2.环状替代
一步到位，直接找最终的位置
注意事项：当n%k==O时，无法移动所有元素，比如6%2@会造成只会在0,2,4，中循环替换
		  索引增加后越界的判断
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
        {
            k -= nums.size();
        }
        int times = 0;
        int index = 0;
        int temp = 0;
        int last = nums[index];
        int des_index = 0;
        int start_index = index;
        while(times < nums.size())
        {
            des_index = index + k;
            if(des_index > nums.size() - 1)
            {
                des_index -= nums.size();
            }

            temp = nums[des_index];
            nums[des_index] = last;
            if(des_index == start_index)  //替换子路径是否构成了闭环，如果是则手动移动下一个要处理的元素
            {
                index = des_index + 1;
                if(index > nums.size() - 1)
                {
                    index -= nums.size();
                }
                last = nums[index];
                start_index = index;
            }
            else
            {
                last = temp;
                index = des_index;
            }
            times++;
        }
    }
};
想不到的情况太多，索引增加后一定要判断是否越界

3.旋转的旋转
【123456】--【654321】--【456321】-【456123】
void reverse(vector<int>& nums,int start,int end)
{
    int temp = 0;
    int front = start,back =end;
    while(front < back)
    {
        temp = nums[front];
        nums[front] = nums[back];
        nums[back] = temp;
        front++;
        back--;
    }
}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
        {
            k -= nums.size();
        }
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};