#include <bits/stdc++.h>
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
using namespace std;

const int N = 2e6 + 6;
int c, t, n, d, x[N], f[N], g[N];

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while (t --){
        cin >> n >> d;
        fr(i, 1, n) cin >> x[i];
        if (n == 1){ cout << "0\n"; continue; }
        if (c == 11 || c == 12){
            int D = x[2] - x[1], p = d / D;
            cout << max(0ll, (p >= 2) * (n + 1 - p * 2)) << "\n";
            continue;
        }
        int ans = 0;
        fr(k, 1, n){
            f[k] = g[k] = 0;
            fr(i, k + 1, n){
                f[i] = LLONG_MAX, g[i] = 0;
                int st = max(k, (long long)(lower_bound(x + 1, x + n + 1, x[i] - d) - x));
                fr(j, st, i - 1){
                    if (f[j] + 1 < f[i]) f[i] = f[j] + 1, g[i] = 1;
                    else if (f[j] + 1 == f[i]) g[i] ++;
                }
                ans += g[i] == 2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

// coding is so tiring, meow.
// I dont wanna learn oi anymore
// I admit I just wanna play computer
// but should I miss the days? sure
// maybe afo after this exam
// 50min to end
// ai, xie bu lai
// finished N <= 300 but WA, and spe A, at 18:15, 8pts got.