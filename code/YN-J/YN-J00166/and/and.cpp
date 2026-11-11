#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[200005];
int vis[200005];
int pw[40];
int w[40];

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int x, int b) {
	if (x == 0) {
		ans = max(ans, b);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = true;
		dfs(x - 1, b & a[i]);
		vis[i] = false;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i <= 32; i++) {
		pw[i] = pw[i - 1] * 2;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (m == 1) {
		sort(a + 1, a + 1 + n, cmp);
		cout << a[1];
		return 0;
	}

	if (m == n) {
		int k = 0x7fffffff;
		for (int i = 1; i <= n; i++) {
			k &= a[i];
		}
		cout << k;
		return 0;
	}

	if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}

	if (m == n - 1) {
		sort(a + 1, a + 1 + n);
		cout << a[1];
		return 0;
	}

	if (m <= 6) {
		dfs(m, 0x7fffffff);
		cout << ans;
		return 0;
	}

	bool s = false;
	for (int i = 0; i <= 32; i++) {
		if (pw[i] == n) {
			s = 1;
			break;
		}
	}

	if (s) {
		sort(a + 1, a + 1 + n, cmp);
		int k = 0x7fffffff;
		for (int i = 1; i <= m; i++) {
			k &= a[i];
		}
		cout << k;
		return 0;
	} else {
		for (int i = 1; i <= n; i++) {
			int k = a[i], p = 0;
			while (k) {
				if (k & 1)
					w[p]++;
				k >>= 1;
				p++;
			}
		}
		int ans = 0;
		for (int i = 0; i <= 32; i++) {
			if (w[i] >= m)
				ans += pw[i];
		}
		cout << ans;
		return 0;
	}
	return 0;
}