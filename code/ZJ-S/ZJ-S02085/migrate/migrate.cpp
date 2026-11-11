#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2100006];
int n, d;
void solve() {
	cin >> n >> d;
	bool flag1 = true;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
		if (i != 1 && i != 2 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) flag1 = false;
	}
	if (x[1] + d >= x[n] || n == 1) {//B
		cout << "0\n";
		return;
	}
	else if (flag1 == true) {//A
		int ans = 0;
		int det = d / (x[2] - x[1]);// <= det times
		if (det == 0) {
			cout << "0\n";
			return;
		}
//		cerr << det << "\n";
		for (int v = 2; v <= n; v ++) {
			if ((v - 1) / det == 1 && (x[v] - x[1]) % d != 0) {
//				cerr << u << " " << v << "\n";	
				ans += n - v + 1;
			}
		}
		cout << ans << "\n";
	}
	else cout << "0\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t --) solve();
	return 0;
}
