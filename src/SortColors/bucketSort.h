/*
* https://leetcode.com/problems/sort-colors/
* bucket sort implementation sort array in O(n) time
* based on NeetCode explanation https://www.youtube.com/watch?v=4xbWSRZHqac
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::map<int, int> bucket;
        for(int elements : nums)
        {
          bucket[elements]++;
        }
        int prevIndex = 0;
        for(auto elements: bucket)
        {
          int curIndex=prevIndex;
          int end = prevIndex+elements.second;
          while(curIndex < end)
          {
            nums[curIndex] = elements.first;
            curIndex++;
          }
          prevIndex=curIndex;
        }
    }
};