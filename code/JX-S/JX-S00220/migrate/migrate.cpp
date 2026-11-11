#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
int T, n, c;
ll a[N];
ll d, ans;
ll vis[N][N], dis[N][N];
void solve () {
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vis[i][j] = 0;
            dis[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] + d < a[j]) break;
            dis[i][j] = dis[j][i] = 1;
            vis[i][j] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || j == k) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    dis[j][i] = dis[i][j];
                    vis[i][j] = vis[i][k] * vis[k][j];
                    vis[j][i] = vis[i][j];
                } else if (dis[i][j] == dis[i][k] + dis[k][j]) {
                    vis[i][j] += vis[i][k] * vis[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (vis[i][j] == 2) ans++;
        }
    }
    cout << ans << '\n';
}
int main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--) solve ();
    return 0;
}
