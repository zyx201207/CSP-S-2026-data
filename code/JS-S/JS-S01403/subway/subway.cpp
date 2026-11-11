#include <bits/stdc++.h>
using namespace std;
#define _N 505
#define N 600005
#define int long long
int n, m, d, q, a[N], dis[_N][_N], ans;
vector<pair<int, int> > eb[N];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> a[i];
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1;i <= n;i++) {
        int k; cin >> k; dis[i][i] = 0;
        for(int j = 1;j <= k;j++) {
            int x, y; cin >> x >> y;
            eb[x].push_back({i, y});
        }
    }
    for(int i = 1;i <= m;i++)
        for(pair<int, int> pr1 : eb[i])
            for(pair<int, int> pr2 : eb[i]) {
                int p1 = pr1.first, w1 = pr1.second;
                int p2 = pr2.first, w2 = pr2.second;
                if(p1 == p2) continue;
                dis[p1][p2] = min(dis[p1][p2], w1 + w2);
                dis[p2][p1] = min(dis[p2][p1], w1 + w2);
            }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= n;k++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--) {
        int x, y; ans = 1e18;
        cin >> x >> y;
        for(pair<int, int> pr1 : eb[x])
            for(pair<int, int> pr2 : eb[y]) {
                int p1 = pr1.first, w1 = pr1.second;
                int p2 = pr2.first, w2 = pr2.second;
                ans = min(ans, w1 + w2 + dis[p1][p2]);
            }
        cout << ans + a[x] + a[y] << endl;
    }
    return 0;
}
