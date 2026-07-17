class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() - 1;
        int k = n;
        int i = 0;
        int sum = 0;
        while(i < k) {
            sum = numbers[i] + numbers[k];
            if(sum < target) {
                i++;
            }
            else if(sum > target) {
                k--;
            }else {
                return {i+1, k+1};
            } 
            
        }
        return {};
    }
};