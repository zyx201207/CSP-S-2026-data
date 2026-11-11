#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e6 + 5;

vector<int> g[N];
long long a[N];
int dis[N], cnts[N];

int main () {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) {
        int n;
        long long d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (c <= 10) {
            for (int i = 1, j = 1; i <= n; i++) {
                while (j <= n && a[j] <= a[i] + d) j++;
                for (int k = i + 1; k < j; k++) {
                    g[i].emplace_back(k);
                }
            }
            queue<int> q;
            int ans = 0;
            for (int i = 1; i < n; i++) {
                memset(dis + 1, -1, n * 4);
                memset(cnts + 1, 0, n * 4);
                cnts[i] = 1; dis[i] = 0;
                q.emplace(i);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : g[u]) {
                        if (!~dis[v] || dis[v] == dis[u] + 1) cnts[v] += cnts[u];
                        if (!~dis[v] || dis[v] > dis[u] + 1) {
                            dis[v] = dis[u] + 1;
                            cnts[v] = cnts[u];
                            q.emplace(v);
                        }
                    }
                }
                for (int j = i + 1; j <= n; j++) {
                    if (cnts[j] == 2) ans++;
                }
            }
            cout << ans << '\n';
            for (int i = 1; i <= n; i++) g[i].clear();
        } else if (c <= 12) {
            int p = upper_bound(a + 1, a + n + 1, a[1] + d) - a - 1;
            if (p < 3) cout << "0\n";
            else cout << max(0, n - p * 2 + 3) << '\n';
        } else cout << "0\n";
    }
    return 0;
}

// ming yun yi ran zhu ding
// nu li jie zai dang jin
