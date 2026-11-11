#include <bits/stdc++.h>

using namespace std;
using num = long long;

num n, m;
vector<num> a, s;

bool check(num l, num r) {
    return (r - l + 1) * a[r] - (s[r] - s[l - 1]) <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a.assign(n + 1, 0);
    for (num i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    s.assign(n + 1, 0);
    for (num i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    num ans = 0;
    for (num r = 1; r <= n; ++r) {
        num l = -1;
        for (num l2 = 1, r2 = r; l2 <= r2; ) {
            num mid = l2 + (r2 - l2) / 2;
            if (check(mid, r)) {
                l = mid;
                r2 = mid - 1;
            } else {
                l2 = mid + 1;
            }
        }
//        if (r - l + 1 > ans) {
//            cerr << l << ' ' << r << '\n';
//        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}