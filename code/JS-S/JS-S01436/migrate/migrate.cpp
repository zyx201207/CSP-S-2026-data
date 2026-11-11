#include <bits/stdc++.h>
using namespace std;
long long a;
int main() {
    freopen("migrate4.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        long long n, d;
        cin >> n >> d;
        long long x, y;
        cin >> x >> y;
        for (int i = 1; i <= n - 2; i++)
            cin >> a;
        long long tot = (y - x < 0 ? x - y : y - x);
        if(tot > d / 2 || d / tot * 2 > n - 1) {
            cout << 0 << endl;
        } else {
            cout << n - d / tot * 2 + 1 << endl;
        }
    }
    return 0;
}
