#include <bits/stdc++.h>

using namespace std;

long long n, m, a[114514], maxn = -1, maxs = -1, all = 1, t = 111111111111111111111111111111;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxs = max(maxs, a[i]);
        all = all & a[i];
    }

    if (m == 1) {
        cout << maxs;
        return 0;
    } else if (m == n) {
        cout << all;
        return 0;
    } else if (m == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + i; j++) {
                t &= a[j] & a[i];
                maxn = max(t, maxn);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < m + i; j++) {
            t &= a[j] & a[i];
            maxn = max(t, maxn);
        }
    }

    cout << maxn;

    return 0;
}



