#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+8;
const int ID=5e2+8;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int c,n,m,d,q;
int ww[N];
int dis[N][ID],t[510][N],a[510][N];
bool vis[N][ID];
struct Node{
    int v,id,w;
    bool operator<(const Node& rhs) const { return w<rhs.w; }
};
vector<Node>adj[N];
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<Node>pq;
    for(int i=1;i<=n;i++)
        if(t[i][s]!=0x3f)
        {
            dis[s][i]=t[i][s];
            pq.push({s,i,t[i][s]});
        }
    while(!pq.empty())
    {
        auto [u,id,_]=pq.top();
        pq.pop();
        if(vis[u][id]) continue;
        vis[u][id]=1;
        for(auto [v,vid,vw]:adj[u])
        {
            if(id!=vid) vw+=t[id][u]+t[vid][u];
            if(dis[v][vid]>dis[u][id]+vw) dis[v][vid]=dis[u][id]+vw,pq.push({v,vid,dis[v][vid]});
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) ww[i]=read();
    memset(t,0x3f,sizeof(t));
    for(int i=1,x;i<=n;i++)
    {
        x=read();
        for(int j=1;j<=x;j++) {
            a[i][j]=read();
            t[i][a[i][j]]=read();
        }
        for(int j=1;j<x;j++)
        {
            adj[a[i][j]].push_back({a[i][j+1],i,0});
        }
    }
    while(q--)
    {
        int x=read(),y=read();
        dijkstra(x);
        int ans=1e18;
        for(int i=1;i<=n;i++) ans=min(ans,dis[y][i]+t[i][y]);
        cout<<ans+ww[x]+ww[y]<<'\n';
    }
    return 0;
}
