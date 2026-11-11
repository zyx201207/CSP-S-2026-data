#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
void slove()
{
    ans+=c;
    t+=2049;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        solve(0);
    }
    cout<<ans;
    return 0;
}
