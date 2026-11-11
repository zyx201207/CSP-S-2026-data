#include<bits/stdc++.h>
using namespace std;
long long w1[500005];
struct node
{
    int x;
    long long y;
}w2[500005][25];
int cnt[500005];
long long dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x7f,sizeof dis);
    for(int i = 1;i <= m;i++)
        cin>>w1[i];
    for(int i = 1;i <= n;i++)
    {
        dis[i][i]=0;
        int k;
        cin>>k;
        for(int j = 1;j <= k;j++)
        {
            int x;
            long long y;
            cin>>x>>y;
            w2[x][++cnt[x]]={i,y};
        }
    }
    for(int i = 1;i <= m;i++)//O(m*d^2)
        for(int j = 1;j <= cnt[i];j++)
            for(int k = j+1;k <= cnt[i];k++)
                dis[w2[i][j].x][w2[i][k].x]=dis[w2[i][k].x][w2[i][j].x]=w2[i][j].y+w2[i][k].y;
    for(int k = 1;k <= n;k++)//O(n^3)(floyd)
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                if(dis[i][k]<1e18&&dis[j][k]<1e18)
                    if(dis[i][j]>dis[i][k]+dis[j][k])
                        dis[i][j]=dis[j][i]=dis[i][k]+dis[j][k];
    while(q--)//O(q*d^2)
    {
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(int i = 1;i <= cnt[x];i++)
            for(int j = 1;j <= cnt[y];j++)
                ans=min(ans,dis[w2[x][i].x][w2[y][j].x]+w2[x][i].y+w2[y][j].y);
        cout<<ans+w1[x]+w1[y]<<"\n";
    }
    return 0;
}
