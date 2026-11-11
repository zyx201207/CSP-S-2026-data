#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
template<typename T> bool chkmax(T& x, const T& y) { return x < y ? x = y, true : false; }
template<typename T> bool chkmin(T& x, const T& y) { return y < x ? x = y, true : false; }

constexpr int M = 5e5 + 5;
constexpr int N = 505;
constexpr int inf = 1e18;

int c, n, m, D, Q;
int w[M], k[N], d[N][N];
vector<int> a[N], t[N];
vector<pair<int, int>> s[M];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(d, 0x3f, sizeof(d));
    cin >> c >> n >> m >> D >> Q;
    rep(i, 1, m) cin >> w[i];
    rep(i, 1, n) d[i][i] = 0;
    rep(i, 1, n) {
        cin >> k[i];
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        rep(j, 0, k[i] - 1) {
            cin >> a[i][j] >> t[i][j];
            for (auto k : s[a[i][j]]) {
                int v = k.first, tv = k.second;
                chkmin(d[i][v], t[i][j] + tv);
                chkmin(d[v][i], t[i][j] + tv);
            }
            s[a[i][j]].push_back({i, t[i][j]});
        }
    }
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                chkmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while (Q--) {
        int x, y, ans = inf;
        cin >> x >> y;
        for (auto i : s[x]) {
            for (auto j : s[y]) {
                chkmin(ans, i.second + d[i.first][j.first] + j.second);
            }
        }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}