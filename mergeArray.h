//合并两个有序数组：把数组2合并到数组1中
//	思路：由后向前，找出较大的放入数组1的末尾，好处是不用申请新的空间。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)
        {
            for(int i = 0;i <= n-1;i++)
            {
                nums1[i] = nums2[i];
            }
            //memcpy(&nums1,&nums2,sizeof(int) * n);
            return;
        }
        else if(n == 0)
        { return;}
        int num1_back = m + n -1;
        int num2_back = n -1;
        while(m-1 >= 0 && num2_back >= 0)
        {
            if(nums1[m-1] < nums2[num2_back])
            {
                nums1[num1_back] = nums2[num2_back];
                printf("%d",nums2[num2_back]);
                num2_back--;
                num1_back--;
            }
            else
            {
                nums1[num1_back] = nums1[m - 1];
                printf("%d",nums1[m -1]);
                m--;
                num1_back--;
            }
        }
        if(m-1 < 0 && num2_back >= 0)
        {
            for(int i = 0;i <= num2_back;i++)
            {
                nums1[i] = nums2[i];
            }
        }
    }
};