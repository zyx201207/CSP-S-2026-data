#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;

int n, m, a[N], d[N], sum[N], sum1[N];
bool flag = 1;
bool check(int i, int t) {
    int cnt = sum1[t - 1] - sum1[i - 1] + (1 - i) * (sum[t - 1] - sum[i - 1]);
    if (cnt <= m) {
        return 1;
    } else {
        return 0;
    }
}
long long solve1() {
    int t = (1 + n) / 2;
    if (n % 2 == 1) {
        int s = sqrt(m);
        if (s >= t) {
            return n;
        } else {
            int p = s * (s - 1);
            if (p + 2 * s <= m) {
                return 2 * s + 1;
            } else if (p + s <= m) {
                return 2 * s;
            } else {
                return 2 * s - 1;

            }
        }
    } else {
        int s = sqrt(m);
        if (s > t) {
            return n;
        } else {
            int p = s * (s - 1);
            if (2 * s - 1 == n) {
                cout << (p + s <= m ? n : n - 1);
            } else {
                if (p + 2 * s <= m) {
                    return 2 * s + 1;
                } else if (p + s <= m) {
                    return 2 * s;
                } else {
                    return 2 * s - 1;
                }
            }
        }
    }
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != i) flag = 0;
    }
    if (flag) {
        cout << solve1();
        return 0;
    }
    sort(a + 1, a + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i <= n - 1) {
            d[i] = a[i + 1] - a[i];
        }
        sum[i] = sum[i - 1] + d[i];
        sum1[i] = sum1[i - 1] + i * d[i];
    }
    for (int i = 1; i + ans <= n; i++) {
        int l = i, r = n, mid = 0;
        while (r > l + 1) {
            mid = (l + r) / 2;
            if (check(i, mid)) {
                l = mid;
            } else {
                r = mid;
            }
            if (check(i, mid) && !check(i, mid + 1)) {
                break;
            }
        }
        if (check(i, l) && !check(i, l + 1)) {
            ans = max(ans, (l - i + 1));
        }
    }
    cout << ans;
    return 0;
}
