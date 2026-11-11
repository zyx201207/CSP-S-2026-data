#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005];
ll s[500005];
ll cst(ll l,ll r)
{
    return a[r]*(r-l)-(s[r-1]-s[l-1]);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=a[i]+s[i-1];
    }
    ll ans=1;
    for(ll i=1;i<=n-ans;i++)
    {
        for(ll j=n;j>=i+ans;j--)
        {
            if(cst(i,j)<=m)
            {
                ans=max(ans,j-i+1);
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
