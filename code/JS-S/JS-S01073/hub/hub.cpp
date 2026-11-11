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
const int N = 2e6 + 5;
vector<int> g[N];
int fa[N], sz[N], dis[N];
int find(int x){
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int u, int v){
    int x = find(u), y = find(v);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    fa[y] = x;
}
void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].eb(v); g[v].eb(u);
    }
    int ans = n + 1;
    for (int S = 0; S < (1 << n); S++){
        if (__builtin_popcount(S) != k) continue;
        for (int i = 0; i < n; i++) fa[i] = i, sz[i] = 1, dis[i] = n + 1;
        queue<int> q;
        for (int j = 0; j < n; j++){
            if (S >> j & 1){
                q.push(j);
                dis[j] = 0;
            }
        }
        for (int u = 0; u < n; u++){
            if (!(S >> u & 1)) continue;
            for (int v : g[u]){
                if (!(S >> v & 1)) continue;
                merge(u, v);
            }
        }
        int num = 0;
        for (int i = 0; i < n; i++){
            if (!(S >> i & 1)) continue;
            if (find(i) == i) num++;
        }
        if (num > 2) continue;
        int res = 0;
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (int v : g[u]){
                if (dis[v] != n + 1) continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        for (int i = 0; i < n; i++) res = max(res, dis[i]);
        ans = min(ans, res);
    }
    cout << ans << endl;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false); cin.tie(0);
    int C, T = 1;
    cin >> C >> T;
    while (T--) solve();
    return 0;
}