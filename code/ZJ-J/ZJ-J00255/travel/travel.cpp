#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a,b,c,d;
    char s,t;
    cin >> a >> b >> s  >> c >> d >> t;
    if(a!=c)
    {
        cout << "0000";
    }
    else if(b!=d)
    {
        cout << "1000";
    }
    else if((s=='D' && t!='F') || (t=='D' && s!='F'))
    {
        cout << "1100";
    }
    else if((s=='A' && t=='C') || (s=='C' && t=='A'))
    {
        cout << "1110";
    }
    else cout << "1111";
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}