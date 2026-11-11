#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

namespace Mort1s {
    using ll = long long;
    const int N = 5e5 + 5;
    int n;
    ll m, ans;
    ll a[N], b[N];
    map<ll, int> mp;
    inline void solve() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) b[i] = a[i];
        int l = unique(a + 1, a + 1 + n) - (a + 1);
        for (int i = 1; i <= n; i++) {
            ll sum = 0, tot = mp[b[i]]--;
            int st = upper_bound(a + 1, a + 1 + l, b[i]) - (a + 1);
            if (a[st] == b[i]) st++;
            for (int j = st; j <= l; j++) {
                sum += tot * (a[j] - a[j - 1]);
                tot += mp[a[j]];
                if (sum > m) {
                    tot -= mp[a[j]];
                    ans = max(ans, tot);
                    break;
                }
            }
        }
        cout << ans;
    }
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
/*
15:17 通过所有样例，我真的过了 T1 吗。
时间复杂度应该是 O(n\sqrt(n)) 的，在 CCF 少爷机上应该能过。
15:26 警觉，这个是不是能够做到 O(n\log n)？
15:28 好像不能二分，这题应该就是 O(n\sqrt(n)) 的。
*/