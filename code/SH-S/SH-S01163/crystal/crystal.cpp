#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], pre[500005], d1[500005], ok, t, t1, maxn;
int check(int l, int r) {
	int ans = 0;
	int cnt = 1;
	for (int i = l; i < r; i++) {
		ans += d1[i] * cnt;
		cnt++;
	}
	return ans;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		d1[i - 1] = a[i] - a[i - 1];
		if (d1[i - 1] <= m) ok = 1;
	}
//	cout << endl;
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + d1[i];
//		cout << pre[i] << " ";
	}
//	cout << endl;
	if (!ok) {
		cout << 1;
		return 0;
	}
	for (int i = n; i > 1; i--) {
		int cnt = 1;
		t = 1;
		while (cnt + 1 <= n && check(cnt + 1, i) <= m && i - t >= 0) {
			cnt++;
//			cout << check(cnt, i) << "|" << cnt << "," << i << " ";
//			cout << sum << endl;
			t++;
		}
//		cout << t << " " << sum - pre[cnt] << endl;
		maxn = max(t, maxn);
	}
//	cout << endl;
	cout << maxn - 1 << endl;
    return 0;
}
