#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;

int x[N + 5], dis[1005][1005], tm[1005][1005], n, d;

void dfs(int st, int u, int di) {
    if (di < dis[st][u]) {
        dis[st][u] = di;
        tm[st][u] = 0;
    } else if (di == dis[st][u])
        tm[st][u]++;
    for (int i = u + 1; i <= n; i++) {
        if (x[i] - x[u] > d)
            return;
        dfs(st, i, di + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 1; i <= n; i++)
            dfs(i, i, 0);
        int ans = 0;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (dis[i][j] == 2)
                    ans++;
        cout << ans << '\n';
    }
    return 0;
}
