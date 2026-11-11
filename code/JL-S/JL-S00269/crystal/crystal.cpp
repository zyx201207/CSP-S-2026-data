#include <bits/stdc++.h>
using namespace std;
int n,ans=-1;
long long a[500005],sum[500005],pay,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=n,r=n;
    while(l>=1)
    {
        if(pay>m)
        {
            r--;
            pay=(r-l+1)*a[r]-(sum[r]-sum[l-1])*1LL;
            continue;
        }
        ans=max(ans,r-l+1);
        if(pay<=m)
        {
            l--;
            pay+=a[r]-a[l];
            continue;
        }

    }
    cout<<ans;
    return 0;
}
