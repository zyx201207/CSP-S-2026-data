#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],b[500010],c[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0,l=1,r=1,sum=0;
    while(l<=r and r<=n)
    {
        r++;
        sum+=(r-l)*(a[r]-a[r-1]);
        if(sum<=m)
        {
            ans=max(ans,r-l+1);

        }else
        {
            while(sum>m)
            {
                sum-=(a[r]-a[l]);
                l++;
            }
        }

    }
    cout<<ans<<"\n";
    return 0;
}
