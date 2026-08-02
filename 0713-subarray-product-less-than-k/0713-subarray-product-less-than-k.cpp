class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1;
        int n = nums.size();
        int left = 0;
        int count = 0;
        for(int r = 0 ; r < n ; r++){
            prod = prod*nums[r];
            while(prod >= k) {
                prod /= nums[left];
                left++;
            } 
            count += r - left + 1;
        }
        return count;
    }
};