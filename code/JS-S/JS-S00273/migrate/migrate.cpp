#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005],dp[2000005],pt[2000005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        int n,d,ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",x+i);
        }
        if(c==11||c==12)
        {
            int k=x[2]-x[1];
            int p=d/k;
            if(p==0)puts("0");
            else if(p==1)puts("0");
            else if(x[n]-x[1]<=d)puts("0");
            else
            {
                printf("%lld\n",n-2*p+1);
            }
            continue;
        }
        for(int i=1;i<n;i++)
        {
            memset(dp,0x3f,sizeof(dp));
            dp[i]=0;
            pt[i]=1;
            for(int j=i+1;j<=n;j++)
            {
                int pos=lower_bound(x+i,x+1+n,x[j]-d)-x;
                for(int k=pos;k<j;k++)
                {
                    if(dp[k]+1<dp[j])
                    {
                        pt[j]=pt[k];
                        dp[j]=dp[k]+1;
                    }
                    else if(dp[k]+1==dp[j])
                    {
                        pt[j]+=pt[k];
                    }
                }
                if(pt[j]==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
