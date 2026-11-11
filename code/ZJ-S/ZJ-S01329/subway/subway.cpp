#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 505, M = 5e5 + 10;
const i64 INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
int w[M];
vector<pair<int, int> > G[M];
i64 f[N][N];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin.tie(0)->sync_with_stdio(false);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a, t;
            cin >> a >> t;
            G[a].push_back({i, t});
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (auto [X, Y] : G[i]) for (auto [L, R] : G[i]) {
            f[X][L] = min(f[X][L], 0ll + Y + R);
        }
    }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        int s, t;
        cin >> s >> t;
        i64 ans = INF;
        for (auto [X, Y] : G[s]) for (auto [L, R] : G[t]) {
            ans = min(ans, 0ll + f[X][L] + Y + R);
        }
        cout << ans + w[s] + w[t] << '\n';
    }
    return 0;
}