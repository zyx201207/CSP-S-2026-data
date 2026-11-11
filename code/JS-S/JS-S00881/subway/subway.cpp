#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q1,w[N];
long long h[502][5000],q[502][5000];
long long u[1001][1001],f[5000];
struct node{
    int v,x;
};
vector<vector<node>> E;
long long dis[5000];bool vis[5000];
void spfa(int s)
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();vis[u]=0;
        for(int i=0;i<E[u].size();i++)
        {
        if(dis[u]+E[u][i].x<dis[E[u][i].v])
        {
            dis[E[u][i].v]=dis[u]+E[u][i].x;
            if(!vis[u]) q.push(u);
            vis[u]=1;
        }
        }
    }
}
int main()
{
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   bool f1=1;
   scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q1);
   for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
   for(int i=1;i<=n;i++)
   {
       int k;scanf("%d",&k);
       if(k>2) f1=0;f[i]=k;
       for(long long j=1;j<=k;j++)
        scanf("%lld%lld",&q[i][j],&h[i][j]);
   }
   if(f1==0)
   {
       for(int i=1;i<=n;i++)
     for(int j=1;j<f[i];j++)
      E[q[i][j]].push_back({q[i][j+1],h[i][j]+h[i][j+1]});
   }
        while(q1--)
       {
           int a,b;
           scanf("%d%d",&a,&b);
           if(f1==1)
           {
           long long ans=0;
           ans+=w[a]+w[b];
           memset(u,0x3f,sizeof(u));
           for(int i=1;i<=n;i++)
                u[q[i][1]][q[i][2]]=h[i][1]+h[i][2];
            for(int i=1;i<=m;i++)
              for(int j=1;j<=m;j++)
               for(int k=1;k<=m;k++)
               if(i!=j&&i!=k&&j!=k)
               {
                   if(u[j][i]+u[i][k]<u[j][k])
                     u[j][k]=u[j][i]+u[i][k];
               }
            printf("%lld\n",ans+u[a][b]);
           }
           else{
            spfa(a);
            printf("%lld\n",dis[b]+w[a]+w[b]);
           }
       }
   return 0;
}
