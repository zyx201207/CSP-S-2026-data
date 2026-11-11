#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 7;
int n, d, dis[N], num[N], x[N], to[N], ans;
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while (T --) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i ++)
            cin >> x[i];
        for (int i = 1, j = 1; i <= n; i ++) {
            while (j < n && x[j + 1] - x[i] <= d)
                j ++;
            to[i] = j;
        }
        for (int i = 1; i <= n; i ++) {
            int u = i;
            while (to[u] != u) {
                if (to[u] - 1 > u)
                    ans += to[to[u] - 1] - to[u];
                if (to[u] - 2 > u)
                    ans -= to[to[u] - 2] - to[u];
                u = to[u];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
