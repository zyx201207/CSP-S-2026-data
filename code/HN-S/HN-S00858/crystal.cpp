#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 10;

ll a[N], s[N];
ll m;

bool Check(int l, int r) {
    return a[r] * (r - l + 1) - s[r] + s[l - 1] <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    int ans = 0, l = 1;
    for (int r = 1; r <= n; ++r) {
        while (l <= r && !Check(l, r)) ++l;
        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
}