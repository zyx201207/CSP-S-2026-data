#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 8, M = 3e3 + 8;
int n, m, a[N], cnt[M];
bool dp[M][M], vis[M];
bool check() {
    for (int i = 2; i <= n; i++)
        if (a[i - 1] > a[i]) return 0;
    return 1;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--) cnt[a[i]]++;
    if (check()) {
        int sum = 0;
        for (int i = 1; i <= m; i++) sum += cnt[i], printf("%d ", sum);
        return 0;
    }
    for (int i = 1; i <= m; i++) dp[i][i] = 1;
    for (int i = n; i >= 1; i--) {
        if (vis[a[i]]) continue;
        vis[a[i]] = 1;
        for (int j = 1; j <= m; j++) dp[a[i]][j] |= dp[a[i + 1]][j];
    }
    for (int i = 1; i <= m; i++) {
        int ans = 0;
        for (int j = 1; j <= m; j++) ans += dp[j][i] * cnt[j];
        printf("%d ", ans);
    }
    return 0;
}
