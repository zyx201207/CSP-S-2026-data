#include<bits/stdc++.h>
using namespace std;
int cx,n,m,d,q,k[501], v[500001][21],w[500001],c[500001],use[500001][501];
long long dis[501][501],ans;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> cx >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x;
            long long y;
            cin >> x >> y;
            use[x][i]=y;
            ++c[x];
            v[x][c[x]]=i;
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=c[i];j++)
        {
            for(int k=j+1;k<=c[i];k++)
            {
                int t1=v[i][j],t2=v[i][k];
                dis[t1][t2]=min(dis[t1][t2],1ll*use[i][t1]+1ll*use[i][t2]);
                dis[t2][t1]=min(dis[t2][t1],1ll*use[i][t1]+1ll*use[i][t2]);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    dis[i][j]=0;
                }
                else
                {
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int fm,to;
        cin >> fm >> to;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int it=1;it<=c[fm];it++)
        {
            int t1=v[fm][it];
            for(int jt=1;jt<=c[to];jt++)
            {
                int t2=v[to][jt];
                ans=min(ans,dis[t1][t2]+1ll*use[fm][t1]+1ll*use[to][t2]+1ll*w[fm]+1ll*w[to]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
