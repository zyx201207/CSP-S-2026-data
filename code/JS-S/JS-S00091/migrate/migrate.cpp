#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5005;
int C, T, n, d, x[N], dis[N][N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> C >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = 1e18;
        for (int i = 1; i <= n; i++) dis[i][i] = 0;
        for (int i = 1; i <= n; i++) {
            int p = x[i], j = i + 1, step = 1;
            while (j <= n) {
                if (x[j] > p + d) break;
                while (j <= n && x[j] <= p + d) dis[i][j++] = step;
                p = x[j - 1];
                step++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                int cnt = 0;
                for (int k = i + 1; k < j; k++)
                    if (dis[i][k] + dis[k][j] == dis[i][j]) cnt++;
                if (cnt == 2) ans++;
            }
        cout << ans << '\n';
    }
    return 0;
}