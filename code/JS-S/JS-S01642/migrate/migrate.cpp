#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e6 + 5;

int n, p[N], q[N];
ll pos[N], d;
int f[N][3];

void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", &pos[i]);
    for (int i = n, j = n; i; i--) {
        while (pos[j] - pos[i] > d) j--;
        p[i] = j, f[i][0] = f[i][1] = f[i][2] = 0;
    }
    for (int i = 1, j = 1; i <= n; i++) {
        while (pos[i] - pos[j] > d) j++;
        q[i] = j;
    }
    for (int i = n; i; i--) {
        if (p[i] == i) continue;
        int j = p[i], k = p[p[i]];
        f[i][0] = k - p[j - 1];
        if (j > i + 1) f[i][2] = p[j - 1] - p[j - 2];
        if (k != j) {
            int cnt = 0;
            if (j == i + 1 || p[j - 1] < k) cnt = 1;
            else if (j == i + 2 || p[j - 2] < k) cnt = 2;
            else cnt = 3;
            if (cnt == 1) f[i][0] += f[j][0];
            else if (cnt == 2) f[i][2] += f[j][0];
            if (cnt == 1) {
                f[i][1] += f[j][1];
                if (q[k - 1] == j) {
                    f[i][1] += f[j][2];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i][1] + f[i][2];
    }
    // for (int i = 1; i <= n; i++) printf("%d%c", p[i] , " \n"[i == n]);
    // for (int i = 1; i <= n; i++) printf("%d %d %d %d\n", i, f[i][0], f[i][1], p[i]);
    printf("%lld\n", ans);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int Cid, T; scanf("%d%d", &Cid, &T);
    while (T--) solve();
    return 0;
}