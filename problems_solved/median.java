// 4. Median of Two Sorted Arrays
// Hard
// Topics
// premium lock icon
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

//solution

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int z = m+n;
        int p1, p2,k=0,l=0;
        for(int i=0;i<(z/2)+1;i++){
            p2 = p1;
            if(k<m&&l<n){//both are not empty or over
                if(nums1[k]>)
            }
        }

        //odd case
        if (z%2==1){
            
        }

    }
}