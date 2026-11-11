#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &xs, int &n, int &d, int f, int e, vector<vector<int>> &ps) {
    if (ps[f][e] != -1) return ps[f][e];
    if (e-f == 1) {
        ps[f][e] = (xs[e]-xs[f] == 1);
        return ps[f][e];
    }
    int cnt = 0;
    if (xs[e]-xs[f] == 1) cnt ++;
    for (int i = f+1; i < e; i ++) {
        cnt += dfs(xs, n, d, f, i, ps)*dfs(xs, n, d, i, e, ps);
    }
    ps[f][e] = cnt;
    return ps[f][e];
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t; cin >> c >> t;
    while (t --) {
        int n, d; cin >> n >> d;
        vector<int> xs(n);
        for (int i = 0; i < n; i ++) {
            cin >> xs[i];
        }
        vector<vector<int>> ps(n, vector<int>(n, -1));
        dfs(xs, n, d, 0, n-1, ps);
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (ps[i][j] == 2) cnt ++;
            }
        }
        cout << cnt << "\n";

        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for (int i = 0; i < n; i ++) {
        //     dp[i][i] = 1;
        //     for (int j = i+1; j < n; j ++) {
        //         if (xs[j] - xs[i] <= d) {
        //             dp[i][j] += dp[i][i];
        //         } else break;
        //     }
        // }
        // for (int i = 0; i < n; i ++) {
        //     for (int j = i+1; j < n; j ++) {
        //         for (int k = i; k <= j; k ++) {
        //             dp[i][j] += dp[i][k]*dp[k][j];
        //         }
        //     }
        // }

        // int cnt = 0;
        // for (int i = 0; i < n; i ++) {
        //     for (int j = i+1; j < n; j ++) {
        //         cout << dp[i][j] << "\t";
        //         if (dp[i][j] == 2) cnt ++;
        //     }
        //     cout << "\n";
        // }
        // cout << cnt;
    }
    return 0;
}