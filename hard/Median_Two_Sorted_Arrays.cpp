/*
Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        size_t i = 0 , j = 0;
        vector<int> merege;
        merege.reserve(nums1.size() + nums2.size());
        double mid;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merege.push_back(nums1[i++]);
            }
            else
            {
                merege.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size())
            merege.push_back(nums1[i++]);
        while (j < nums2.size())
            merege.push_back(nums2[j++]);
  
        if (merege.size() % 2 == 0)
        {
            mid = merege[merege.size() / 2] + merege[(merege.size() / 2) - 1];
            mid /= 2;
        }
        else
            mid = merege[merege.size() / 2];

        return mid;
    }

};

int main()
{
    Solution s;

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,7,8,9,10,11,12,13,14,15,16,17};

    cout << s.findMedianSortedArrays(v1,v2) << endl;

    return 0;
}