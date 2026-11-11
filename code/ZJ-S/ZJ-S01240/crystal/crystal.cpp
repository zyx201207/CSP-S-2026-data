#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int n, m, a[N], s[N], ans = INT_MIN;
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n, sum = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((i - mid) * a[i] - (s[i - 1] - s[mid - 1]) <= m) r = mid - 1, sum = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - sum + 1);
	}
	cout << ans;
}
signed main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}
