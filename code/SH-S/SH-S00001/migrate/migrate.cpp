#include <bits/stdc++.h>
using namespace std;

int c, t, n, ans, cnt;
long long mn;
long long d;
long long a[2000005];

void dfs (int l, int r, int res) {
	if (l == r) {
		if (mn == res) cnt++;
		if (mn > res) {
			cnt = 1;
			mn = res;
		} 
		return;
	}
	if (l > r) return;
	for (int i = 1; i <= d; i++) {
		int x = lower_bound(a + 1, a + n + 1, a[l] + i) - a;
		if (a[x] != a[l] + i) continue;
		dfs(a[x], r, res + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (d == 1) {
			cout << "0\n";
			continue;
		}
		for (int len = 2; len <= n; len++) {
			for (int l = 1; l + len - 1 <= n; l++) {
				int r = l + len - 1;
				if (a[r] - a[l] + 1 <= d) continue;
				cnt = 0;
				mn = 0x3f3f3f3f3f3f;
				dfs(l, r, 0);
				if (cnt == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

