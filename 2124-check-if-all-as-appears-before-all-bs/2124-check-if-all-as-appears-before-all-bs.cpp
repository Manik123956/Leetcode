class Solution {
public:
    bool checkString(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == s[i+1])
                continue;
            else if (s[i] == 'a' && s[i+1] == 'b')
                continue;
            else
                return false;
        }
        return true;
    }
};