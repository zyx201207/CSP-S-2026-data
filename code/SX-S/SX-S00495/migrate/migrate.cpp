#include <bits/stdc++.h>
using namespace std;
int c, t;
long long a[2000005], ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;



	for (int i = 1; i <= t; i++) {
		int n;
		long long d;
		cin >> n >> d;
		for (int j = 1; j <= n; j++)
			cin >> a[j];
		long long cnt = abs(a[2] - a[1]);
		long long mm = 2 * d - ans;
		int v = 2;
		while (abs(a[v] - a[1]) <= mm & v <= n)
			v++;
		v -= 3;
		if (v >= n - 3 || d <= cnt)
			cout << 0 << endl;
		else
			cout << n - v << endl;
		/*if (d > cnt) {
			ans = n - ((d / cnt ) - 1);
			if (ans < 0)
				cout << 0 << endl;
			else
				cout << ans << endl;
			memset(a, 0, sizeof(a));

		} else
			cout << 0 << endl;
		ans = 0;*/
	}
	return 0;
}
