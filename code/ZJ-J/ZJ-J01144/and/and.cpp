#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
int pw2[N];
int ans;
void dfs(int x, int cnt, int res) {
	if (x > n) {
		if (cnt == m) {
			ans = max(res, ans);
		}
		return;
	}
	int lst = res;
	if (res == -1) res = a[x];
	else res &= a[x];
	dfs(x + 1, cnt + 1, res);
	res = lst;
	dfs(x + 1, cnt, res);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	pw2[0] = 1;
	for (int i = 1; i <= 30; ++i) {
		pw2[i] = pw2[i - 1] * 2;
	}
	for (int i = 1; i <= 30; ++i) {
		pw2[i]--;
	}
	cin >> n >> m;
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	bool f = 1;
	for (int i = 1; i <= n; ++i) {
		bool ff = 0;
		for (int j = 0; j <= 30; ++j) {
			if (a[i] == pw2[j]) ff = 1;
		}
		if (!ff) {
			f = 0;
			break;
		}
	}
	if (f) {
		sort(a + 1, a + 1 + n, greater<>());
		cout << a[m] << endl;
		return 0;
	}
	if (m == 1) {
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			mx = max(mx, a[i]);
		}
		cout << mx;
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; ++i) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	if (mx <= 4) {
		int cnt[5]{};
		for (int i = 1; i <= n; ++i) {
			cnt[a[i]]++;
		}
		if (cnt[4] >= m) {
			cout << 4;
		} else if (cnt[3] + cnt[4] >= m) {
			cout << 3;
		} else if (cnt[2] + cnt[3] + cnt[4] >= m) {
			cout << 2;
		} else if (cnt[1] + cnt[2] + cnt[3] + cnt[4]) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	dfs(1, 0, -1);
	cout << ans;
	return 0;
}