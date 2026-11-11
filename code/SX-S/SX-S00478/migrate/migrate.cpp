#include <bits/stdc++.h>
using namespace std;
int  q, t, a[500100], b[500100], c[500100], g = 1;
int n, d;
string ss[500100];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q >> t;
	for (int w = 1; w <= t; w++) {

		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 2; i <= n; i++) {
			b[i] = a[i] - a[i - 1];
			c[i] = b[i] + c[i - 1];
		}
		if (c[n] <= d)
			cout << 0;
		else
			cout << 2;
	}

	return 0;
}
