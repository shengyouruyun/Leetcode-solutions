```c++
class Solution {
public:
    int rangeBitwiseAnd(long long m, long long n) {
        long long ret = 0;
        long long gap = n - m;
        if(gap == 0)
            return m;
        long long bit = 1;
        for(int i = 0; i <= 31; i ++)
        {
            
            
            
           
            if(m&(1<<i)&& n&(1<<i) && (m+(1<<i)-1>=n)){
                ret |= bit;
            }
            
            bit <<= 1;
        }
        return ret;
    }
}
```