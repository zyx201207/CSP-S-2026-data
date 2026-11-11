#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 507, M = 5e5 + 7;
int c, n, m, d, q;
ll f[N][N];
ll w[M];
vector<pair<int, ll> > v[M];
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i ++) f[i][i] = 0;
    for(int i = 1; i <= m; i ++) cin >> w[i];
    for(int i = 1; i <= n; i ++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j ++) {
            int x; ll y;
            cin >> x >> y;
            v[x].push_back({i, y});
        }
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j < v[i].size(); j ++)
            for(int k = 0; k < v[i].size(); k ++) {
                int x = v[i][j].first, y = v[i][k].first;
                ll w1 = v[i][j].second + v[i][k].second;
                f[x][y] = min(f[x][y], w1);
            }
    }
    for(int k = 1; k <= n; k ++) 
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++) 
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
/*    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) {
            cout << i << "," << j << ":" << f[i][j] << endl;
        }*/
    while(q --) {
        int x, y; cin >> x >> y;
        ll ans = 1e18;
        for(auto tmp1 : v[x])
            for(auto tmp2 : v[y]) {
                int u = tmp1.first, v = tmp2.first;
                ll w1 = tmp1.second + tmp2.second;
                ans = min(ans, f[u][v] + w1 + w[x] + w[y]);
            }
        cout << ans << '\n';
    }
    return 0;
}