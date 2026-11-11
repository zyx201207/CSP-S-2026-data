#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1,ans=0,us=0;
    while(r<=n)
    {
        if(us<=m) ans=max(ans,r-l+1);
        while(us>m)
            us-=(a[r]-a[l++]);
        r++;
        us+=(r-l)*(a[r]-a[r-1]);
    }
    cout<<ans<<'\n';
    return 0;
}
