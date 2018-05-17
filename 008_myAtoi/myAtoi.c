/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.


实现 atoi，将字符串转为整数。

在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。

当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
若函数不能执行有效的转换，返回 0。

说明：
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31).

*/

//#define INT_MAX 2147483647
//#define INT_MIN (-INT_MAX-1)

int myAtoi(char* str) {
    int lenStr, i=0, j, sign=1;
    int ret = 0;
    
    if(!str || strlen(str)==0) return 0;

    lenStr = strlen(str);    
    while(i < lenStr && str[i] == ' ')
        i++;
    
    if(i < lenStr && str[i] == '-'){
        sign = -1;
        i++;
    }else if(i < lenStr && str[i] == '+'){
        i++;
    }
    
    for(j = i; j < lenStr; j++){
        if(str[j] >= '0' && str[j] <= '9'){
            if(ret < INT_MAX/10)
                ret = 10*ret + str[j]-'0';
            else if(ret > INT_MAX/10){
                return sign == -1 ? INT_MIN : INT_MAX;    
            }else if(ret == INT_MAX/10){
                if(sign == 1 && str[j] - '0' > INT_MAX%10)
                    return INT_MAX;
                else if(sign == -1 && str[j] - '0' > (INT_MAX%10+1)) // NOTE: can't use (INT_MAX+1)%10, for it will overflow
                    return INT_MIN;
                else
                    ret = 10*ret + str[j]-'0';
            }
            
        }else
            break;
            
        
    }
    
    return sign*ret;
}
