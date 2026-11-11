#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],d[500005];
bool check(ll x)
{
    ll minn=1e18;
    for(int i = 1;i <= n-x+1;++i) minn=min(minn,x*a[i+x-1]-(d[i+x-1]-d[i-1]));
    if(minn<=m) return 1;
    else return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    d[0]=0;
    for(int i = 1;i <= n;++i)
    {
        d[i]=d[i-1]+a[i];
    }
    ll l=1,r=n,ans=1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
