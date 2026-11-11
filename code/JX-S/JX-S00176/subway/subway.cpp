#include<bits/stdc++.h>
#define PII pair<int, int>
#define pb emplace_back
#define ll long long
#define fir first
#define sec second
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
using namespace std;
const int N = 502, M = 5e5 + 5;
int c, n, m, d, Q;
vector<PII> vec[M];
ll ans, f[N][N], w[M];
int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
    FOR(i, 1, m) scanf("%lld", &w[i]);
    for (int i = 1, k, x, t; i <= n; i++) {
        scanf("%d", &k);
        FOR(j, 1, k) scanf("%d%d", &x, &t), vec[x].pb(i, t);
    }
    FOR(i, 1, n) FOR(j, 1, n) f[i][j] = 1e17;
    FOR(i, 1, n) f[i][i] = 0;
    FOR(i, 1, m) {
        for (PII x : vec[i]) for (PII y : vec[i]) if (x.fir != y.fir) f[x.fir][y.fir] = f[y.fir][x.fir] = min(f[x.fir][y.fir], (ll)x.sec + y.sec);
    }
    FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1, x, y; i <= Q; i++) {
        scanf("%d%d", &x, &y), ans = 1e17;
        for (PII S : vec[x]) for (PII T : vec[y]) ans = min(ans, f[S.fir][T.fir] + S.sec + T.sec);
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}