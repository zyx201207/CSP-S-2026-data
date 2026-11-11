#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 2e6 + 10;
int c, t, n, toright[N], toleft[N], f[N], g[N], l1[N], r1[N], l2[N], r2[N];
ll d, a[N], sumf[N], sumg[N];
void ckmin(int & x, int y) {
    if (y < x) x = y;
}
void ckmax(int & x, int y) {
    if (y > x) x = y;
}
ll solvesmall() {
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        g[i] = 1;
        for (int j = i + 1; j <= n; j++) {
            f[j] = n + 3;
            g[j] = 0;
            for (int k = i; k < j; k++) if (a[j] - a[k] <= d) {
                if (f[j] > f[k] + 1) f[j] = f[k] + 1, g[j] = g[k];
                else if (f[j] == f[k] + 1) g[j] += g[k];
            }
            if (g[j] == 2) ans++;
        }
    }
    return ans;
}

ll solve() {
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[1] - d - 1;
    a[n + 1] = a[n] + d + 1;
    for (int i = 0, j = 0; i <= n; i++) {
        while (a[j] - a[i] <= d) j++;
        toright[i] = j - 1;
    }
    for (int i = n + 1, j = n + 1; j >= 1; j--) {
        while (a[j] - a[i] <= d) i--;
        toleft[j] = i + 1;
    }
    //for (int i = 1; i <= n; i++) printf("%d ", toright[i]); printf("\n");
    //for (int i = 1; i <= n; i++) printf("%d ", toleft[i]); printf("\n");
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        if (i > 1 && toright[i - 1] == i ) f[i] = f[i - 1] + 1;
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        if (i < n && toleft[i + 1] == i ) g[i] = g[i + 1] + 1;
    }
    //for (int i = 1; i <= n; i++) printf("%d ", f[i]); printf("\n");
    //for (int i = 1; i <= n; i++) printf("%d ", g[i]); printf("\n");
    for (int i = 1; i <= n; i++) sumf[i] = sumf[i - 1] + f[i];
    for (int i = 1; i <= n; i++) sumg[i] = sumg[i - 1] + g[i];
    for (int i = 1; i <= n; i++) {
        l1[i] = l2[i] = n + 1;
        r1[i] = r2[i] = 0;
        //r1[i] = i - 1;
        //l2[i] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        ckmin(l1[toright[i]], i);
        ckmax(r1[toright[i]], i);
        ckmin(l2[toleft[i]], i);
        ckmax(r2[toleft[i]], i);
    }
    for (int i = 1; i <= n; i++) {
        r1[i] = min(r1[i], i - 1);
        l2[i] = max(l2[i], i + 2);
    }
    //for (int i = 1; i <= n; i++) printf("i:%d (%d %d) (%d %d)\n", i, l1[i], r1[i], l2[i], r2[i]);
    ll ans = 0;
    for (int i = 1; i < n; i++) if (l2[i] <= r2[i] && l1[i + 1] <= r1[i + 1]) {
        //for (int j = l1[i + 1] + 1; j <= r1[i + 1]; j++) assert(f[j] == 1);
        //for (int j = l2[i]; j < r2[i]; j++) assert(g[j] == 1);
        ans += (sumf[r1[i + 1]] - sumf[l1[i + 1] - 1]) * (sumg[r2[i]] - sumg[l2[i] - 1]);
    }
    return ans;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        if (n <= 500) cout << solvesmall() << '\n';
        else cout << solve() << '\n';
    }
    return 0;
}
