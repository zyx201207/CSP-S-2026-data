#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f;

vector<int> g[N];
bool choose[N], vis[N];
int dis[N];
int n, k, ans;

void Init() {
    fill(g + 1, g + n + 1, vector<int>());
    fill(choose + 1, choose + n + 1, false);
    ans = INF;
}

void Check(int x) {
    vis[x] = true;
    for (auto y : g[x]) {
        if (!choose[y] || vis[y]) continue;
        Check(y);
    }
}

void Upd(int x, int dep) {
    dis[x] = min(dis[x], dep);
    for (auto y : g[x]) {
        if (choose[y] || dis[y] <= dep + 1) continue;
        Upd(y, dep + 1);
    }
}

void Dfs(int x, int lft) {
    if (x > n) {
        if (lft != 0) return;
        fill(vis + 1, vis + n + 1, false);
        fill(dis + 1, dis + n + 1, INF);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (choose[i] && !vis[i]) {
                Check(i);
                ++cnt;
            }
        }
        if (cnt > 2) return;
        for (int i = 1; i <= n; ++i) {
            if (choose[i]) Upd(i, 0);
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) res = max(res, dis[i]);
        ans = min(ans, res);
        return;
    }
    if (lft < 0 || lft > n - x + 1) return;
    if (lft == 0) {
        choose[x] = false;
        Dfs(x + 1, lft);
        choose[x] = false;
    } else if (lft == n - x + 1) {
        choose[x] = true;
        Dfs(x + 1, lft - 1);
        choose[x] = false;
    } else {
        choose[x] = false;
        Dfs(x + 1, lft);
        choose[x] = true;
        Dfs(x + 1, lft - 1);
        choose[x] = false;
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        Init();
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        Dfs(1, k);
        cout << ans << '\n';
    }
}