#include <bits/stdc++.h>
using namespace std;
int n, c, a[210000];

int p(int s, int e, int d) {
	int maxx = INT_MIN, minn = INT_MAX;

	for (int i = s + 1; i < e; i++) {

		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
	}

	return ((e - s) % 2 == 0 && abs(maxx - minn) <= d && abs(maxx - e) <= d && abs(minn - s) <= d ) || ((e - s) % 2 == 1
	        && abs(maxx + minn) / 2 <= d && abs(maxx - e) <= d && abs(minn - s) <= d)
	       || (maxx + minn <= 0 && (abs(e - s) % 2 == 1 && abs(maxx - minn) <= d && abs(maxx - e) <= d && abs(minn - s) <= d)
	           || ((e - s) % 2 == 0 && abs(maxx + minn) / 2 <= d
	               && abs(maxx - e) <= d && abs(minn - s) <= d) );

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> n;

	for (int i = 1; i <= n; i++) {

		int m, d;
		cin >> m >> d;

		for (int j = 1; j <= m; j++) {

			cin >> a[j];
		}

		int cnt = 0;

		for (int j = 1; j <= m - 3; j++) {

			for (int h = j + 3; h <= m; h++) {

				cnt += p(j, h, d);
			}
		}

		cout << cnt << endl;
	}

	return 0;
}