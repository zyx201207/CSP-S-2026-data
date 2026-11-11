#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
long long dist[M][M];
long long w[N];
int c,m,n,d,q;
struct node{
    int line;
    long long len;
};
vector<node> li[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dist,0x3f,sizeof dist);
    scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=m;i++)
    {
        dist[i][i]=0;
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int x;
            long long t;
            scanf("%d%lld",&x,&t);
            li[x].push_back(node{i,t});
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int si=li[i].size();
        for(int j=0;j<si;j++)
        {
            for(int k=j+1;k<si;k++)
            {
                int u=li[i][j].line,v=li[i][k].line;
                long long dis=li[i][j].len+li[i][k].len;
                dist[u][v]=min(dist[u][v],dis);
                dist[v][u]=min(dist[v][u],dis);
            }
        }
    }
    
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         printf("%lld ",dist[i][j]);
    //     puts("");
    // }
    
    while(q--)
    {
        int x,y;
        long long ans=LONG_LONG_MAX;
        scanf("%d%d",&x,&y);
        int s1=li[x].size();
        int s2=li[y].size();
        
        for(int i=0;i<s1;i++)
            for(int j=0;j<s2;j++)
            {
                int u=li[x][i].line,v=li[y][j].line,dis=li[x][i].len+li[y][j].len;
                ans=min(ans,dist[u][v]+w[x]+w[y]+dis);
            }
        printf("%lld\n",ans);
    }
    return 0;
}