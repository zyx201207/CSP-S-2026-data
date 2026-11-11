#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
template<typename T> bool chkmax(T& x, const T& y) { return x < y ? x = y, true : false; }
template<typename T> bool chkmin(T& x, const T& y) { return y < x ? x = y, true : false; }

constexpr int inf = 4e18;
constexpr int N = 2e6 + 5;

int c, T, n, d;
int x[N];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        rep(i, 1, n) cin >> x[i];
        if (c == 11 || c == 12) {
            if (n <= 2) {
                cout << "0\n";
                continue;
            }
            int w = x[2] - x[1];
            int k = d / w;
            if (k < 2) {
                cout << "0\n";
                continue;
            }
            cout << max(n - k - (k - 1), 0ll) << '\n';
        } else {
            vector<vector<int>> dis(n + 5, vector<int>(n + 5, inf)),
                cnt(n + 5, vector<int>(n + 5));
            rep(i, 1, n) {
                dis[i][i] = 0;
                cnt[i][i] = 1;
                rep(j, i + 1, n) {
                    if (x[j] - x[i] > d) break;
                    dis[i][j] = 1;
                    cnt[i][j] = 1;
                }
            }
            rep(k, 1, n) {
                rep(i, 1, n) {
                    rep(j, i + 2, n) {
                        if (!(i < k && k < j)) continue;
                        if (dis[i][j] > dis[i][k] + dis[k][j]) {
                            dis[i][j] = dis[i][k] + dis[k][j];
                            cnt[i][j] = cnt[i][k] * cnt[k][j];
                        } else if (dis[i][j] == dis[i][k] + dis[k][j]) {
                            cnt[i][j] += cnt[i][k] * cnt[k][j];
                        }
                    }
                }
            }
            int ans = 0;
            rep(i, 1, n) {
                rep(j, i + 2, n) {
                    if (cnt[i][j] == 2) ++ans;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}