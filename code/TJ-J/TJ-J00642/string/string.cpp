#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        string b;
        cin >> x >> b;
        for(int j=1;j<=x;j++)
        {
            s+=b;
        }
    }
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-i-1])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
