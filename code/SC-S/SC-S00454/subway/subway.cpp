#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int w[N];
int t[505][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    multiset<int> g[n + 1];
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x, y;
            cin >> x >> y;
            g[i].insert(x);
            t[i][x] = y;
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = w[x];
        if (x == y) {
            ans += w[x];
            cout << ans << '\n';
            continue;
        }
        int i = x, j;
        for (int l = 1; l <= n; ++l) {
            if (g[l].count(x)) {
                j = l;
                break;
            }
        }
        ans += t[j][i];
        int k;
        for (int l = 1; l <= n; ++l) {
            if (g[l].count(y)) {
                k = l;
                break;
            }
        }
        bool ok = 0;
        while (i != y) {
            if (!ok) {
                ++i;
                ok = 1;
                ans += t[j][i];
                cout << j << ' ' << i << '\n';
            } else {
                ok = 0;
                if (j != k) {
                    ++j, i = 1;
                    cout << j << ' ' << i << '\n';
                    ans += t[j][i];
                }
            }
        }
        ans += w[y];
        cout << ans <<'\n';
    }
    return 0;
}
