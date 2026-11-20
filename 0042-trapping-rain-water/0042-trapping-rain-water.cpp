// this is the optimal approach with out extra space using two pointer approach.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0 , r = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while(l<r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]);
            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

// this is batter approach with extra space time complexity of this code o(n) and space complexity o(n)


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int>lmax(n,0);
//         vector<int>rmax(n,0);
//         lmax[0]=height[0];
//         rmax[n-1]=height[n-1];
//         for(int i=1 ; i<n ; i++){
//             lmax[i] = max(height[i],lmax[i-1]);
//         }
//         for(int i=n-2 ; i>=0 ; i--){
//             rmax[i] = max(height[i],rmax[i+1]);
//         }
//         int ans = 0;
//         for(int i=0 ; i<n ; i++){
//             ans += min(lmax[i],rmax[i]) - height[i];
//         }
//         return ans;
//     }
// };