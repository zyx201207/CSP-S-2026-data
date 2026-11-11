#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//2026CSP-S RP<<=INF

int c, t;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        long long x[n + 5], mp[n + 5][n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            cout << 0 << endl;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[i][j] = abs(x[i] - x[j]);
            }
        }
    }
    return 0;
}
