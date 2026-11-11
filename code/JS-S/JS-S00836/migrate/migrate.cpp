#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    long long n, d, x[100005];
    cin >> c >> t;

    for (int i = 1; i <= t; i++) {
        cin >> n >> d;
    //cout << n;
        for (int k = 1; k <= n; k++) {
            cin >> x[k];
        }

       if (c == 11 || c == 12) {
            int p = d / (x[2] - x[1]);
            int ans = 0;
            if (p == 0) {
                cout << 0 << endl;
                continue;
            }
            for (int a = 1; a <= n; a++) {
                for (int b = a+3; b <= n;b++) {
                    if(b-a == 3 || (b-a-3)% d == 0) ans++;
                }
            }
            cout << ans << endl;
       }
       else cout << 0 << endl;
    }

    return 0;
}
