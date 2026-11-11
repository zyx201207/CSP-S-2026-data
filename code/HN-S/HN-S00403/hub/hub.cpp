#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, INF = 1e18;
int c, n, k, ans, du[N], li[N];
bool flag[N], key[N];
vector<int> g[N], ss;
struct node {
    int val, ju, last;
};
int bfs (int x) {
    queue<node> q;
    q.push({x, 0, 0});
    while(!q.empty()) {
        node h = q.front(); q.pop();
        if (flag[h.val]) {
            return h.ju;
        }
        for (int i = 0; i < g[h.val].size(); i++) {
            int dd = g[h.val][i];
            if (dd == h.last) continue;
            q.push({dd, h.ju + 1, h.val});
        }
    }
    return INF;
}
void B (int x, int last) {
    if (key[x]) return;
    //if (flag[2] && flag[3] && flag[9]) cout << x << " " << last << "\n";
    key[x] = 1;
    for (int i = 0; i < g[x].size(); i++) {
        int h = g[x][i];
        if (h == last || !flag[h]) continue;
        B(h, x);
    }
}
bool check() {
    for (int i = 0; i <= n; i++) key[i] = 0;
    int dg = 0;
    for (int i = 1; i <= n; i++) {
        if (flag[i] && !key[i]) {
            dg++; B(i, 0);
            //if (flag[2] && flag[3] && flag[9])
            //for (int ii = 1; ii <= n; ii++) cout << key[i] << " ";
        }
        if (dg > 2) return 0;
    }
    return 1;
}
void dfs (int x, int shu) {
    if (x > n) {
        if (shu == 0 || !check()) return;
        int kop = 0;
        for (int i = 1; i <= n; i++) {
            int h = bfs(i);
            kop = max(kop, h);
        }
        ans = min(ans, kop); return;
    }
    if (shu < k) flag[x] = 1;
    dfs(x + 1, shu + 1);
    flag[x] = 0;
    dfs(x + 1, shu);
}
bool C (int x) {
    int sum = k;
    queue<node> q;
    for (int i = 0; i < ss.size(); i++) q.push({ss[i], 0, 0});
    for (int i = 0; i <= n; i++) flag[i] = 0, li[i] = INF;
    while(!q.empty()) {
        node h = q.front(); q.pop();
        if (li[h.val] <= h.ju) continue;
        li[h.val] = h.ju;
        if (h.ju >= x) sum--, h.ju = -x, flag[h.val] = 1;
        if (sum < 0) return 0;
        for (int i = 0; i < g[h.val].size(); i++) {
            int y = g[h.val][i];
            if (y == h.last) continue;
            q.push({y, h.ju + 1, h.val});
        }
    }
    if (!check()) return 0;
    return 1;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear(), du[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++; du[v]++;
    }
    if (c > 0 && c <= 3) {
        ans = INF;
        // 可以敲中文也不要跳你那雷霆输入法行吗。
        dfs(1, 0); cout << ans << "\n"; return;
    }
    ss.clear();
    for (int i = 1; i <= n; i++) if (du[i] == 1) ss.push_back(i);
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if (C(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> c >> t; while(t--) solve();
    return 0;
}
// 17:40 100+100+24+15=249
// T4 神秘假算算 eps 分。
