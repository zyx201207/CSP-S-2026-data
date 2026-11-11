#include <bits/stdc++.h>
using namespace std;
int c, t, ans, sum, n, d;
int a[200006];
void dfs1(int i, int j, int st) {
	int ui = i, ok = 1;
	while (a[i] + d >= a[ui]) {
		ui++;
		ok = 0;
	}
	if (a[i] + d < a[ui]) ui--;
	if (ok) return ;
	if (i >= j) {
		ans = st;
		return ;
	}
	dfs1(ui, j, st + 1);
}
void dfs2(int i, int j, int st) {
	if (a[i + 1] - a[i] > d) return ;
	for (int x = a[i + 1] - a[i]; x <= d; x++) {
		int ui = i + 1;
		while (a[i] + x <= a[ui] and ui <= j) {
			dfs2(ui, j, st + 1);
			ui++;
		}
	}
	if (i >= j) {
		if (st == ans) sum++;
		return ;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
			int as = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					ans = 0;
					sum = 0;
					if (i == j) continue;
					dfs1(i, j, 0);
					//cout << i << " " << j << " " << ans << endl;
					if (ans) dfs2(i, j, 0);
					//cout << sum << endl;
					if (sum == 2) {
						as++;
					}
				}
			}
			cout << as << endl;

	}
	return 0;
} 




