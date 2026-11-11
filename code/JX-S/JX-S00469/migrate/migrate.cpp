#include <bits/stdc++.h>
#define int long long
using namespace std;

int T = 1, c;
const int N = 5e3 + 10;
int n, d;
int arr[N];
int dp[N][N], dis[N][N];

void Solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dis, 127, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] - arr[i] <= d) {
                dis[i][j] = 1;
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            for (int k = j + 1; k <= i - 1; k++) {
                if (dis[j][k] <= d && dis[k][i] <= d) {
                    if (dis[j][i] > dis[j][k] + dis[k][i]) {
                        dis[j][i] = dis[j][k] + dis[k][i];
                        dp[j][i] = 1;
                    } else if (dis[j][i] == dis[j][k] + dis[k][i]) dp[j][i]++;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dp[i][j] == 2) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
