#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2000006;
ll n, m;
ll a[maxn];
vector<int> g[maxn];
ll dis[5005];
int calc(int x, int y) {
    for (int i = 1; i <= n; i++) dis[i] = (ll)1e18;
    dis[x] = 1;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        if (u == y) break;
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i];
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    if (dis[y] == 1 || dis[y] == (ll)1e18) return 0;
    queue<int> qq;
    qq.push(y);
    while (!qq.empty()) {
        int u = qq.front();
        qq.pop();
        if (u == x) break;
        ll minn = (ll)1e18;
        int cnt = 0;
        for (int i = 0; i < (int)g[u].size(); i++) minn = min(minn, dis[g[u][i]]);
        for (int i = 0; i < (int)g[u].size(); i++) if (dis[g[u][i]] == minn) {
            qq.push(g[u][i]);
            cnt++;
        }
        if (cnt == 2) return 1;
        if (cnt > 2) return 0;
    }
    return 0;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].clear();
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] - a[i] <= m) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += calc(i, j);
            // cout << i << " " << j << " " << calc(i, j) << '\n';
            // cout << ans << '\n';
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }   
    return 0;
}