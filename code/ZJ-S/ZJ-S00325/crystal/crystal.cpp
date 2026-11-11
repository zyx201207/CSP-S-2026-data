#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;
int a[maxn],sum[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0;
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
    int l=1,r=1;
    for(;r<=n;++r)
    {
        while(l<r&&(r-l+1)*a[r]-(sum[r]-sum[l-1])>m)
        {
            ++l;
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
    return 0;
}