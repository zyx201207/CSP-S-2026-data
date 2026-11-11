#include <bits/stdc++.h>
#define int long long
#define ULL unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define fi first
#define se second
#define mod 998244353
#define Mod 1000000007
#define inf 1e18
using namespace std;
const int N = 2e5 + 10;
int n, d, cas;
int a[N], s[N], c[N];
void solve1() {
    for (int i = 1; i <= n - 3; i++) {
        int x1 = a[i], x2 = a[i + 1], x3 = a[i + 2], x4 = a[i + 3];
        if (x3 - x1 <= d && x4 - x2 <= d) s[i] = 1;
        s[i] += s[i - 1];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > d) c[i] = 1;
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++) cout << s[i] << " " << c[i] << '\n';
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 3; j <= n; j++) {
            if (c[j - 1] - c[i - 1] > 0) break;
            if (s[j - 3] - s[i - 1] == 1) ans++;
        }
    cout << ans << '\n';
}
void solve2() {
    int D = a[2] - a[1];
    int k = D / d;
    cout << max(0ll, n - k - 1) << '\n';
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 3) return cout << "0\n", void();
    if (n <= 5000) solve1();
    else solve2();
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> cas >> T;
    while (T--) solve();
    return 0;
}
