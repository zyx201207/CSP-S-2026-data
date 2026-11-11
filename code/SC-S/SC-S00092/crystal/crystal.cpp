#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll tmp = (ll)(i - mid + 1) * a[i] - (s[i] - s[mid - 1]);
            if (tmp <= m) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (pos != -1) ans = max(ans, i - pos + 1);
    }
    cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin.tie(0), cout.tie(0), cerr.tie(0) -> sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}