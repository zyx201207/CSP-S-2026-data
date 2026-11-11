#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+10;
constexpr int INF=1e18;
int n,m,ans=1,a[maxn],sum[maxn];
bool check(int x,int y)
{
    int val=(y-x+1)*a[y]-(sum[y]-sum[x-1]);
    return val<=m;
}
int calc(int x)
{
    int l=1,r=x,ans=x;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid,x))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;++i)
    {
        int p=calc(i);
        ans=max(ans,i-p+1);
    }
    printf("%lld",ans);
    return 0;
}
