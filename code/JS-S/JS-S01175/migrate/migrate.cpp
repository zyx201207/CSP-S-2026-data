#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 8;
int TEST, T, n, minn;
long long d, ans, a[N], num;
void dfs(int u, int ed, int cnt) {
    if (u == ed) {
        if (cnt == minn) num++;
        else if (cnt < minn) minn = cnt, num = 1ll;
        return;
    }
    if (u > ed) return;
    for (int v = u + 1; v <= ed && abs(a[v] - a[u]) <= d; v++)
       dfs(v, ed, cnt + 1);
    return;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &TEST, &T);
    while (T--) {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                minn = 2e9, num = 0ll;
                dfs(i, j, 0);
                ans += (num == 2ll);
        }
        printf("%lld\n", ans);
        ans = 0ll;
    }
    return 0;
}
