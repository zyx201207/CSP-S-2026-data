#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];
int sum[N];

bool check(int x) {
    for (int i = x; i <= n; i++)
        if (a[i] * x - (sum[i] - sum[i - x]) <= m)
            return true;

    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;

    return 0;
}
