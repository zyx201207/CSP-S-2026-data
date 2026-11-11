#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005][5005];
int x[5005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%lld %lld",&c,&t);
    while(t--)
    {
        int n,d,ans=0;
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n;++i)
        {
            int l=i;
            int en=i;
            for(int j=i;j<=n;++j)
            {
                if(i==j)
                {
                    dp[i][j]=0;
                    continue;
                }
                while(x[j]-x[l]>d)
                {
                    ++l;
                }
                if(l==j)
                {
                    dp[i][j]=-1;
                    break;
                }
                dp[i][j]=dp[i][l]+1;
                if(dp[i][j]!=dp[i][j-1])
                {
                    en=j-1;
                }
                if(en-l+1==2)
                {
                    ++ans;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
