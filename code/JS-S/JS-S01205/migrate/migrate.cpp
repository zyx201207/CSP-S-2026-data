// Arknighs Endfield
// rossi i love you

#include <bits/stdc++.h>
using namespace std;

#define range(v, l, r) next(begin(v), l), next(begin(v), r+1)
#define range_full(v) begin(v), end(v)

int64_t c, t;
int64_t n, d;
array<int64_t, size_t(2e6+5)> x;
array<array<int64_t, size_t(5005)>, size_t(505)> g, cc;

int32_t main() {
    ignore = freopen("migrate.in", "r", stdin);
    ignore = freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> t;
    for (int64_t i=1; i<=t; i++) {
        cin >> n >> d;
        bool flagA{1};
        for (int64_t j=1; j<=n; j++) {
            cin >> x[j];
            flagA &= (x[j]-x[j-1] == x[j-1]-x[j-2]);
        }
        if (c == 11 || c == 12 || flagA) {
            // cout << "entered A\n";
            int64_t diff = x[2]-x[1];
            if (d <= diff) {
                cout << "0\n";
            }
            else {
                int64_t sq = d/diff*2;
                if (sq > n) {
                    cout << "0\n";
                }
                else {
                    cout << n-sq+1 << "\n";
                }
            }
        }
        else {
            for (int64_t i=1; i<=n; i++) {
                fill(range_full(g[i]), 0x3f3f3f3f3f3f3f3f);
                fill(range_full(cc[i]), 0);
                for (int64_t j=i+1; j<=n; j++) {
                    if (x[j]-x[i] <= d) {
                        g[i][j] = 1;
                    }
                }
            }
            for (int64_t k=1; k<=n; k++) {
                for (int64_t i=1; i<=n; i++) {
                    for (int64_t j=1; j<=n; j++) {
                        if (g[i][k] + g[k][j] <= g[i][j]) {
                            if (g[i][k] + g[k][j] == g[i][j]) {
                                cc[i][j]++;
                            }
                            g[i][j] = g[i][k] + g[k][j];
                        }
                    }
                }
            }
            int64_t ans{};
            for (int64_t i=1; i<=n; i++) {
                for (int64_t j=i+1; j<=n; j++) {
                    ans += (cc[i][j] == 1);
                }
            }
            cout << ans << "\n";
        }
    }
    

    return 0;
}