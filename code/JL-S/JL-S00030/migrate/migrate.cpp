#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
long long d, x[N];
int n, c, t;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t > 0) {
        t --;
        cin >> n >> d;
        for (int i = 1; i <= n; i ++) {
            cin >> x[i];
        }
        cout << n * n - n;
    }

    return 0;
}
