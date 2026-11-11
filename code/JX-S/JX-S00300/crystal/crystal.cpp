#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

using ll = long long;

int n;
ll m;
ll a[N], sum[N];

bool check(int l) {
    bool flag = false;
    for (int i = n; i >= l; i--) {
        if (a[i] * (l - 1) - sum[i - 1] + sum[i - l] <= m) {
            flag = true;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}

// Don't guafen!!!