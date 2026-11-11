#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500024;
typedef long long ll;

int n;
ll m, a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0, ptr = 1;
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        s += (i - ptr) * (a[i] - a[i - 1]);
        while (s > m) s -= a[i] - a[ptr++];
        if (i - ptr + 1 > ans) ans = i - ptr + 1;
    }
    cout << ans << '\n';
    return 0;
}

// timestamp: 2026/10/31 14:40 (UTC+8)
