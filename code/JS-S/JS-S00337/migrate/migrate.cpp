//
#include <bits/stdc++.h>
using namespace std;

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

#define int long long
const int N = 2e6+5, N1 = 305, inf = 0x3f3f3f3f3f3f3f3f;
int n, d, a[N];
int r[N], dis[N], cnt[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, _;
    cin >> c >> _;
    while (_--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (c == 11 || c == 12) {
            int cha = a[2] - a[1];
            if (cha >= d) {
                cout << "0\n";
            } else {
                int ans = n - 2 * d / cha + 1;
                cout << max(ans, 0ll) << '\n';
            }
        } else {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int p = upper_bound(a + i + 1, a + n + 1, a[i] + d) - a;
                r[i] = p - 1;
            }
            for (int i = 1; i <= n; i++) {
                queue<int> q;
                q.push(i);
                for (int j = i; j <= n; j++) {
                    dis[j] = inf;
                    cnt[j] = 0;
                }
                dis[i] = 0;
                cnt[i] = 1;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v = u + 1; v <= r[u]; v++) {
                        if (dis[v] == inf) {
                            dis[v] = dis[u] + 1;
                            cnt[v] = cnt[u];
                            q.push(v);
                        } else if (dis[v] == dis[u] + 1) {
                            cnt[v] += cnt[u];
                        }
                    }
                }
                for (int j = i + 1; j <= n; j++) {
                    ans += cnt[j] == 2;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
