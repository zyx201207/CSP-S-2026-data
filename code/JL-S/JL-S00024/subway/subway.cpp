#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005],ans;
bool vis1[500005],vis2[505];
struct node
{
    int v;
    long long w;
};
vector<node>g1[500005],g2[505];
void dfs(int u,int v,long long sum,int op)
{
    if(op==1&&u==v)
    {
        ans=min(ans,sum);
        return ;
    }
    if(op==1)
    {
        for(auto x:g1[u])
        {
            int y=x.v;
            long long w=x.w;
            if(vis2[y])continue;
            vis2[y]=true;
            dfs(y,v,sum+w,2);
            vis2[y]=false;
        }
    }
    else
    {
        for(auto x:g2[u])
        {
            int y=x.v;
            long long w=x.w;
            if(vis1[y])continue;
            vis1[y]=true;
            dfs(y,v,sum+w,1);
            vis1[y]=false;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int a;
            long long t;
            scanf("%d %lld",&a,&t);
            g1[a].push_back({i,t});
            g2[i].push_back({a,t});
        }
    }
    while(q--)
    {
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        int u,v;
        scanf("%d %d",&u,&v);
        ans=1e18;
        dfs(u,v,0,1);
        printf("%lld\n",ans+w[u]+w[v]);
    }
    return 0;
}
