#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
vector<pair<int, int>> edge;
vector<vector<int>> e;
vector<int> dep, siz, dep_child;
int root = 0, ans = 0, cnt = 0;
void dfs(int x, int fa, int dis) {
    siz[x] = 1;
    dep_child[x] = dep[x] = dep[fa] + 1;
    int childcnt = 0;
    for (auto to : e[x]) {
        if (to == fa)
            continue;
        dfs(to, x, dis);
        siz[x] += siz[to];
        dep_child[x] = max(dep_child[x], dep_child[to]);
        childcnt++;
    }
    if (dep_child[x] - dep[x] < dis)
        cnt--;
    if (dep[x] > dis || childcnt >= 2) 
        root = x;
}
bool check(int x) {
    for (int i = 1; i <= n; i ++) {
        ans = 0;
        cnt = 0;
        root = 0;
        dep.assign(n + 1, 0);
        dep_child.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        dfs(1, 0, x);
        cnt += siz[root];
        ans = ans + max(cnt, 1);
        if (ans <= k) {
            return true;
        }
    }
    for (auto it : edge) {
        ans = 0;

        cnt = 0;
        root = 0;
        dep.assign(n + 1, 0);
        dep_child.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        dfs(it.first, it.second, x);
        cnt += siz[root];
        ans = ans + max(cnt, 1);

        // cout << ans << ' ';

        cnt = 0;
        root = 0;
        dep.assign(n + 1, 0);
        dep_child.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        dfs(it.second, it.first, x);
        cnt += siz[root];
        // cout << cnt << ' ';
        ans = ans + max(cnt, 1);

        // cout << ans << ' ' << it.first << ' ' << it.second  << ' ' << x << '\n';
        if (ans <= k) {
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> k;
    edge.clear();
    e.assign(n + 1, vector<int> {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
        e[u].push_back(v);
        e[v].push_back(u);
    }   
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--) {
        solve();
    }
    return 0;
}