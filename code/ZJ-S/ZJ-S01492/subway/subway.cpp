#include<bits/stdc++.h>
#define int long long
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 5e5 + 5, M = 505;
int c, n, m, d, q, w[N], k[M], f[M][M];
vector<int> a[M], t[M];
vector<pair<int, int> > b[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(f, 0x3f, sizeof f);
    rep(i, m) cin >> w[i];
    rep(i, n) {
        cin >> k[i];
        a[i] = t[i] = vector<int>(k[i] + 5, 0ll);
        rep(j, k[i]) {
            cin >> a[i][j] >> t[i][j];
            b[a[i][j]].emplace_back(i, t[i][j]);
        }
        f[i][i] = 0;
    }
    rep(i, m) for(pair<int, int> x : b[i]) for(pair<int, int> y : b[i]) {
        int s = x.first, t = y.first;
        if(s == t) continue;
        f[s][t] = f[t][s] = min(f[s][t], x.second + y.second);
    }
    rep(k, n) rep(i, n) rep(j, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--) {
        int x, y, ans = f[0][0];
        cin >> x >> y;
        for(pair<int, int> i : b[x]) for(pair<int, int> j : b[y]) {
            int s = i.first, t = j.first;
            ans = min(ans, w[x] + w[y] + i.second + j.second + f[s][t]);            
        }
        // if(x == y) ans = 0;
        cout << ans << '\n';
    }
    return 0;
}