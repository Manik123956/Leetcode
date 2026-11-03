class Solution {
public:
    bool EatingBananas(vector<int>& piles,int mid, int h){
        int actualHr = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            actualHr += piles[i] / mid;
            if(piles[i] % mid != 0){
                actualHr++;
            }
        }
        return actualHr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = low + (high - low) / 2;
            if(EatingBananas(piles , mid , h)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};