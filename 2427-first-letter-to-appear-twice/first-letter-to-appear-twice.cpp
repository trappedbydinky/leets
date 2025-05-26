class Solution {
public:
    char repeatedCharacter(string s) {
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(str.find(s[i]) != string::npos) return s[i];
            else{
                str += s[i];
            }
        }
        return s[0];
    }
};