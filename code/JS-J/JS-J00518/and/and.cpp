#include <bits/stdc++.h>

using namespace std;

using lld = long long;

bool block[200007];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    lld n, m;
    cin >> n >> m;

    vector<int> a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0xffffffff;
    for (int j = 31; j >= 0; j--) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (((a[i] >> j) & 1) && !block[i]) {
                cnt++;
            } else {

            }
        }

        if (cnt >= m) {
            for (int i = 1; i <= n; i++) {
                if (((a[i] >> j) & 1) && !block[i]) {

                } else {
                    block[i] = 1;
                }
            }
        } else {
            ans &= ~(1 << j);
        }
    }

    cout << ans << endl;


    return 0;
}