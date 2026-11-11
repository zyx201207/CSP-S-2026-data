#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,tot;
int head[N];
bool chosen[N];
struct Edge
{
    int v,nxt;
}e[N<<1];
void add(int u,int v)
{
    e[++tot]={v,head[u]};
    head[u]=tot;
}
bool vis[N];
int dis[N];
void dfs(int u,int fa)
{
    vis[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
        if(e[i].v!=fa&&chosen[e[i].v]) dfs(e[i].v,u);
}
bool check()
{
    for(int i=1;i<=n;i++)
        vis[i]=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]&&chosen[i]) dfs(i,i),cnt++;
    return cnt<=2;
}
int bfs()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(chosen[i]) q.push(i),dis[i]=0;
        else dis[i]=n+1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt)
            if(dis[e[i].v]>dis[u]+1) dis[e[i].v]=dis[u]+1,q.push(e[i].v);
    }
    return *max_element(dis+1,dis+1+n);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,T;cin>>c>>T;
    if(c>3) return 0;
    while(T--)
    {
        cin>>n>>k;
        tot=0;
        for(int i=1;i<=n;i++)
            head[i]=0;
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            add(u,v);add(v,u);
        }
        int ans=n+1;
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(__builtin_popcount(mask)>k) continue;;
            for(int j=1;j<=n;j++)
                chosen[j]=(mask>>(j-1))&1;
            if(check()) ans=min(ans,bfs());
            // cerr<<mask<<" "<<bfs()<<"\n";
        }
        cout<<ans<<"\n";
    }
}