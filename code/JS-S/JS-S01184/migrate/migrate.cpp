#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int c, t;

// Test case: 11~12
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;
    while (t--){
        ll n, d, x, xa, xb, diff;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i){
            cin >> x;
            if (i == 1) xa = x;
            if (i == 2) xb = x;
        }
        diff = abs(xb - xa);

        ll tms = d / diff;
        if (tms <= 1) cout << "0\n";
        else cout << max(0LL, n - (tms * 2 - 1)) << "\n";
    }
    return 0;
}
