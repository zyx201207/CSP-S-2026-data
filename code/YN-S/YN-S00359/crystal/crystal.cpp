#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[200005];
int s[200005];
int ans = 0;

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, cnt = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((i - mid) * a[i] - (s[i - 1] - s[mid - 1]) <= m) {
				cnt = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - cnt + 1);
	}
	cout << ans;
	return 0;
}