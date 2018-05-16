/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/

/*Method1: A better answer from Leetcode submission record*/
char* longestPalindrome(char* s) 
{
    int i, left, right, lenS, maxLen=1, start=0;
    char *ret;
    
    if(!s) return NULL;
    if(strlen(s) <= 1) return s;
    
    lenS = strlen(s);
    for(i = 0; i < lenS-1;){
        if(lenS-i <= maxLen/2)
            break;
        
        left = right = i;

	/*1. find the rightest same element, exclude odd or even symmetry problems */
        while(right < lenS-1 && s[right] == s[right+1])
            right++;

        /*2. next start from right+1, because length of Palindrome from i+1 will never larger than right*/
        i = right+1;
	
	/*3. find the Palindrome, and move left and right pointer*/        
        while(right > 0 && right < lenS-1 && s[left-1]==s[right+1]){
            left--;
            right++;
        }
        
        if(right-left+1 > maxLen){
            maxLen = right-left+1;
            start = left;
        }
    }
    
    ret = (char*)malloc(maxLen+1);
    strncpy(ret, s+start, maxLen);
    ret[maxLen] = '\0';
    return ret;
}

