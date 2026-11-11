#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 5e5 + 5;

int n, m;
int a[MAX_N];
int sum[MAX_N];
bool flag = 1;

signed main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> n >> m;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = 0;
    }

    sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    if (flag) {
        for (int k = n; k >= 1; k--) {
            __int128 s = k * (k - 1) / 2 * d;
            if (s <= (__int128)m) {
                cout << k << endl;
                return 0;
            }
        }
    } else {
        for (int k = n; k >= 1; k--) {
            for (int i = 1; i <= n - k + 1; i++) {
                __int128 s = (k - 1) * a[i + k - 1] - sum[i + k - 2] + sum[i - 1];
                if ((__int128)m >= s) {
                    cout << k << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
