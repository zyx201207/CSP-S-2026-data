#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;
int n,m;
int a[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,r=0;
    int ans=0;
    int cost=0;
    while(r<n)
    {
        ++r;
        cost+=(r-l)*(a[r]-a[r-1]);
        if(cost<=m)
        {
            ans=max(ans,r-l+1);
        }
        else
        {
            while(cost>m && l<r)
            {
                ++l;
                cost-=a[r]-a[l-1];
            }
            ans=max(ans,r-l+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
