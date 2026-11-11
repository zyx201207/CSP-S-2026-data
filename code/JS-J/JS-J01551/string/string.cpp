#include<bits/stdc++.h>
using namespace std;

int main()
{
    auto f_in = ifstream("./string.in", ios::in);
    auto f_out = ofstream("./string.out", ios::out);

    int n;
    f_in >> n;

    string s, line;
    int num;
    while ((f_in >>  num) && (f_in >> line))
    {
        for (size_t i = 0; i < num; i++)
        {
            s += line;
        }
        
    }

    int ans = 0;
    for (int l = 0, r = s.size() - 1;l < r;l++, r--)
    {
        if(s[l] != s[r])
        {
            ans++;
        }
    }

    f_out << ans;
    
    

    

    return 0;
}