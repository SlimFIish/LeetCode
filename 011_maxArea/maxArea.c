/*

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

注意：你不能倾斜容器，n 至少是2。

*/

/*解题思路：
注意点1：水不能超过两端两条线的低线，不能水会溢出
注意点2： 用left和right指针分别从两边往中间靠拢时，如left处比较短，则left到right的容积 肯定是left到其他所有边中最大的，
因为，（1）left到其他边的距离会缩短 （2）left到其他边的可盛水的高度受本身限制，所以，最高为height[left]，或者更低
故left这条边和其他边的组合最大为 与 right的组合。
*/

#define MIN(x, y) ((x) < (y) ? (x):(y))
#define MAX(x, y) ((x) > (y) ? (x):(y))

int maxArea(int* height, int heightSize) {
    int i, low, high, tmpV1, tmpV2, maxV = 0;
    if(!height || heightSize < 2)
        return 0;
    
    low = 0;
    high = heightSize-1;
   while(low < high){
       maxV = MAX(maxV, MIN(height[low], height[high])*(high-low));
       if(height[low] < height[high])
           low++;
       else
           high--;
   }
    
    return maxV;
}
