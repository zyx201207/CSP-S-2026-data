#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e6+10;
constexpr int K=N;
int c,T;
int n,k;
struct edge{
    int from,to;
};
vector<edge> e[N];
bool vis[N];
bool ff[N];
void color(int u){
    vis[u]=true;
    for(edge ee:e[u]){
        int v=ee.to;
        if(vis[v]) continue;
        if(!ff[v]) continue;
        color(v);
    }
}
bool check(int mask){
    memset(ff,false,sizeof(ff));
    for(int i=1;i<=n;i++){
        if((mask>>(i-1ll))&1ll){
            ff[i]=true;
        }
    }
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(((mask>>(i-1ll))&1ll) && !vis[i]){
            color(i); cnt++;
        }
    }
    return cnt<=2;
}
int dist[N];
void dfs(int u,int cnt){
    vis[u]=true;
    for(edge ee:e[u]){
        int v=ee.to;
        if(vis[v]) continue;
        dist[v]=min({dist[v],cnt+1});
        dfs(v,cnt+1);
    }
}
void solve_force(){
    int res=1e14;
    for(int mask=0;mask<(1ll<<n);mask++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if((mask>>(i-1ll))&1){
                cnt++;
            }
        }
        if(cnt!=k) continue;
        if(!check(mask)) continue;
        memset(dist,0x3f,sizeof(dist));
        for(int i=1;i<=n;i++){
            if((mask>>(i-1ll))&1){
                dist[i]=0;
                memset(vis,false,sizeof(vis));
                dfs(i,0);
            }
        }
        res=min({res,(*max_element(dist+1,dist+1+n))});
    }cout<<res<<'\n';
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        e[u].emplace_back(edge{u,v});
        e[v].emplace_back(edge{v,u});
    }
    solve_force();
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
/*
RP++
17:27 15pts
*/
