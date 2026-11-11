#include <bits/stdc++.h>
using namespace std;
#define int long long
// log 1e12 = 40
// 5e5 - > 5e7
const int maxn = 5e5 + 15;
int n, m, a[maxn], ans = 0, ls[maxn];
int minv = 2e9, maxv = -2e9;

bool check (int mid) {
	int yy = m, tot = 0, cnt = 0;
	for (int i = 1; i < maxn; i ++)
		ls[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > mid)
			break;
		ls[++tot] = mid - a[i];
	}
	bool flag = true;
	for (int i = tot; i >= 1; i --) {
		if (yy >= ls[i]) {
			yy -= ls[i];
			cnt ++;
		} else
			flag = false;
	}
	ans = max (ans, cnt);
	return flag;
}

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		minv = min (minv, a[i]);
		maxv = max (maxv, a[i]);
	}
	sort (a + 1, a + n + 1);
	if (n <= 4000) {
		for (int i = 1; i <= n; i ++)
			check (a[i]);
		cout << ans << endl;
		return 0;
	}
	// mj
	int l = minv, r = maxv;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check (mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}