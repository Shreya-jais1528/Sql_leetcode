class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int merged[2000];

        int i = 0;
        int j = 0;
        int k = 0;

        // Merge both sorted arrays
        while (i < m && j < n) {

            if (nums1[i] < nums2[j]) {
                merged[k] = nums1[i];
                i++;
                k++;
            }
            else {
                merged[k] = nums2[j];
                j++;
                k++;
            }
        }

        // Remaining elements of nums1
        while (i < m) {
            merged[k] = nums1[i];
            i++;
            k++;
        }

        // Remaining elements of nums2
        while (j < n) {
            merged[k] = nums2[j];
            j++;
            k++;
        }

        // Find median
        int total = m + n;

        if (total % 2 == 1) {
            return merged[total / 2];
        }
        else {
            return (merged[(total / 2) - 1] + merged[total / 2]) / 2.0;
        }
    }
};