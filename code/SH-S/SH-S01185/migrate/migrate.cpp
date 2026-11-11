#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int c, t, n, d, x[N];
int e[N][N], cnt[N][N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t; // assert(c <= 6);
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        memset(e, 0x3f, sizeof(e));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) e[i][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                if (x[j] - x[i] > d) break;
                e[i][j] = cnt[i][j] = 1;
            }
        for (int i = 1; i <= n - 2; i++)
            for (int j = i + 2; j <= n; j++)
                for (int k = i + 1; k <= j - 1; k++) {
                    if (e[i][k] + e[k][j] < e[i][j])
                        e[i][j] = e[i][k] + e[k][j], cnt[i][j] = cnt[i][k] * cnt[k][j];
                    else if (e[i][k] + e[k][j] == e[i][j])
                        e[i][j] = e[i][k] + e[k][j], cnt[i][j] += cnt[i][k] * cnt[k][j];
                    cnt[i][j] = min(cnt[i][j], 3);
                }
        int ans = 0;
        for (int i = 1; i <= n - 1; i++)
            for (int j = i + 1; j <= n; j++)
                ans += cnt[i][j] == 2;
        cout << ans << endl;
    }
    return 0;
}