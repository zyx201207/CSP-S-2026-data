#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e2+8;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int c,T,n,d;
int x[N],dis[N],ban[N][N];
int dp[N][N],cnt[N][N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    c=read(),T=read();
    while(T--)
    {
        n=read(),d=read();
        memset(dp,0x3f,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) x[i]=read(),dp[i][i]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                if(x[i]-x[j]<=d)
                    ban[j][i]=1;
        for(int s=1;s<=n;s++)
        {
            for(int i=s+1;i<=n;i++)
            {
                for(int j=s;j<i;j++)
                {
                    if(x[i]-x[j]>d) continue;
                    if(dp[s][i]>dp[s][j]+1) dp[s][i]=dp[s][j]+1,cnt[s][i]=1;
                    else if(dp[s][i]==dp[s][j]+1) cnt[s][i]++;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(cnt[i][j]==2)
                    ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
