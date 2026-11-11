#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
int n, d, a[N], dis[N], cnt[N];
bool vis[N];
vector <int> G[N];
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) if(a[j] - a[i] <= d) G[i].push_back(j), G[j].push_back(i); else break;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) dis[j] = 1e18, vis[j] = cnt[j] = 0;
        std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > q;
        q.push({0, i}), dis[i] = 0, cnt[i] = 1;
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int j = 0; j < G[u].size(); ++j){
                int v = G[u][j];
                if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, cnt[v] = cnt[u], q.push({dis[v], v});
                else if(dis[v] == dis[u] + 1) cnt[v] += cnt[u];
            }
        }
        for(int j = i + 1; j <= n; ++j) if(cnt[j] == 2) ans++;
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i) G[i].clear();
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--) solve();
    return 0;
}
