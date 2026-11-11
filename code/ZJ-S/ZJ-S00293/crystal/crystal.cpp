#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=5e5+10;

int n,m;
int a[maxn];
int need=0;
int ans=1;

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
    for(int l=1,r=1;r<=n;++r)
    {
        need+=(r-l)*(a[r]-a[r-1]);
        while(m<need&&l+1<=r)
        {
            ++l;
            need-=a[r]-a[l];
        }
        //printf("%lld %lld %lld\n",need,l,r);
        ans=max(ans,r-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}