#include <bits/stdc++.h>

using namespace std;

long long c, t;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        long long n, d, x1, x2;
        cin >> n >> d >> x1 >> x2;
        if(d < 2*(x2-x1)) {
            cout << "0\n";
        } else if(d < 3*(x2-x1)) {
            cout << n-2 << '\n';
        } else {
            cout << d/(x2-x1) << '\n';
        }
    }
    return 0;
}
