#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,cost=0;
    for(int r=1;r<=n;++r)
    {
        cost+=(a[r]-a[max(l,r-1)])*(r-l);
        while(cost>m)
        {
            cost-=a[r]-a[l];
            ++l;
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}
