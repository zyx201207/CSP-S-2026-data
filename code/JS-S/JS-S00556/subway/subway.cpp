#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500010], k[510], ans, l, r;
vector< pair<int, int> > a[510];
bool flag[500010];
void dfs(int now, int money) {
    if (now == r) {
        ans = min(ans, money);
        return;
    }
    for (int i = 1; i <= m; ++i) {
        bool ok = false;
        int j;
        for (j = 1; j <= k[i]; ++j)
            if (a[i][j].first == now) {
                ok = true;
                break;
            }
        flag[now] = true;
        if (ok)
            for (int p = 1; p <= k[i]; ++p)
                if (p != j && !flag[a[i][p].first])
                    dfs(a[i][p].first, money + a[i][j].second + a[i][p].second);
        flag[now] = false;
    }
}
void solve1() {
    while (q--) {
        cin >> l >> r;
        for (int i = 1; i <= n; ++i)
            flag[i] = false;
        ans = 0x3f3f3f3f;
        dfs(l, 0);
        cout << ans + w[l] + w[r] << endl;
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c;
    cin >> c >> m >> n >> d >> q;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        cin >> k[i];
        a[i].push_back({0, 0});
        for (int j = 1; j <= k[i]; ++j) {
            int t1, t2;
            cin >> t1 >> t2;
            a[i].push_back({t1, t2});
        }
    }
    if (c <= 6)
        solve1();
    return 0;
}
