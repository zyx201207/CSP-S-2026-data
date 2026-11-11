#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=0x3f3f3f3f3f3f3f3f;
constexpr int maxn=5e5+1000;
vector<pair<int,int>>gra[maxn];
struct node_t
{
    int v,w;
    node_t()=default;
    node_t(int v,int w):v(v),w(w){}
    bool operator<(const node_t& b)const{return v>b.v;}
};
auto dijkstra(int n,int s)
{
    vector<int>dis(n+1,INF);
    vector<int>vis(n+1);
    priority_queue<node_t>q;
    q.emplace(s,0);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:gra[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(v,dis[v]);
            }
        }
    }
    return dis;
}
void addedge(int u,int v,int w)
{
    gra[u].emplace_back(v,w);
    gra[v].emplace_back(u,w);
}
signed main()
{
#ifndef zzr
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int>w(m+1);
    for(int i=1;i<=m;++i)cin>>w[i];
    int sum=0;
    for(int i=1,k;i<=n;++i)
    {
        cin>>k;
        sum+=k;
        for(int j=1,a,t;j<=k;++j)
        {
            cin>>a>>t;
            addedge(a,i+m,t);
        }
    }
    vector<vector<int>>dis(n+1);
    for(int i=1;i<=n;++i)dis[i]=dijkstra(n+m,m+i);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int res=INF;
        for(int i=1;i<=n;++i)res=min(res,dis[i][u]+dis[i][v]);
        cout<<res+w[u]+w[v]<<'\n';
    }
    // 1-m 
    // 
}
// 2 4 13