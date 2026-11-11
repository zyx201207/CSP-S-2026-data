#include<bits/stdc++.h>
using namespace std;
const int N=5e5+600;
vector<pair<int,int>>a[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int c,n,m,d,qq,w[N];
int dis[N],vis[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
   cin>>c>>n>>m>>d>>qq;
   for(int i=1;i<=m;i++)
    cin>>w[i];
   for(int t=1;t<=n;t++)
   {
       int k;
       cin>>k;
       for(int i=1;i<=k;i++)
       {
           int u,ww;
           cin>>u>>ww;
           a[u].push_back({t+m,ww});
           a[t+m].push_back({u,ww});
       }
   }
   while(qq--)
   {
       memset(dis,0x3f,sizeof(dis));
       memset(vis,0,sizeof(vis));
       int s,t;
       cin>>s>>t;
       dis[s]=w[s]+w[t];
       q.push({dis[s],s});
       while(!q.empty())
       {
            int u=q.top().second;
            q.pop();
            if(vis[u]!=0)continue;
            vis[u]=1;
            for(int i=0;i<a[u].size();i++)
            {
                int v=a[u][i].first,w=a[u][i].second;
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    if(vis[v]==0)q.push({dis[v],v});
                }
            }
       }
       printf("%d\n",dis[t]);
   }
    return 0;
}
