#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int n, m;
int a[MAXN], vis[MAXN], ans = 0;

void dfs(int t, int sum) {
	if (t > m) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		int p = sum;
		if (vis[i] == 0) {
			if (t == 1)
				sum = a[i];
			else
				sum = (sum & a[i]);
			vis[i] = 1;
			dfs(t + 1, sum);
			vis[i] = 0;
			sum = p;
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxm = 0, tmp = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxm = max(maxm, a[i]);
		if (i == 1)
			tmp = a[i];
		else
			tmp = tmp & a[i];
	}
	if (m == 1) {
		cout << maxm;
		return 0;
	}
	if (m == n) {
		cout << tmp;
		return 0;
	}
	if (m == 2) {
		int y = 0;
		for (int i = 1; i <= n; i++) {
			int g = a[i];
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					y = max(y, g & a[j]);
				}
			}
		}
		cout << y << endl;
		return 0;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}