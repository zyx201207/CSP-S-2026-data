#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    string s = "";
    while(t--)
    {
        int x;
        string str;
        cin>>x>>str;
        while(x--)
        {
            s += str;
        }
    }
    int ans = 0;
    for(int i = 0;i < s.size() / 2;i++)
    {
        int other = s.size() - 1 - i;
        if(s[i] != s[other]) ans++;
    }
    cout<<ans;
    return 0;
}