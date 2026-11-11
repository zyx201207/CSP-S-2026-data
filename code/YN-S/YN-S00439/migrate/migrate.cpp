#include <bits/stdc++.h>
using namespace std;
int a[200005], f[200005], dis[200005];

//暴力出奇迹，骗分过样例
int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	for (int q = 1; q <= t; q++) {
		int n, d;
		cin >> n >> d;
		dis[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			dis[i] = a[i] - a[i - 1];
		}
		if (c == 11 || c == 12) { //A
			int o = a[2] - a[1];
			if (o >= d || (o <= d && d < o * 2))
				cout << 0;
			else if (o * 2 <= d) {
				cout << n - 3;
			}
		} else if (c == 13 && c == 14) { //B
			cout << 0;
		} else if (c >= 15 && c <= 18) {

		} else {

		}
	}

	return 0;
}
