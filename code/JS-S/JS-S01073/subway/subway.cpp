#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
const int M = 500005;
int C, n, m, d, Q;
ll w[M];
vector<pii> g[505];
vector<pil> lines[M];
ll dis[505];
bool used[505];
void dijkstra(int s){
    for (int i = 1; i <= n; i++) dis[i] = 1e18, used[i] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s}); dis[s] = 0;
    while (!pq.empty()){
        int u = pq.top().second; pq.pop();
        if (used[u]) continue;
        used[u] = 1;
        for (pii x : g[u]){
            int v = x.first, w = x.second;
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                if (!used[v]) pq.push({dis[v], v});
            }
        }
    }
}
ll f[505][505];
void solve(){
    cin >> C >> n >> m >> d >> Q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int x, t; cin >> x >> t;
            lines[x].eb(i, t);
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < sz(lines[i]); j++){
            for (int k = j + 1; k < sz(lines[i]); k++){
                pii x = lines[i][j], y = lines[i][k];
                ll w = x.second; w += y.second;
                g[x.first].eb(y.first, w);
                g[y.first].eb(x.first, w);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        dijkstra(i);
        for (int j = 1; j <= n; j++) f[i][j] = dis[j];
    }
    while (Q--){
        int x, y; cin >> x >> y;
        ll ans = 2e18;
        for (pil a : lines[x]){
            for (pil b : lines[y]){
                ans = min(ans, w[x] + w[y] + f[a.first][b.first] + a.second + b.second);
            }
        }
        cout << ans << '\n';
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}