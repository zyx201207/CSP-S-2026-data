#include <bits/stdc++.h>

#define int long long

const int MAXN = 70;

int n, k;

bool chosen[MAXN];
std::vector<int> g[MAXN];

bool temp[MAXN];

int dis[MAXN][MAXN];

void dfs(int u) {
    if (!temp[u])
        return;

    temp[u] = false;
    for (int v : g[u])
        dfs(v);
}

bool check() {
    memcpy(temp, chosen, sizeof(chosen));

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (temp[i]) {
            dfs(i);
            cnt++;
        }
    }
    return cnt == 2;
}

int mypopcount(int x) {
    int ans = 0;
    while (x) {
        x &= (x - 1);
        ans++;
    }
    return ans;
}

int solve() {
    //std::cerr << "======================new test==================\n";
    std::cin >> n >> k;

    if (n > MAXN)
        return rand();

    memset(chosen, 0, sizeof(chosen));
    memset(dis, 0x3f, sizeof(dis));

    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
        g[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);

        dis[u][v] = dis[v][u] = 1;
    }

    for (int b = 0; b < n; ++b) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = std::min(dis[i][j], dis[i][b] + dis[b][j]);
            }
        }
    }

    int ans = LLONG_MAX;

    for (int state = 0; state < (1LL << n); ++state) {
        if (mypopcount(state) != k)
            continue;

        std::vector<int> nodes;
        for (int i = 0; i < n; ++i) {
            chosen[i] = (state >> i) & 1;
            if (chosen[i])
                nodes.push_back(i);
        }

        if (!check())
            continue;

        int ass = 0;
        for (int i = 0; i < n; ++i) {
            if (chosen[i])
                continue;

            int as = LLONG_MAX;
            for (int j : nodes) {
                as = std::min(as, dis[i][j]);
            }
            ass = std::max(ass, as);
        }

        ans = std::min(ans, ass);
        // std::cerr << ass << '\n';
    }

    return ans;
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c, t;
    std::cin >> c >> t;

    while (t--)
        std::cout << solve() << '\n';
}