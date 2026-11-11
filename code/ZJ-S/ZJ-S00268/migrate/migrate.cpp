#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10; 
int c,t;
int n,d;
int x[maxn];
int dp[maxn];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;++i)
        {
            dp[i]=0;
            scanf("%lld",x+i);
        }
        if(n<=3)
        {
            puts("0");
            continue;
        }
        dp[0]=dp[1]=dp[2]=dp[3]=0ll;
        for(int i=4;i<=n;++i)
        {
            dp[i]=dp[i-1];
            if((x[i-2]+d>=x[i])&&((dp[i-2]!=dp[i-3])||(x[i-3]+d<x[i])))
            {
                ++dp[i];
            }
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
