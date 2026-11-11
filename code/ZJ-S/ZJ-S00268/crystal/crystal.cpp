#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10; 
int n,m;
int a[maxn];
int sum[maxn];
int ans;
bool check(int x)
{
    for(int i=x+1;i<=n;++i)
    {
        int tmp=x*a[i]-(sum[i-1]-sum[i-x-1]);
        if(tmp<=m)
        {
            return 1;
        }
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(r+l)>>1;
        if(check(mid))
        {
            
            l=mid+1;
        }
        else
        {
            ans=mid;
            r=mid-1;
        }
    }
    printf("%lld",ans);
    return 0;
}
