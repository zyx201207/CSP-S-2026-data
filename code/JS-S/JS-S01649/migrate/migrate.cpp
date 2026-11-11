#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

long long c, t, n, d, x[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --) {
        for (int i = 1; i <= n; i ++) {
            cin >> x[i]; 
        }
        long long idx = 1, minn  = 1;
        while(idx * (x[n] - x[n - 1]) <= d && idx <= n - 1) idx++;
        idx --;
        if(idx == 0) cout << 0 << "\n";
        if(idx == 1) cout << 0 << "\n";
        else if(idx == 2) {
            cout << n - 3 << "\n";
        } else { 
            long long ans = 0;
            for (int i = 1; i <= n - 1; i ++) {
                if(i <= idx) continue;
                if(i / idx >= 3) continue;
                if (i % idx == idx - 1) ans += n - i;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}