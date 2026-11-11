#include<bits/stdc++.h>
using namespace std;
int a[5009],dis[5009];
bool vis[5009];
struct node
{
    int id,dis,rt;
    bool friend operator <(node a,node b)
    {
        return a.dis>b.dis;
    }
};
vector<node> g[5009];
int f[5009][5009];
int t[30][5009];
int w[5009];
int c,n,m,d,q;
void dij(int s)
{
    priority_queue<node> q;
    for(int i=1;i<=n;i++) dis[i]=t[f[s][i]][s];
    q.push({s,0,0});
    vis[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().id,from=q.top().rt;
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].id,w;
            int r=f[v][u];
            if(r!=0) w+=t[r][u]+t[r][v]+t[from][u];
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    q.push({v,dis[v],r});
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            a[j]=x;
            int u=x;
            cin>>t[i][x];
            if(lst==0) continue;
            g[lst].push_back({x,0});
            g[x].push_back({lst,0});
        }
        for(int j=1;j<=k;j++)
        {
            for(int z=1;z<=k;z++) f[j][z]=i;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dij(x);
        cout<<w[x]+w[y]+dis[y]<<endl;
    }
    return 0;
}
