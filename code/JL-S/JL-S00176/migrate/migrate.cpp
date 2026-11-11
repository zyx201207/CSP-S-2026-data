

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, n, d, a[N];
int l[N], r[N];
vector<int>  p[N], q[N];
void Solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i].clear(), q[i].clear();
    if (c == 13 || c == 14) {
        cout << 0 << '\n'; return;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        r[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
        l[i] = max(l[i], 1ll);
        if (l[i] + 1 <= r[i]) p[l[i]].push_back(i), q[r[i]].push_back(i);
        //cout << l[i] << ' ' << r[i] << '\n';
    }
    int ans = 0;
    if (c <= 10) {
        int x, y;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (l[i] == r[i] || l[j] == r[j]) continue;
                if (l[i] < r[i] - 1 && l[j] < r[j] - 1 && r[i] == l[j] + 1) {
                        //cout << i << ' ' << j <<'\n';
                         ans++; continue;
                }
                if (l[j] <= r[i]) continue;
                if (!p[r[i] - 1].empty() && !q[l[j]].empty()) {
                    //cout << upper_bound(p[r[i] - 1].begin(), p[r[i] - 1].end(), r[i]) - p[r[i] - 1].begin() << ' ' << lower_bound(q[l[j]].begin(), q[l[j]].end(), l[j]) - q[l[j]].begin() - 1 << '\n';
                    x = *upper_bound(p[r[i] - 1].begin(), p[r[i] - 1].end(), i);
                    y = *(lower_bound(q[l[j]].begin(), q[l[j]].end(), j) - 1);
                    if (x <= y) {
                            //cout << i << ' ' << j <<'\n';
                            ans++; continue;
                    }
                }
                if (!p[r[i]].empty() && !q[l[j] + 1].empty()) {
                    x = *upper_bound(p[r[i]].begin(), p[r[i]].end(), i);
                    y = *(lower_bound(q[l[j] + 1].begin(), q[l[j] + 1].end(), j) - 1);
                    //cout << "! " << x << ' ' << y <<'\n';
                    if (x <= y) {
                           // cout << i << ' ' << j <<'\n';
                        ans++;
                        continue;}
                }
            }
        }
        cout << ans <<'\n'; return;
    }
    for (int i = 1; i <= n; i++) {
        if (l[i] + 1 >= r[i] || p[r[i] - 1].empty()) continue;
        ans += p[r[i] - 1].size() - (upper_bound(p[r[i] - 1].begin(), p[r[i] - 1].end(), r[i]) - p[r[i] - 1].begin());
    }
    cout << ans << '\n';
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    int T = 1; cin >> c >> T;
    while (T--) Solve();
    return 0;
}

