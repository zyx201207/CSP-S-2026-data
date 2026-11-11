#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 100;
#define int long long
int n, d;
int a[N];
int f[N];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i+1; j <= n; j ++) {
            for (int k = 0; k <= n; k ++) f[k] = 0;
            for (int mask = 0; mask < (1 << n); mask ++) {
                int cnt = 0;
                int pre = a[i];
                bool flag = true;
                for (int k = 1; k <= n; k ++) {
                    if ((mask >> (k-1)) & 1 and !(i<=k and k<=j)) {
                        flag = false; break;
                    }
                    if ((mask >> (k-1)) & 1) {
                        if (a[k] - pre <= d) {
                            pre = a[k];
                            cnt ++;
                        } else {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag and a[j] - pre <= d) {
                    f[cnt] ++;
                     //cerr << i << " and " << j << " Have a good answer : " << mask << ' ' << cnt << endl;
                }
            }
            //cerr << "Now is " << i << " and " << j << endl;
            for (int k = 0; k <= n; k ++) {
                //cerr << f[k] << ' ';
                if (f[k]) {
                    if (f[k] == 2) ans ++;
                    break;
                }
            }
            //cerr << endl;
        }
    }
    cout << ans << endl;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t; cin >> c >> t;
    while (t --) solve();
    return 0;
}
