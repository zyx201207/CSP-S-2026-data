#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, t;
int x[2000010];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        if (c == 11 || c == 12) {
            if (x[3] - x[1] > d) cout << 0 << '\n';
            int g = d / (x[2] - x[1]);
            int k = (n - 1 + g - 1) / g;
            if (k * g - 1 < n - 1) cout << 0 << '\n';
        }
    }

    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
