#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 510;
const int M = 5010;
int c, n, m, d, q, k[N];
ll w[M], t[N][M];
vector<int> edges[N];

inline void solve() {
    int x, y;
    scanf("%d%d", &x, &y);
    ll ans = w[x] + w[y];
    ll mi = 1 << 30;
    for (int i = 1; i <= n; i++)
        mi = min(mi, t[i][x] + t[i][y]);
    if (mi >= 1 << 30) {
        ll m1 = 1 << 30, m2 = 1 << 30;
        for (int i = 1; i <= n; i++)
            m1 = min(m1, t[i][x]), m2 = min(m2, t[i][y]);
        mi = m1 + m2;
    }
    ans += mi;
    printf("%lld\n", ans);
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    memset(t, 127, sizeof(t));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++) {
            int x, time;
            scanf("%d%d", &x, &time);
            edges[i].push_back(i);
            t[i][x] = time;
        }
    }
    for (; q--; )
        solve();
    return 0;
}
