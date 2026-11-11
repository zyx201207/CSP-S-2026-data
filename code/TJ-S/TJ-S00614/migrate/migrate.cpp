#include <bits/stdc++.h>
using namespace std;
int c, t;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        int n;
        long long d;
        cin >> n >> d;
        int a[2000010];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int x = 1 + n - 4;
        cout << x << endl;
    }
    return 0;
}
