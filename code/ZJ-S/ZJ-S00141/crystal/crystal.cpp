#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iny signed long long
constexpr int maxn=5e5+13;

ll n,m;
ll a[maxn];
ll sum[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int l=1,r=i;
        int pos=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int cnt=i-mid+1;
            if(1ll*cnt*a[i]-(sum[i]-sum[mid-1])<=m)
            {
                pos=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=max(ans,i-pos+1);
    }
    printf("%d\n",ans);

    return 0;
}

