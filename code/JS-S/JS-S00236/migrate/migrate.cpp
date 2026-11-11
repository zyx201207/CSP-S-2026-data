#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define int long long
using namespace std;
int pos[5005];
vector<int> nb[5005];
pii dp[5005][5005]; //n,from:{minstep,number}
void slv() {
    int n, d, res = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < 5005; i++) {
        nb[i].clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pos[j] - pos[i] <= d) {
                nb[i].pb(j);
            }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = {0, 1};
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            dp[k][k] = {0, 1};
            for (auto j : nb[i]) {
                if (dp[j][k].first > dp[i][k].first + 1) {
                    dp[j][k] = {dp[i][k].first + 1, dp[i][k].second};
                } else if (dp[j][k].first == dp[i][k].first + 1) {
                    dp[j][k].second++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            //clog << dp[i][k].first << " " << dp[i][k].second << endl;
            if (dp[i][k].second == 2) {
                res++;
            }
        }
    }
    //clog << endl;
    cout << res << endl;
}
void slvA() {
    int n, d, x1, x2, l1;
    cin >> n >> d;
    if (n == 1) {
        cin >> l1;
        cout << 0 << endl;
        return;
    }
    cin >> x1 >> x2;
    for (int i = 2; i < n; i++) {
        cin >> l1;
    }
    int cha = x2 - x1;
    if (cha > d) {
        cout << 0 << endl;
        return;
    } else if (2 * cha > d) {
        cout << 0 << endl;
        return;
    } else if (3 * cha > d) {
        cout << 1 << endl;
        return;
    } else {
        cout << 0 << endl;
        return;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        if (c == 11 || c == 12) {
            slvA();
        } else {
            slv();
        }
    }
    return 0;
}