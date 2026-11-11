#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N], ans, n, m, h[N];

bool check(int mid, int k) {
	int cnt = (k - mid + 1) * a[k] - (h[k] - h[mid - 1]);
	//cout << mid << " " << k << " " << cnt << " " << (cnt <= m) << '\n';
	return cnt <= m;
}

bool cmp(int a, int b) {
	return a < b;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		h[i] = h[i - 1] + a[i];
		//cerr << h[i] << " ";
	}
	//cerr << (3 * a[3] - (h[3] - h[0]));
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		int res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i))
				res = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		//cerr << res << '\n';
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}