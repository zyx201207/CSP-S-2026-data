#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
int a[2000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++)
			cin >> a[i];
		int diff = a[2] - a[1];
		int cnt = d / diff;
		for(int i = 1; i <= n; i ++) {
			int len = d * 2 / diff;
			int to = min(n, i + len);
			ans += (to - (i + cnt));
		}
		cout << ans << "\n";
	}
	return 0;
}
