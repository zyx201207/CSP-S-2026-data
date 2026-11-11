#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500010], l[510];
int cnt[500010], bel[500010][30], t[500010][30];
long long f[510][510];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        for (int j = 1; j <= l[i]; j++) {
            int x, y;
            cin >> x >> y;
            cnt[x]++;
            bel[x][cnt[x]] = i;
            t[x][cnt[x]] = y;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = 1ll << 62;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= cnt[i]; j++)
            for (int k = j + 1; k <= cnt[i]; k++)
                f[bel[i][j]][bel[i][k]] = min(f[bel[i][j]][bel[i][k]], 1ll * t[i][j] + t[i][k]),
                f[bel[i][k]][bel[i][j]] = f[bel[i][j]][bel[i][k]];
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (f[i][k] < 1ll << 62 && f[k][j] < 1ll << 62)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (; q--; ) {
        int x, y;
        cin >> x >> y;
        long long ans = 1ll << 62;
        for (int i = 1; i <= cnt[x]; i++)
            for (int j = 1; j <= cnt[y]; j++)
                ans = min(ans, f[bel[x][i]][bel[y][j]] + w[x] + w[y] + t[x][i] + t[y][j]);
        cout << ans << "\n";
    }
    return 0;
}
