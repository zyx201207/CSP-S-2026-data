#include <bits/stdc++.h>
using namespace std;
typedef long long LLD;
const int N = 2e6 + 10;
int TASK_ID, t, n, dis[N], f[N], s[N];
LLD d, a[N];

namespace Brute {
    void solve() {
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            dis[i] = 0; f[i] = 1; s[i - 1] = 0; s[i] = 1;
            for (int j = i + 1; j <= n; ++j) { dis[j] = n + 1; f[j] = 0; }
            for (int j = i + 1; j <= n; ++j) {
                int st = lower_bound(a + i, a + j, a[j] - d) - a;
                if (st == j) break;
                int ed = upper_bound(dis + i, dis + j, dis[st]) - dis - 1;
                dis[j] = dis[st] + 1;
                f[j] = min(s[ed] - s[st - 1], 3);
                s[j] = s[j - 1] + f[j];
                ans += (f[j] == 2);
            }
        }
        printf("%lld\n", ans);
    }
}

namespace A {
    bool judge() {
        for (int i = 3; i <= n; ++i)
            if (a[i] - a[i - 1] != a[2] - a[1])
                return 0;
        return 1;
    }
    void solve() {
        long long ans = 0;
        dis[1] = 0; f[1] = 1; s[0] = 0; s[1] = 1;
        for (int i = 2; i <= n; ++i) { dis[i] = n + 1; f[i] = 0; }
        for (int i = 2; i <= n; ++i) {
            int st = lower_bound(a + 1, a + i, a[i] - d) - a;
            if (st == i) break;
            int ed = upper_bound(dis + 1, dis + i, dis[st]) - dis - 1;
            dis[i] = dis[st] + 1;
            f[i] = min(s[ed] - s[st - 1], 3);
            s[i] = s[i - 1] + f[i];
            ans += (f[i] == 2) * (n - i + 1);
        }
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TASK_ID >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n == 1) {
            puts("0");
            continue;
        }
        if (A::judge()) A::solve();
        else if (n <= 5000) Brute::solve();
        else puts("0");
    }
    fflush(stdout); fclose(stdin), fclose(stdout);
    return 0;
}