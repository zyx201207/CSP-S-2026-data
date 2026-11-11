#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;

ll c, t, n, d, x[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        if (x[2] - x[1] > d) {
            cout << 0;
            continue;
        }
        cout << 1 << '\n';
    }
    return 0;
}
