#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate6.in", "r", stdin);
	freopen("migrate6.out", "w", stdout);
	int  c, t;
	cin >> c >> t;
	int n;
	int x[10001];
	int d, s = 0, m = 0;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++)
			cin >> x[j];
		for (int k = 1; k <= n; k++) {
			if (k == (n - 1) || k == n) {
				if (( x[k] - x[k - 2]) <= d || (x[k] - x[k - 1]) <= d)
					m++;
			} else if ((x[k + 2] - x[k]) <= d || (x[k + 1] - x[k]) <= d)
				m++;
		}
		cout << m << endl;
	}
	return 0;
}