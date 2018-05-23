/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。


*/

char* longestCommonPrefix(char** strs, int strsSize) {
    char *p = *strs;
    int i, j=0;
    
    if(!p) 
        return "";
    if(strsSize == 1) 
        return p;
    
    while(p[j] != '\0'){
        for(i = 1; i <= strsSize-1; i++){
            if(p[j] != strs[i][j]){
                p[j] = '\0';
                return p;
            }
        }
        j++;
    }
    
    return p;
}
