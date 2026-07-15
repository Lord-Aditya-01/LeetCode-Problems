class Solution {
public:
    void heapifyMax(vector<int>& nums, int n, int i) {
        int largest = i;      
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapifyMax(nums, n, largest);
        }
    }

    void heapSortAscending(vector<int>& nums, int n) {
        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyMax(nums, n, i);

        // Extract elements
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapifyMax(nums, i, 0);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        heapSortAscending(nums, nums.size());
        return nums[nums.size() - k]; 
    }
};