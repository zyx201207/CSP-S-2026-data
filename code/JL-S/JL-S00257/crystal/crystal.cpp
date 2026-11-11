#include <bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int ans=-1e9;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=i+1;
        if(1ll*i*a[i]<=sum[i]+m)
        {
            ans=i;
            continue;
        }
        while(l+1<r)
        {
            int mid=(l+r)>>1;
            if(1ll*(i-mid+1)*a[i]<=sum[i]-sum[mid-1]+m)
                r=mid;
            else
                l=mid;
        }
        ans=max(ans,i-r+1);
    }
    printf("%d\n",ans);
    return 0;
}
