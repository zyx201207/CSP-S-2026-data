#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
int a[1000005];
void solve() {
	cin >> n >> d;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= d) {
			ans++;
		}
	}
	cout << ans << "\n";
}
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}