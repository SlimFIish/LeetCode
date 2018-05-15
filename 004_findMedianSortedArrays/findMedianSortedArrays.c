/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n))


给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

示例 1:
nums1 = [1, 3]
nums2 = [2]
中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
中位数是 (2 + 3)/2 = 2.5
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, cnt = 0, flag, num, tmp, mid, mid1;
    double ret;
    
    flag = (nums1Size+nums2Size)%2;
    num = (nums1Size+nums2Size)/2+1;
    
    while(cnt < num){
        if(i < nums1Size && j < nums2Size){
            tmp = nums1[i]<nums2[j]?nums1[i]:nums2[j];
            if(tmp == nums1[i])
                i++;
            else
                j++;
        }
        else if(i >= nums1Size)
            tmp = nums2[j++];   
        else
            tmp = nums1[i++];

        cnt++;
        if((flag == 0) && (cnt == num-1))
            mid1 = tmp;
    }
    mid = tmp;
    
    if(flag == 0)
        ret = ((double)mid1+(double)mid)/2;
    else
        ret = mid;
    return ret;
}
