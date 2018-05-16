/*
Given a 32-bit signed integer, reverse digits of an integer.

给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21

注意:
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

/*If reversed integer overflows, then the length of ret and x must be the same*/
int reverse(int x) {
    int tmp, c, ret = 0;
    
    tmp = x;
    while(tmp){
        c = tmp%10;
        tmp = tmp/10;
        
        if(tmp == 0){
            if(x < 0){
                /*1. INT_MIN=–2147483648, ret=-2147483649*/
                if(ret < INT_MIN/10)
                    return 0;
                /*2. INT_MIN=–2147483648, ret=-3147483648*/
                else if(ret == INT_MIN/10){
                    if(c < INT_MIN%10)
                        return 0;
                }
            }else{
                /*3. INT_MAX=2147483647, ret=2147483648*/
                if(ret > INT_MAX/10)
                    return 0;
                /*4. INT_MAX=2147483647, ret=3147483647*/
                else if(ret == INT_MAX/10){
                    if(c > INT_MAX%10)
                        return 0;
                }
            } 
        }
        
        ret = 10*ret + c;
    }
    
    return ret;
}
