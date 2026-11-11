#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int maxn1=2e6+5;
#define ll long long
int n,dp[maxn][maxn],dis[maxn][maxn];
ll x[maxn1],d;
int nxt[maxn];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c<=10 && c>=1)
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>x[i];
            for(int i=1;i<=n;i++)
            {
                int p=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
                nxt[i]=p;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dp[i][j]=0;
                    dis[i][j]=0;
                }
            }
            for(int k=1;k<=n;k++)
            {
                for(int i=1;i<=n;i++)
                {
                    int j=i+k-1;
                    if(j>n)
                        break;
                    if(x[j]-x[i]<=d)
                    {
                        dis[i][j]=1;
                        dp[i][j]=1;
                        continue;
                    }
                    if(nxt[i]==i)
                    {
                        dp[i][j]=0;
                        continue;
                    }
                    dis[i][j]=1+dis[nxt[i]][j];
                    if(nxt[i]==i+1)
                    {
                        dp[i][j]=dp[nxt[i]][j];
                    }
                    if(nxt[i]==i+2)
                    {
                        dp[i][j]=dp[nxt[i]][j];
                        if(dis[nxt[i]-1][j]+1==dis[i][j])
                            dp[i][j]+=dp[nxt[i]-1][j];
                        if(dp[i][j]>2)
                            dp[i][j]=3;
                    }
                    if(nxt[i]>i+2)
                    {
                        dp[i][j]=dp[nxt[i]][j];
                        if(dis[nxt[i]-1][j]+1==dis[i][j])
                            dp[i][j]+=dp[nxt[i]-1][j];
                        if(dis[nxt[i]-2][j]+1==dis[i][j])
                            dp[i][j]+=dp[nxt[i]-2][j];
                        if(dp[i][j]>2)
                            dp[i][j]=3;
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(dp[i][j]==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    else if(c==11 || c==12 || c==0)
    {
        while(T--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>x[i];
            ll k=(d/(x[2]-x[1]));
            if(k<=1)
                cout<<0<<"\n";
            else
            {
                ll ans=0;
                if((ll)n>=2*k-1)
                    ans+=((ll)n-(2*k-1));
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
