#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int q[N], c[N], ans[N], maxx = -1;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    bool op = 1;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    sort(q + 1, q + n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = q[i] - q[i - 1];
        if (i >= 3 && c[i] != c[i - 1]) {
            op = 0;
        }
    }
    c[1] = 0;
    if (op) {
        if (c[2] == 1) {
            for (int i = 1; i <= n; i++) {
                m -= i;
                if (m < 0) {
                    cout << i << endl;
                    return 0;
                }
            }
            cout << n;
            return 0;
        }
        else {
            int num = 0;
            for (int i = c[2]; ; i += c[2]) {
                m -= i;
                num++;
                if (m < 0) {
                    cout << num << endl;
                    return 0;
                }
            }
        }
    }
    q[0] = -1e12 + 5;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (l <= r - 2) {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * q[i] - (ans[i] - ans[mid - i]) <= m) r = mid;
            else l = mid;
        }
        maxx = max(maxx, i - r + 1);
    }
    cout << maxx;
    return 0;
}
