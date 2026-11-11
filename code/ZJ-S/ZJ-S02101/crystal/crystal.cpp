#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
ll a[500005],s[500005],n,m;
bool check(ll x)
{
    for(ll i=1;i<=n-x+1;i++)
    {
        ll sum=a[i+x-1]*x-(s[i+x-1]-s[i-1]);
        if(sum<=m)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll ans;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    ll l=0,r=n;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
