#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, MN = INT_MIN, MX = INT_MAX;
int c, t, lj, ans, a[N];
void dfs(int l, int r, int d) {
	if (a[l] == a[r]) {
		lj++;
		return ;
	}
	if (a[l] > a[r])
		return ;
	for (int i = l + 1 ; i <= r ; i++) {
		if (a[i] - a[l] <= d)
			dfs(a[i], a[r], d);
		else if (i == r)
			return ;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1 ; i <= n ; i++)
			cin >> a[i];
		for (int i = 1 ; i <= n - 1 ; i++) {
			for (int j = i + 1 ; j <= n ; j++) {
				lj = 0;
				dfs(i, j, d);
				if (lj == 2)
					ans++;
			}
		}
		cout << ans / 2 << endl;
	}
	return 0;
}
