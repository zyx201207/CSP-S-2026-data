#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char a;
        cin >> x >> a;
        for(int j=0;j<x;j++)
        {
            s=s+a;
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        int root=i+1;
        if(s[i]!=s[s.size()-root]) ans++;
    }
    cout << ans << endl;

    return 0;
}