#include<bits/stdc++.h>;
using namespace std;
long long c,n,m,d,q,f,e;
long long a[1005][1005],k[1005][1005],t[1005][1005],dp[1005],s=0;
long long dfs(long long x,long long y)
{
    if(x==y) return t[x][y];
    for(long long i=1;i<=m;i++)
    {
        if(t[i][y]!=0&&i!=y)
        {
            if(y==e)s++;
            dp[s]=dp[s]+dfs(x,i)+t[i][i];
            return dfs(x,i);
        }
    }
}
int main( )
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long p[10005],x[10005];
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>p[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>x[i];
        for(long long j=1;j<=x[i];j++)
        {
            cin>>a[j][i]>>k[j][i];
        }
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=x[i];j++)
        {
            for(long long c=1;c<=x[i];c++)
            {
               t[a[c][i]][a[j][i]]=k[j][i];
            }
        }
    }
    while(q--)
    {
        for(long long i=1;i<=s;i++)
        {
           dp[i]=0;
        }
        cin>>f>>e;
        if(t[f][e]!=0)
        {
            cout<<t[f][e]+p[f]+p[e]+t[f][f]<<endl;

        }else
        {
            dfs(f,e);
            long long minx=INT_MAX;
            for(long long i=1;i<=s;i++)
            {
                if(minx>dp[i])
                {
                    minx=dp[i];
                }
            }
            cout<<minx+p[f]+p[e]+1<<endl;
        }
    }
    return 0;
}
