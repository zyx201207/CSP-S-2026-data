#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)

void tomax(int& x, int y) {
    x = max(x, y);
}

constexpr int MAXN = 5e5 + 5;
int n, m;
int a[MAXN], pre[MAXN];
int calc(int l, int r) {
    int len = r - l + 1;
    return a[r] * len - (pre[r] - pre[l - 1]);
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("cyrstal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    rep (i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep (i, 1, n) pre[i] = pre[i - 1] + a[i];
    int l = 1, ans = 0;
    rep (r, 1, n) {
        while (l + 1 <= r && calc(l, r) > m) l++;
        if (calc(l, r) <= m) tomax(ans, r - l + 1);
    }
    cout << ans << endl;

    return 0;
}