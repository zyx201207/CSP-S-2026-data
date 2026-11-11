#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c, n, m, d, q, w[N], ans[N];
pair<int, int> qu[N];
vector<pair<int, int>> e[N];
vector<int> dij(int s){
   vector<int> dist(m+n+1, 1e18), vis(m+n+1, 0);dist[s]=0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;q.emplace(0, s);
   while(q.size()){
        auto tmp=q.top();q.pop();int u=tmp.second;
        if(vis[u]!=0) continue;
        vis[u]=1;
        for(auto i:e[u]){
            int v=i.first, w=i.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.emplace(dist[v], v);
            }
        }
   }
   return dist;
}
vector<int> bfs(int s){
   vector<int> dist(m+n+1, 0), vis(m+n+1, 0);vis[s]=1;
   queue<int> q;q.emplace(s);
   while(q.size()){
        auto u=q.front();q.pop();
        for(auto i:e[u]){
            int v=i.first, w=i.second;
            if(vis[v]!=0) continue;
            vis[v]=1;
            dist[v]=dist[u]+w;
            q.emplace(v);
        }
   }
   return dist;
}
void solve(){
    for(int i=1;i<=n;i++){
        vector<int> dist=bfs(i);
        for(int i=1;i<=q;i++) ans[i]=min(ans[i], dist[qu[i].first+n]+dist[qu[i].second+n]);
    }
    for(int i=1;i<=q;i++) cout << ans[i]+w[qu[i].first]+w[qu[i].second] << '\n';
    exit(0);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1, k, z;i<=n&&cin >> k;i++){
        for(int j=1, a, t;j<=k&&cin >> a >> t;j++){
            e[i].emplace_back(a+n, t);
            e[a+n].emplace_back(i, t);
        }
    }
    for(int i=1;i<=q;i++) cin >> qu[i].first >> qu[i].second;
    memset(ans, 0x3f, sizeof(ans));
    if(c<=19&&c>=16) solve();
    for(int i=1;i<=n;i++){
        vector<int> dist=dij(i);
        for(int i=1;i<=q;i++) ans[i]=min(ans[i], dist[qu[i].first+n]+dist[qu[i].second+n]);
    }
    for(int i=1;i<=q;i++) cout << ans[i]+w[qu[i].first]+w[qu[i].second] << '\n';
    return 0;
}
