#include <bits/stdc++.h>
// FUCK YOU CCF
#define int long long
using namespace std;
const int maxn = 5e5 + 10;

int c, n, m, d, q, w[maxn], k[maxn];
int x, y, a[505][505], t[505][505], ans = LLONG_MAX;
vector<int> e[maxn];

void dfs(int u, int fa, int time) {
    if (fa == y) {
        ans = min(ans, time);
        return ;
    }
    for (auto pos : e[u]) {
        if (pos != fa) {
            time += w[pos];
            time += t[fa][pos];
            dfs(pos, u, time);
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
        for (int j = 2; j <= k[i]; j++) {
            int u = a[i][j], v = a[i][j-1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    while (q--) {
        cin >> x >> y;
        dfs(1, 0, 0);
        cout << ans << endl;
        ans = LLONG_MAX;
    }
    return 0;
}
