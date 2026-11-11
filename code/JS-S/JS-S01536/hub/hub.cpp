#ifndef ENABLE_DEBUG
#define NDEBUG
#endif
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using ui128 = __uint128_t;
#define amin(x, y) x = min(x, y)
#define amax(x, y) x = max(x, y)
#define gcd(x, y) __gcd(x, y)
#ifdef NO_FILE
#define file(x) (void)0
#else
#define file(x) auto _ = freopen(x ".in", "r", stdin); \
                     _ = freopen(x ".out", "w", stdout); \
                (void)_;
#endif

constexpr int maxn = 101;

int n, k;
vector<int> g[maxn];
int depth[maxn];
int fas[maxn];

void init(int cur, int fa) {
    depth[cur] = depth[fa] + 1;
    fas[cur] = fa;

    for (int ch : g[cur]) {
        if (ch == fa) {
            continue;
        }
        init(ch, cur);
    }
}

int get_dis(int u, int v) {
    int ret = 0;

    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    while (depth[u] > depth[v]) {
        u = fas[u];
        ++ret;
    }

    while (u != v) {
        u = fas[u];
        v = fas[v];
        ret += 2;
    }

    return ret;
}

int ans;
int v[maxn];
bool in[maxn];
bool vis[maxn];

void bfs(int s) {
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        vis[cur] = true;

        for (int ch : g[cur]) {
            if (vis[ch] || !in[ch]) {
                continue;
            }
            q.push(ch);
        }
    }
}

bool valid() {
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 1; i <= k; ++i) {
        if (!vis[v[i]]) {
            if (cnt == 2) {
                return false;
            }
            ++cnt;
            bfs(v[i]);
        }
    }
    return true;
}

void dfs(int cur) {
    if (cur == k + 1) {
        if (!valid()) {
            return;
        }

        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            int mn = 0x3f3f3f3f;
            for (int j = 1; j <= k; ++j) {
                amin(mn, get_dis(i, v[j]));
            }
            amax(mx, mn);
        }
        amin(ans, mx);
        return;
    }

    for (v[cur] = v[cur - 1] + 1; v[cur] <= n - k + cur; ++v[cur]) {
        in[v[cur]] = true;
        dfs(cur + 1);
        in[v[cur]] = false;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    init(1, 0);

    ans = 0x3f3f3f3f;
    dfs(1);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("hub");

    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }

    cout << flush;
    return 0;
}
