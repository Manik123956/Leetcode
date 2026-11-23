class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int rem = 0;
        int sum = 0;
        int actualNum = x;
        while(x > 0){
            rem = x % 10;
            sum += rem;
            x = x / 10;
        }
        if(actualNum % sum == 0){
            return sum;
        }
        else{
            return -1;
        }
        
    }
};