#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], ans, t[5];
void dfs1(int x, int cnt, int s) {
	if (n - x + cnt + 1 < m)
		return ;
	if (cnt == m) {
		ans = max(ans, s);
		return ;
	}
	if (x > n)
		return ;
	dfs1(x + 1, cnt, s);
	dfs1(x + 1, cnt + 1, s & a[x]);
}
void dfs2(int x, bool flag, int s) {
	if (x > n) {
		if (flag)
			ans = max(ans, s);
		return ;
	}
	if (!flag)
		dfs2(x + 1, true, s);
	dfs2(x + 1, flag, s & a[x]);
}
bool f(int x) {
	int ret = 1;
	while (ret < n)
		ret *= 2;
	return ret == n;
}
int quickPow(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1)
			res *= base;
		base *= base;
		power >>= 1;
	}
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20) {
		for (int i = 1; i <= n - m + 1; i++)
			dfs1(i + 1, 1, a[i]);
		cout << ans;
		return 0;
	}
	if (n <= 2000) {
		if (m == 1)
			for (int i = 1; i <= n; i++)
				ans = max(ans, a[i]);
		else if (m == n) {
			ans = a[1];
			for (int i = 2; i <= n; i++)
				ans &= a[i];
		} else
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	if (m == n - 1) {
		dfs2(2, false, a[1]);
		dfs2(3, true, a[1]);
		dfs2(3, true, a[2]);
		cout << ans;
		return 0;
	}
	if (f(n)) {
		int k = n / m;
		k = log2(k);
		k = quickPow(2, k);
		ans = n / k * (k - 1);
		cout << ans;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	if (a[n] <= 4) {
		a[n + 1] = 5;
		int u = upper_bound(a + 1, a + 1 + n, 1) - a;
		t[1] = u - 1;
		u = upper_bound(a + 1, a + 1 + n, 2) - a;
		t[2] = u - 1 - t[1];
		u = upper_bound(a + 1, a + 1 + n, 3) - a;
		t[3] = u - 1 - t[1] - t[2];
		u = upper_bound(a + 1, a + 1 + n, 4) - a;
		t[4] = u - 1 - t[1] - t[2] - t[3];
		if (t[4] >= m)
			ans = 4;
		else if (t[3] >= m)
			ans = 3;
		else if (t[2] + t[3] >= m)
			ans = 2;
		else if (t[1] + t[3] >= m)
			ans = 1;
		else
			ans = 0;
		cout << ans;
		return 0;
	}
	ans = a[n - m + 1];
	cout << ans;
	return 0;
}
