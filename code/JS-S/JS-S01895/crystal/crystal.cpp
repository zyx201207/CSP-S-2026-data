#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],sum[500005];
ll l,r,mid,ans;

bool check(ll x)
{
    for(int i=1;i<=n-x;i++)
        if(a[i+x-1]*x-sum[i+x-1]+sum[i-1]<=m)
            return true;
    return false;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    l=1,r=n;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}
