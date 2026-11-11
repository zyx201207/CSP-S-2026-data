#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
template<typename T> bool chkmax(T& x, const T& y) { return x < y ? x = y, true : false; }
template<typename T> bool chkmin(T& x, const T& y) { return y < x ? x = y, true : false; }

constexpr int N = 5e5 + 5;

int n, m, ans;
int a[N], s[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n) s[i] = s[i - 1] + a[i];
    rep(i, 1, n) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        chkmax(ans, i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}