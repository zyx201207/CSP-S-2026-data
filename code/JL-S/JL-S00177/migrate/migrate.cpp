#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;

int n, d;

int a[N];

void solve() {
    cin >> n >> d;
    int tn = n, flg = 1, mn = 114514114;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i > 1) {
            mn = min(mn, a[i] - a[i - 1]);
            if (a[i] - a[i - 1] > d && flg) tn = i - 1, flg = 0;
        }
    }
    if (mn > d) cout << 0 << endl;
    else cout << max(tn - d - 1, 0LL) << endl;
    return ;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c; cin >> c;
    int T = 1; cin >> T;
    while (T--) solve();
    return 0;
}
