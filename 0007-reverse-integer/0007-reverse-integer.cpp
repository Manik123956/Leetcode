class Solution {
public:
    int reverse(int x) {
        int rem=0;
        long result=0;
        while(x != 0){
            rem=x%10;
            result=result*10+rem;
            x/=10;
        }
        if(result > INT_MAX || result < INT_MIN){
            return 0;
        }
        return result;
    }
};