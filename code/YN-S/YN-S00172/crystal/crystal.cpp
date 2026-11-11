//2026.10.31  zyb  crystal
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], s[N], ans;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, res = i;
		while (l <= r) {
			int mid = l + ((r - l) >> 1);
			if ((i - mid)*a[i] - (s[i - 1] - s[mid - 1]) <= m) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';
	return 0;
}