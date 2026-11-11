#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cctype>
#include <cmath>
#include <set>

#define int long long
#define FILENAME "hub"

const int MAXN = 110;

int n, k;
std::vector<int> es[MAXN];
bool flag[MAXN], vis[MAXN];

void dfs1(int u) {
    vis[u] = true;
    for (int v: es[u]) {
        if (!vis[v] && flag[v]) dfs1(v);
    }
}

bool check(int i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j, i >>= 1) {
        if (i & 1) {
            flag[j] = true;
            ++cnt;
        } else {
            flag[j] = false;
        }
    }
    if (cnt != k) return false;
    for (int i = 1; i <= n; ++i) vis[i] = false;
    cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (flag[u] && !vis[u]) {
            ++cnt;
            dfs1(u);
        }
    }
    return cnt <= 2;
}

int dfs2(int u, int p) {
    if (flag[u]) return 0;
    int ans = 0x3f3f3f3f;
    for (int v: es[u]) {
        if (v != p) {
            ans = std::min(ans, dfs2(v, u));
        }
    }
    return ans + 1;
}

signed main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, t;
    std::cin >> c >> t;

    while (t--) {
        // printf(
            
        //     "??????"
        // );
    std::cin >> n >> k;
    int u, v;
    for (int u = 1; u <= n; ++u) {
        es[u].clear();
    }
    for (int i = 1; i < n; ++i) {
        std::cin >> u >> v;
        es[u].push_back(v);
        es[v].push_back(u);
    }
    int mx = 1 << n;
    int trueans = 0x3f3f3f3f;
    for (int i = 1; i < mx; ++i) {
        if (!check(i)) continue;
        // printf("OK: %d\n", i);
        int ans = 0;
        for (int u = 1; u <= n; ++u) {
            ans = std::max(ans, dfs2(u, 0));
        }
        trueans = std::min(trueans, ans);
    }
    std::cout << trueans << '\n';
    }

    std::cout.flush();

    fclose(stdin);
    fclose(stdout);
    return 0;
}