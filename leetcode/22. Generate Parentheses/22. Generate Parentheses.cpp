class Solution {
public:
    void sol(vector<string>&v,string curr,int o,int c,int max)
    {
        if(curr.length()==max*2)
        {
            v.push_back(curr);
            return ;
        }
        if(o<max)
            sol(v,curr+"(",o+1,c,max);
        if(c<o)
            sol(v,curr+")",o,c+1,max);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        sol(v,"",0,0,n);
        return v;
    }
};