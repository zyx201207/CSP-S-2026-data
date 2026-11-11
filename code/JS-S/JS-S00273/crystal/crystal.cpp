#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,m,ans=-9e18;
int bs(int x)
{
    int l=1,r=x,mid;
    while(l<r)
    {
        mid=l+((r-l)>>1);
        if((x-mid+1)*(a[x]-a[x-1])-(a[x]-a[mid-1])<=m)
        {
            r=mid;
        }
        else l=mid+1;
    }
    return l;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int pos=bs(i);
        ans=max(ans,i-pos+1);
    }
    printf("%lld\n",ans);
    return 0;
}
