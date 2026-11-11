#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N];
int pre[N];

signed main () {
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1]) continue;
		int l = 1, r = i, ans = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int now = a[i] * mid - (pre[i] - pre[i - mid]);
			if (now <= m) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		res = max (res, ans);
	}
	cout << res;
	return 0;
}