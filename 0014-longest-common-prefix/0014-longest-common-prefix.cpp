class Solution {
public:
    string common(string s1, string s2) {
        int n = min(s1.size(), s2.size());
        string ans = "";

        for(int i = 0 ; i  <n ; i++) {
            if(s1[i] == s2[i]) {
                ans += s1[i];
            } else {
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(int i = 1 ; i < strs.size() ; i++) {
            res = common(res, strs[i]);
        }
        return res;
    }
};