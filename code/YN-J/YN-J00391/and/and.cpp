#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
int a[MAXN];
int ans = 0;

void dfs(int dep, int cnt, int res) {
	if (dep > n) {
		if (cnt == m) {
			ans = max(ans, res);
		}
		return;
	}
	if (cnt > m)
		return;
	dfs(dep + 1, cnt, res);
	dfs(dep + 1, cnt + 1, (res & a[dep]));
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20) {
		dfs(1, 0, 2097151);
		cout << ans;
		return 0;
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
			cout << ans;
			return 0;
		}
	}
	if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1, greater<int>());
	cout << a[m];
	return 0;
}