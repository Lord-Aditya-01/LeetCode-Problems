class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        reverse(s.begin(), s.end());

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (index != 0) s[index++] = ' ';

                int j = i;
                while (j < n && s[j] != ' ')
                    s[index++] = s[j++];

                reverse(s.begin() + index - (j - i), s.begin() + index);

                i = j;
            }
        }

        s.resize(index);
        return s;
    }
};
