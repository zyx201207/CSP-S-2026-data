// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N = 2e6 + 5;
// int c, t, n, d, a[N], dp[2][N], to[2][N];
// signed main() {
//     freopen("migrate.in", "r", stdin);
//     freopen("migrate.out", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     cin >> c >> t;
//     while (t--) {
//         cin >> n >> d;
//         int ans = 0;
//         for (int i = 1; i <= n; i++) cin >> a[i];
//         a[0] = -2e18, a[n + 1] = 2e18;
//         dp[0][1] = 1, to[0][1] = 1;
//         for (int i = 2; i <= n; i++) {
//             int it = lower_bound(a, a + i + 1, a[i] - d) - a;
//             if (a[it + 1] - a[to[0][it]] > d) dp[0][i] = dp[0][it] + 1, to[0][i] = it;
//             else dp[0][i] = 1, to[0][i] = i;
//         }
//         dp[1][n] = 1, to[1][n] = n;
//         to[1][n + 1] = n + 1;
//         for (int i = n - 1; i >= 1; i--) {
//             int it = upper_bound(a + i, a + n + 2, a[i] + d) - a - 1;
//             if (a[to[1][it]] - a[it - 1] > d) dp[1][i] = dp[1][it] + 1, to[1][i] = it;
//             else dp[1][i] = 1, to[1][i] = i;
//         }
//         for (int i = 2; i < n; i++) {
//             int u = a[i], v = a[i + 1];
//             if (v - u >= d) continue;
//             int it1 = lower_bound(a, a + n + 2, v - d) - a;
//             int it2 = upper_bound(a, a + n + 2, u + d) - a - 1;
//             if (it1 != i && it2 != i + 1) ans += 
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, a[N], dis[N], cnt[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            queue <int> que;
            for (int j = 1; j <= n; j++) dis[j] = 1e18, cnt[j] = 0;
            dis[i] = 0, cnt[i] = 1;
            que.push(i);
            while (!que.empty()) {
                int t = que.front();
                // cout << i << ' ' << t << endl;
                que.pop();
                for (int j = t + 1; j <= n; j++)
                    if (a[j] - a[t] <= d) {
                        if (dis[j] > 5e17) dis[j] = dis[t] + 1, cnt[j] = cnt[t], que.push(j);
                        else if (dis[j] == dis[t] + 1) cnt[j] += cnt[t];
                    } else break;
            }
            for (int j = i + 1; j <= n; j++)
                if (cnt[j] == 2)
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}