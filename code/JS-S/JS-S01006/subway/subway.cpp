#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int c, n, m, d, q;
int w[N], k[505];
int v[N][505];
int dp[505][505];
vector<int> g[N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i ++) {
        dp[i][i] = 0;
        for (int j = i + 1; j <= n; j ++) {
            dp[i][j] = dp[j][i] = -1;
        }
    }
    for (int i = 1; i <= m; i ++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j ++) {
            int a, t;
            cin >> a >> t;
            v[a][i] = t;
            for(int l:g[a]) {
                if (dp[i][l] == -1 || dp[i][l] > v[a][i] + v[a][l]) {
                    dp[i][l] = dp[l][i] = v[a][i] + v[a][l];
                }
            }
            g[a].push_back(i);
        }
    }
    for (int l = 1; l <= n; l ++) {
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if (l == i || l == j) {
                    continue;
                }
                if (dp[i][l] == -1 || dp[l][j] == -1) {
                    continue;
                }
                if (dp[i][j] == -1 || dp[i][j] > dp[i][l] + dp[l][j]) {
                    dp[i][j] = dp[j][i] = dp[i][l] + dp[l][j];
                }
            }
        }
    }
    while(q --) {
        int x, y;
        cin >> x >> y;
        int ans = -1;
        for (int i:g[x]) {
            for (int j:g[y]) {
                if (v[x][i] == -1 || v[y][j] == -1) {
                    continue;
                }
                if (ans == -1 || ans > dp[i][j] + v[x][i] + v[y][j]) {
                    ans = dp[i][j] + v[x][i] + v[y][j];
                }
            }
        }
        ans += w[x] + w[y];
        cout << ans <<endl;
    }
    return 0;
}
