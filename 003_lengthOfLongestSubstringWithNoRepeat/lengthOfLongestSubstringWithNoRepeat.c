/*
Given a string, find the length of the longest substring without repeating characters.

给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：
给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。

*/

int lengthOfLongestSubstring(char* s) {
    int len, maxLen = 0, curLen = 0;
    int start = 0, end;
    int i = 0;
    int cIdx[256] = {0}; /* The index which has been exist!*/
    
    if(!s) return 0;
    memset(cIdx, 0x00, sizeof(cIdx));
    
    len = strlen(s);
    while( i < len){
        if(cIdx[s[i]] == 0){
            cIdx[s[i]] = i+1;
            curLen++;
            maxLen = (maxLen < curLen ? curLen:maxLen);
        }else{
            end = cIdx[s[i]]-1 ;
            while(start <= end){
                cIdx[s[start]] = 0;
                start++;
                curLen--;
            }
            cIdx[s[i]] = i+1;
            curLen++;
        }
        i++;
    }
    return maxLen;
}
