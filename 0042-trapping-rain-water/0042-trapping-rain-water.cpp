class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int water = 0, leftmax = height[left], rightmax = height[right];

        while(left < right) {
            if(leftmax < rightmax) {
                left++;
                leftmax = max(leftmax, height[left]);
                water += leftmax - height[left];
            }
            else {
                right--;
                rightmax = max(rightmax, height[right]);
                water += rightmax - height[right];
            }
        }    
        return water;
    }
};