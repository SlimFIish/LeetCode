/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j,find=0;
    int *ret;
    
    if(!nums)
        return NULL;
    
    for(i = 0; i < numsSize-1; i++){
        for(j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                find = 1;
                break;
            }
        }
        if(find)
            break;
    }
    
    if(find){
        ret = (int *)malloc(2*sizeof(int));
        ret[0] = i;
        ret[1] = j;
        return ret;
    }
    return NULL;
}
