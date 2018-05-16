/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)


将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R

之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:
string convert(string s, int numRows);

示例 1:
输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"

示例 2:
输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"

解释:
P     I    N
A   L S  I G
Y A   H R
P     I
*
*/

char* convert(char* s, int numRows) {
    if(!s) return NULL;
    if(strlen(s) <= numRows) return s;
    
    int i=0, j=0, c=0, len;
    char *p[numRows];
    
    len = strlen(s);
    for(i = 0; i < numRows; i++){
        p[i] = (char *)malloc(len+1);
        memset(p[i], 0x00, len+1);
    }
    
    while(c < len){
        i = 0;
        while(i >= 0 && i < numRows && c < len){
            p[i][strlen(p[i])] = s[c];
            i++;
            c++;
        }
        if(c >= len)
            break;
        
        i = numRows - 2;
        while(i > 0 && i < numRows-1 && c < len){
            p[i][strlen(p[i])] = s[c];
            i--;
            c++;
        }
        if(c >= len)
            break;
    }
    
    char *ret;
    ret = (char *)malloc(len + 1);
    memset(ret, 0x00, len + 1);
    for(i = 0; i < numRows; i++){
        strcat(ret, p[i]);
	free(p[i]);
    }
 	   
    return ret;
}
