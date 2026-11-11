#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
int C,T;
int n,k,dis[N][N],diss[N],ans,res,vis[N];
vector <int> g[N];
void dfs(int x,int f,int tp){
    if(x != tp) dis[tp][x] = dis[tp][f] + 1;
    for(auto i : g[x])
        if(i != f) dfs(i,x,k);
}
void dfs2(int x,int f,int st){
    vis[x] = 1;
    for(auto i : g[x])
        if(i != f && ((st >> i) & 1 == 0)) dfs2(i,x,st);
}
void solve(){
    cin>>n>>k;
    ans = 1e9;
    memset(dis,0,sizeof(dis));
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++) dfs(i,i,i);
    for(int st = 0;st < (1 << n);st++){
        if(__builtin_popcount(st) != k) continue;
        res = 0;
        for(int i=0;i<n;i++) diss[i] = 1e9;
        for(int i=0;i<n;i++) vis[i] = 0;
        int cnt = 0;
        for(int i=0;i<n;i++) if(((st >> i) & 1) && !vis[i]) dfs2(i,i,st),cnt++;
        if(cnt > 2) continue;
        for(int i=0;i<n;i++){
            if(((st >> i)) & 1) continue;
            for(int j=0;j<n;j++){
                if((st >> j) & 1 == 0) continue;
                diss[i] = min(diss[i],dis[i][j]);
            }
            res = max(res,diss[i]);
        }ans = min(ans,res);
        //cout<<res<<"\n";
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>C>>T;
    while(T--) solve();
}
