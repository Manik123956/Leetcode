class Solution {
public:
    bool checkValidString(string s) {
        stack<char>openSt;
        stack<char>asteriskSt;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                openSt.push(i);
            }
            else if(s[i] == '*'){
                asteriskSt.push(i);
            }
            else{
                if(!openSt.empty()){
                    openSt.pop();
                }
                else if(!asteriskSt.empty()){
                    asteriskSt.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!openSt.empty() && !asteriskSt.empty()){
            if(openSt.top() > asteriskSt.top()){
                return false;
            }
            openSt.pop();
            asteriskSt.pop();
        }
        return openSt.empty();
    }
};