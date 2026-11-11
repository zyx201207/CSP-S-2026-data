#include <bits/stdc++.h>
using namespace std;
int a[100001];
int	c, t, n, d;

bool cmp(int x, int y) {
	return x > y;
}

int mj(int x, int y) {
	int m, cnt = 0, ac = 0;

	if (x <= 2)
		return 1;

	if (y >= x)
		return 1;

	for (int i = 0; i <= x; i++) {

		for (int j = x; j >= 0; j--) {

			m = a[j] - a[i];
			m = abs(m);

			if (m % y < 2 && m % y >= 1 && m / y != 0)
				cnt++;
		}
	}

	cnt /= 2;
	return cnt;
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	for (int i = 1; i <= t; i++) {

		cin >> n >> d;

		for (int j = 1; j <= n; j++) {

			cin >> a[j];
		}

		cout << mj(n, d) << endl;
	}

	return 0;

}