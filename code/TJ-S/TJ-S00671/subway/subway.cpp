#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=1e7;
const int inf=1e18;
int w[N],k[N];
vector<int> t[505],a[505];
int x[N],y[N];
struct edge{
    int to,w;
};
struct node{
    int dis,x;
    bool operator<(const node &other)const{
        return other.dis<dis;
    }
};
vector<edge> g[M*3];
int dis[M*3],vis[M*3];
int c,n,m,d,q;
inline void dijkstra(int s){
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=3*n*m;i++) dis[i]=1e18;
    dis[s]=0;
    priority_queue<node> q;
    q.push({0,s});
    while (!q.empty()){
        int u=q.top().x;q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto &edge:g[u]){
            int v=edge.to,w=edge.w;
            if (dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
inline void solve(){
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        cin>>k[i];
        t[i].resize(k[i]+10);
        a[i].resize(k[i]+10);
        for (int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for (int i=1;i<=q;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=m;i++){
        g[i+m].push_back({i+m*2,w[i]}); //ditiezhan -> zhanting
        g[i+m*2].push_back({i+m,w[i]});
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<k[i];j++){
            g[a[i][j]+(i-1)*3*m].push_back({a[i][j+1]+(i-1)*3*m,0}); // xianlu
            g[a[i][j+1]+(i-1)*3*m].push_back({a[i][j]+(i-1)*3*m,0});
            g[a[i][j]+(i-1)*3*m].push_back({a[i][j]+m*2,t[i][j]}); //zhantai -> zhanting
            g[a[i][j]+m*2].push_back({a[i][j]+(i-1)*3*m,t[i][j]});
        }
        g[a[i][k[i]]+(i-1)*3*m].push_back({a[i][k[i]]+m*2,t[i][k[i]]});
        g[a[i][k[i]]+m*2].push_back({a[i][k[i]]+(i-1)*3*m,t[i][k[i]]});
    }
    for (int i=1;i<=q;i++){
        int u=x[i]+m,v=y[i]+m;
        dijkstra(u);
        cout<<dis[v]<<'\n';
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    while (T--) solve();
    return 0;
}
