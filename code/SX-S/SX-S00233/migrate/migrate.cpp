#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6+5;
int c, t, n, d, x[N], de;

void solveA() {
	return ;
}

void solveB() {
	return ;
}

void solveC() {
	return ;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		int ans = n * (n - 1) / 2;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c == 11 || c == 12) {
			de = x[2] - x[1];
			solveA();
		}
		if (c == 12 || c == 14) {
			solveB();
		}
		if (c >= 15 && c <= 18) {
			solveC();
		}
		cout << ans << endl;
	}
	return 0;
}
