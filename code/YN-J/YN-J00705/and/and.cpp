#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], yhq[200005], yhh[200005];
int n, m, maxx = INT_MIN, zh = 0;

void dfs(int dep, int cnt, int sum) {
	if (dep > n) {
		if (cnt == m) {
			maxx = max(sum, maxx);
		}
		return;
	}
	if (cnt == 0) {
		dfs(dep + 1, cnt + 1, a[dep]);
	} else {
		dfs(dep + 1, cnt + 1, sum & a[dep]);
	}
	dfs(dep + 1, cnt, sum);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int cnt0 = 0;
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			yhq[1] = a[1];
		} else {
			yhq[i] = yhq[i - 1] & a[i];
		}
		if (a[i] != i - 1) {
			flag = 0;
		}
		if (a[i] == 0) {
			cnt0++;
		}
		maxx = max(a[i], maxx);
	}
	if (m == 1) {
		cout << maxx;
	} else if (m == n) {
		zh = a[1];
		for (int i = 2; i <= n; i++) {
			zh &= a[i];
		}
		cout << zh;
	} else if (m == 2) {
		maxx = INT_MIN;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int h = a[i] & a[j];
				maxx = max(maxx, h);
			}
		}
		cout << maxx;
	} else if (m == n - 1) {
		for (int i = n; i >= 1; i--) {
			if (i == n) {
				yhh[i] = a[i];
			} else {
				yhh[i] = yhh[i + 1] & a[i];
			}
		}
		int ans = INT_MIN;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				ans = max(yhh[2], ans);
			} else if (i == n) {
				ans = max(yhq[n - 1], ans);
			} else {
				int h = yhq[i - 1] & yhh[i + 1];
				ans = max(ans, h);
			}
		}
	} else {
		if (n <= 20) {
			maxx = INT_MIN;
			dfs(1, 0, 0);
			cout << maxx;
		} else {
			if (flag == 1) {
				int h = a[n];
				for (int i = n; i >= n - m + 1; i--) {
					h &= a[i];
				}
				cout << h;
			} else {
				if (n - cnt0 >= m) {
					cout << maxx;
				} else {
					cout << 0;
				}
			}
		}
	}
	return 0;
}