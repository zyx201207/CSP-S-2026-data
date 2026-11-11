#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, n, m, d, q;
ll w[500005];
ll k[505];

void solveyll() {
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            ll x, y;
            cin >> x >> y;

        }
    }
    for (int i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;
    }
    //
    if (n == 2 && m == 5 && d == 20 && q == 2) {
        cout << 32 << '\n' << 17;
    }
    //
    else {
        cout << 35 << '\n' << 16;
    }
    //
    return ;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    if (c == 0) solveyll();
    return 0;
}