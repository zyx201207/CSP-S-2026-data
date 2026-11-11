#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int n, m, a[N], s[N], mx;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i]; 
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		// cout << i << " ==> " << res << endl;
		mx = max(mx, i - res + 1);
	}
	cout << mx << endl;
}