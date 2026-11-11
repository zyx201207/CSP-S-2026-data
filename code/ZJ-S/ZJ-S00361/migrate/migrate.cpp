#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    using ll = long long;
    using pii = pair<int, int>;
    const int N = 5005;
    const ll inf = 1e18;
    int n, d;
    ll x[N];
    ll cnt[N][N], dis[N][N];
    inline void bfs(int s) {
        queue<pii> q;
        q.push({s, 0});
        while (q.size()) {
            auto [u, w] = q.front(); q.pop();
            if (w > dis[s][u]) continue;
            if (w == dis[s][u]) {
                cnt[s][u]++;
                continue;
            }
            dis[s][u] = w;
            cnt[s][u]++;
            ll mx = min(x[n], x[u] + d), mn = max(x[1], x[u] - d);
            int l = lower_bound(x + 1, x + 1 + n, mn) - (x + 1);
            while (x[l] < mn && l < n) l++;
            int r = upper_bound(x + 1, x + 1 + n, mx) - (x + 1);
            while (x[r] > mx && r > 1) r--;
            for (int i = l; i <= r; i++) {
                if (w + 1 > dis[s][i]) continue;
                q.push({i, w + 1});
            }
        }
    }    
    inline void solve() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            for (int j = 1; j <= n; j++) dis[i][j] = inf, cnt[i][j] = 0;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            bfs(i);
            for (int j = i + 1; j <= n; j++) {
                if (cnt[i][j] >= 2) ans++;
            }
        }
        cout << ans << '\n';
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    IOS;
    int c, t = 1;
    cin >> c >> t;
    while (t--) Mort1s::solve();
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


4:00 开始开 T3。
4:47 多测要清空/ll
*/