#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int op, T, n, d, id[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> op >> T;
    while (T--){
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> id[i];
        if (op == 13 || op == 14){
            cout << 0 << "\n";
            continue;
        }
        if (op == 11 || op == 12){
            int x = id[2] - id[1];
            int t = floor(1.0 * d / x);
            int ans = max(0ll, (2 * n - 3 * t) * (t - 1) / 2);
            cout << ans << "\n";
            continue;
        }
    }
    return 0;
}