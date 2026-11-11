#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+10;
int n,m,a[maxn],sum[maxn];
bool chk(int x,int id)
{
    if((id-x)*a[id]-sum[id-1]+sum[x-1]<=m) return 1;
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
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int res=0;
    for(int i=1;i<=n;++i)
    {
        int l=1,r=i,ans=0;
        while(l<=r)
        {
            int mid=l+(r-l>>1);
            if(chk(mid,i))
            {
                r=mid-1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        res=max(res,i-ans+1);
    }
    printf("%lld",res);
    return 0;
}