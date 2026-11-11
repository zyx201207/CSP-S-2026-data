#include <bits/stdc++.h>
#define int long long
using namespace std;
int cas, T, n, d, a[2000005], f[2000005][3], nxt[2000005], pre[2000005];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> cas >> T;
    while (T--) {
        // cerr<<"=======\n";
        cin >> n >> d;
        for (int i=1;i<=n;i++) cin >> a[i];
        int cur = 1;
        for (int i=1;i<=n;i++) {
            while (cur < n && a[cur+1]-a[i] <= d) cur++;
            nxt[i] = cur;
        }
        cur = 1;
        for (int i=1;i<=n;i++) {
            while (a[i]-a[cur] > d) cur++;
            pre[i] = cur;
        }
        int res = 0;
        f[n][0] = 0;
        f[n][1] = f[n][2] = 0;
        for (int i=n-1;i>=1;i--) {
            int l = i<=2 ? 0 : nxt[i-2]+1, r = i==1 ? 0 : nxt[i-1];
            f[i][0] = f[i][1] = f[i][2] = 0;
            f[i][0] = f[nxt[i]][0] + nxt[i]-max(r, i);
            if (pre[nxt[i]] == i) {
                f[i][1] = f[nxt[i]][1];
                if (pre[nxt[i]-1] == i) f[i][1] += f[nxt[i]][2];
                res += f[nxt[i]][1] + f[nxt[i]][2];
            }
            if (pre[nxt[i]] == i-1) f[i][2] = f[nxt[i]][0];
            f[i][2] += max(r, i) - max(l, i+1) + 1;
            // cerr << i << " : " << f[i][0] << " " << f[i][1] << " " << f[i][2] << "\n";
            // cerr << l << " " << r << "\n";
            // nxt[i-2]+1 ~ nxt[i-1]
        }
        cout << res << "\n";
    }
    return 0;
}