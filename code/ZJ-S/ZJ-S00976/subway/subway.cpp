#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int a[M];
struct edge{
    int v,w;
    bool operator<(const edge &x) const{
        return w>x.w;
    }
};
vector<edge> mp[N+M];
vector<edge> st[M];
int res[N][N];
int dis[N+M];bool vis[N+M];
void dij(int st){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<edge> q;
    dis[st]=0;q.push({st,0});
    while(!q.empty()){
        int u=q.top().v;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(edge e:mp[u]){
            int v=e.v,w=e.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        res[st][i]=dis[i];
}
void bfs(int st){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    queue<int> q;
    dis[st]=0;q.push(st);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(edge e:mp[u]){
            int v=e.v,w=e.w;
            if(vis[v]) continue;
            vis[v]=1;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++)
        res[st][i]=dis[i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    int T=-1;bool fg=1;
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            mp[i].push_back({n+a,t});
            mp[n+a].push_back({i,t});
            st[a].push_back({i,t});
            if(T==-1) T=t;
            else{
                if(T!=t) fg=0;
            }
        }
    }
    if(fg) for(int i=1;i<=n;i++) bfs(i);
    else for(int i=1;i<=n;i++) dij(i);
    while(q--){
        int x,y;cin>>x>>y;
        int ans=1e18;
        for(edge u:st[x]){
            for(edge v:st[y]){
                ans=min(ans,res[u.v][v.v]+u.w+v.w);
            }
        }
        cout<<ans+a[x]+a[y]<<endl;
    }
    return 0;
}
