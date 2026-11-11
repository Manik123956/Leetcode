class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        solve(1, k, n, current);
        return ans;
    }
    void solve(int start, int k, int n, vector<int>&current){
        if(current.size() == k){
            if(n == 0){
                ans.push_back(current);
            }
            return;
        }
        for(int i = start; i <= 9; i++){
            if(i > n) break;
            current.push_back(i);
            solve(i + 1, k, n - i, current);
            current.pop_back();
        }
    }
};