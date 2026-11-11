#include <bits/stdc++.h>
using namespace std;
const int M = 500010, N = 510;

long long f[N][N];
int c, n, m, d, q, w[M], k[N], lsta[M];
pair <int, int> sta[M][22];
vector <pair <int, int>> to[N];

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1, x, y; j <= k[i]; j++)
            cin >> x >> y, to[i].push_back({x, y}),
            lsta[x]++, sta[x][lsta[x]].first = i, sta[x][lsta[x]].second = y;
    }
    for (int i = 1; i <= m; i++)
        sort(sta[i] + 1, sta[i] + lsta[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = (1ll << 60);
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            for (auto id : to[i]) {
                int x = id.first, y = id.second;
                int L = 0, R = lsta[x] + 1;
                while (L + 1 < R) {
                    int M = (L + R) >> 1;
                    if (sta[x][M].first < j)
                        L = M;
                    else
                        R = M;
                }
                if (sta[x][R].first != j)
                    continue;
                f[i][j] = min(f[i][j], 1ll * y + sta[x][R].second);
            }
        }
    for (int mid = 1; mid <= n; mid++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][mid] + f[mid][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        long long ans = (1ll << 60);
        for (int i = 1; i <= lsta[x]; i++) {
            int posx = sta[x][i].first;
            for (int j = 1; j <= lsta[y]; j++) {
                int posy = sta[y][j].first;
                ans = min(ans, f[posx][posy] + w[x] + w[y] + sta[x][i].second + sta[y][j].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
