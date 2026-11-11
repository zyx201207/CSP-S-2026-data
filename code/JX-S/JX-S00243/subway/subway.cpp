#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pii pair<int,i64>
#define fi first
#define se second
#define ep emplace_back
inline i64 read()
{
    i64 res=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) res=(res<<3)+(res<<1)+(c^48),c=getchar();
    return res;
}
const int N=505,M=5e5+10;
const i64 INF=8e18;
int c,n,m,d,q;
vector<pii> to[M];
i64 dis[N][N],val[M];
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
i64 query(int x,int y)
{
    i64 res=val[x]+val[y],minx=INF;
    int X=to[x].size(),Y=to[y].size();
    for(int i=0;i<X;i++)
    {
        int u=to[x][i].fi;
        i64 w1=to[x][i].se;
        for(int j=0;j<Y;j++)
        {
            int v=to[y][j].fi;
            i64 w2=to[y][j].se;
            minx=min(minx,w1+w2+dis[u][v]);
        }
    }
    return minx+res;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) val[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k;
        k=read();
        for(int j=1;j<=k;j++)
        {
            int v,t;
            v=read();t=read();
            to[v].ep(i,t);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int x=to[i].size();
        if(x==0) continue;
        for(int j=0;j<x;j++)
        {
            int u=to[i][j].fi;
            i64 w1=to[i][j].se;
            for(int k=j+1;k<x;k++)
            {
                if(j==k) continue;
                int v=to[i][k].fi;
                i64 w2=to[i][k].se;
                dis[u][v]=min(dis[u][v],w1+w2);
                dis[v][u]=min(dis[v][u],w1+w2);
            }
        }
    }
    floyd();
    while(q--)
    {
        int x,y;
        x=read(),y=read();
        printf("%lld\n",query(x,y));
    }
    return 0;
}
