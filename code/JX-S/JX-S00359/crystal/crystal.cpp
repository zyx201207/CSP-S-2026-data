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
const int N = 5e5 + 10;
int n, m;
int a[N], sum[N];
int calc(int l, int r, int i) {
    return (r - l + 1) * a[i] - (sum[r] - sum[l - 1]);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && calc(l, i - 1, i) > m) l++;
        ans = max(ans, r - l + 2), r++;
    }
    cout << ans << '\n';
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
