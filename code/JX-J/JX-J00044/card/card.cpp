#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 5, M = 3000 + 5;
int n, m;

bitset<M> dp[N];
int a[N], ans[M];
int nxt[N], nxtt[M];

int main() {
    ios::sync_with_stdio(false);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        nxt[i] = nxtt[a[i]];
        nxtt[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        int lst = 0;
        if (nxt[i]) {
            lst = nxt[i];
        } else {
            lst = i + 1;
        }
        dp[i] = dp[lst];
        dp[i][a[i]] = 1;
        for (int j = 1; j <= m; j++) {
            if (dp[i][j]) {
                ans[j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i];
        if (i != m) cout << ' ';
    }
    cout << '\n';
    return 0;
}
