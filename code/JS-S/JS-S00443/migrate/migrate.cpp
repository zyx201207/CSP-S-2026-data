#include <bits/stdc++.h>
using namespace std;

const int N = 2000010;
int c, t, n, mind, cnt;
long long d, x[N];

void dfs(int p, int pos, int id) {
    if (p > mind) return ;
    if (x[pos] == x[id]) {
        if (p < mind) {
            mind = p;
            cnt = 1;
        } else  ++cnt;
        return ;
    }
    for (int i = pos + 1; i <= n && x[i] - x[pos] <= d; i++)
        dfs(p + 1, i, id);
}
void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mind = n + 1, cnt = 0;
            dfs(1, i, j);
            if (cnt == 2) ++ans;
        }
    }
    printf("%d\n", ans);
}

void solve2() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    int ans = 0;
    vector<int> dp(n + 1, n + 1);
    vector<int> dp2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i; j <= n; j++)
            for (int k = j - 1; k >= i && x[j] - x[k] <= d; --k)
                dp[j] = min(dp[j], dp[k] + 1);
        dp2[i] = 1;
        for (int j = i; j <= n; j++) {
            for (int k = j - 1; k >= i && x[j] - x[k] <= d; --k)
                if (dp[k] == dp[j] - 1)
                    dp2[j] += dp2[k];
            if (dp[j] == 2) ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        if (c == 1 || c == 2)
            solve();
        else
            solve2();
    }
    return 0;
}
