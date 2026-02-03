class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int check=0;
        int check2=0;
        map <char,char> mpp;
        mpp={
            {']','['},
            {')','('},
            {'}','{'}
        };
        int n=s.size();
        //base case
        if(n<2)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('|| s[i]=='{' || s[i]=='[')
            {   check2++;
                st.push(s[i]);
            }
            else
            {   check++;    //has closing bracket
               if(st.empty() || st.top()!=mpp[s[i]]) 
                    {return false;}
                else
                {
                    st.pop();
                }
            }

        }
        if(check!=0 && check==check2)
            return true;
        else
            return false;
    }
};
